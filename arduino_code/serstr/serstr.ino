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

  //시리얼 통신 시작 9600의 속도로 통신
  Serial.begin(9600);
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

//문자열 분리 후 서보모터 전달
void copy(String teststr){
  //구분자 위치 찾기
  int one = teststr.indexOf("a");
  int two = teststr.indexOf("b");
  int three = teststr.indexOf("c");
  int four = teststr.indexOf("d");
  int five = teststr.indexOf("e");
  //구분자 위치 이용, 문자 분리 후 숫자로 변환
  String a1=teststr.substring(0,one);
  int a=a1.toInt();
  String b1=teststr.substring(one+1,two);
  int b=b1.toInt();
  String c1=teststr.substring(two+1,three);
  int c=c1.toInt();
  String d1=teststr.substring(three+1,four);
  int d=d1.toInt();
  String e1=teststr.substring(four+1,five);
  int e=e1.toInt();
  //각 서보모터에 명령 주기
  move(1,a);
  move(2,b);
  move(3,c);
  move(4,d);
  move(5,e);
}

void loop() { 
  //읽을 것이 있을 때
  while (Serial.available() > 0) {
    //문자열 단위로 읽음
    String data = Serial.readString();
    //앞뒤 공백 문자 제거
    data.trim();
    //함수 실행
    copy(data);
  }
}