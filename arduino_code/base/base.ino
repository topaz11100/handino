//필수 모듈 불러오기
#include<Servo.h>

//서보 모터 변수 지정
Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;

//초기 설정
void setup() {
  //서보모터 핀 지정
  servo_1.attach(12); 
  servo_2.attach(10);
  servo_3.attach(9);
  servo_4.attach(6);
  servo_5.attach(2); 
  delay(500);
  //완전히 핀 상태로 5초 유지 -> 탄성보존을 위함
  servo_1.write(165);
  servo_2.write(165);
  servo_3.write(165);
  servo_4.write(165);
  servo_5.write(165);
  delay(5000);
}

//반복
void loop() {   
  
}