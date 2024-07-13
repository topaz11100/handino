//필수 모듈 불러오기
#include <Servo.h>

//서보 모터 변수 지정
Servo motor[5];

const int PIN[5] = {12, 10, 9, 6, 2};

//초기 설정
void setup() {
  for(int i=0; i<5; i+=1){
      motor[i].attach(PIN[i]);
      motor[i].write(165);
  }
}

//반복
void loop() {   
  
}