#include <Servo.h>

Servo a;
Servo hand[5];

void setup() {
  Serial.begin(9600);

  /*
  a.attach(10);
  a.write(180);
  */

  for(int i=0; i<5; i+=1){
    hand[i].attach(i+4);
    hand[i].attach(i+4);
  }

  //receive와 조건문 이용 가위바위보 구현
}

void loop() {
  Serial.println("aaa");
  /*
  a.attach(10);
  a.write(180);
  */
}

// 가위바위보 시키기
void rock(){
  hand[0].write( 0 );
  hand[1].write( 0 );
  hand[2].write( 0 );
  hand[3].write( 0 );
  hand[4].write( 0 );
}

//함수로 엮어서 가위바위보 시키기
void move(int arr[]){
  for(int i=0; i<5; i+=1){
    hand[0].write( arr[i] );
  }
}






















