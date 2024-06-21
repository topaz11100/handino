//필수 모듈 불러오기
#include<Servo.h>

//서보모터 변수 지정
Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;

//초기설정
void setup() {
  //서보모터 핀 지정
  servo_1.attach(12); 
  servo_2.attach(10);
  servo_3.attach(9);
  servo_4.attach(6);
  servo_5.attach(2); 
  delay(500);
  //완전 핀 상태로 5초 대기 -> 탄성 보존을 위해
  servo_1.write(165);
  servo_2.write(165);
  servo_3.write(165);
  servo_4.write(165);
  servo_5.write(165);
  delay(5000);
}

//손가락,각도 입력받아 움직이게 하는 함수
void move(int num, int angle){
  //최대 165까지이므로 이상을 165도로 처리
  if (angle>=165){
    angle=165;
  }
  //스위치 구문 손가락 번호 구분
  switch(num){
    //1번 손가락=엄지
    case 1:
      //서보모터에 신호 전달
      servo_1.write(angle);
      //움직일 시간을 위해 딜레이
      delay(10);
      break;
    case 2:
      servo_2.write(angle);
      delay(10);
      break;
    case 3:
      servo_3.write(angle);
      delay(10);
      break;
    case 4:
      servo_4.write(angle);
      delay(10);
      break;
    case 5:
      servo_5.write(angle);
      delay(10);
      break;
  }
}

//바위
void rock(){
  move(1,0);
  move(2,0);
  move(3,0);
  move(4,0);
  move(5,0);
}

//가위
void scissor(){
  move(1,0);
  move(2,180);
  move(3,180);
  move(4,0);
  move(5,0);
}

//보
void paper(){
  move(1,180);
  move(2,180);
  move(3,180);
  move(4,180);
  move(5,180);
}

//반복
void loop() {
  //1초간 손가락 접기
  for(int i=1;i<=5;i++){
    move(i,0);
    delay(1000);
  }
  //1초간 손가락 펴기
  for(int i=5;i>=1;i--){
    move(i,180);
    delay(1000);
  }
}