#include <Servo.h>

Servo motor[5];

const int PIN[5] = {12, 10, 9, 6, 2};

const int speed = 1000; //마이크로초 = 0.001밀리초 = 0.000001초

void setup(){
    Serial.begin(9600);
    motor_init();
    Serial.println("Start !");
}
void motor_init(){
    for(int i=0; i<5; i+=1){
        motor[i].attach(PIN[i]);
        motor[i].write(165);
    }
    delay(5000);
}

bool same(int arr[]){
    for(int i=0; i<5; i+=1){
        if(motor[i].read() != arr[i]) return false;
    }
    return true;
}
void move_arr(int arr[], int speed){
    while(same(arr)){
        for(int i=0; i<5; i+=1){
            int temp = motor[i].read();
            if     (temp < arr[i]) motor[i].write(temp+1);
            else if(temp > arr[i]) motor[i].write(temp-1);
        }
        delayMicroseconds(speed);
    }
}
void move_one(int num, int angle, int speed){
    while(true){
        int temp = motor[num].read();
        if     (temp < angle) motor[num].write(temp+1);
        else if(temp > angle) motor[num].write(temp-1);
        else return;
        delayMicroseconds(speed);
    }
}

void rsp(int num){
    int angle[3][5] = { {0,0,0,0,0}, {0,180,180,0,0}, {180,180,180,180,180} };
    move_arr(angle[num], speed);
}
void angle_move(){
    int angle[5] = {angle_receive(), angle_receive(), angle_receive(), angle_receive(), angle_receive()};
    move_arr(angle, speed);
}

void loop(){
    char received = receive();
    if     ( received == 'r' ) rsp(0);
    else if( received == 's' ) rsp(1);
    else if( received == 'p' ) rsp(2);
    else if( received == 'a' ) angle_move();
    else if( received == 'i' ) Serial.println(angle_receive());
}

char receive(){
    if(Serial.available()) return Serial.read();
    else return '?';
}
int angle_receive(){
    String angle = "";
    while(true){
      char temp = receive();
      if      (temp == '?') continue;
      else if (temp == ';') break;
      angle += String(temp);
    }
    return angle.toInt();
}























