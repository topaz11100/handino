#include <Parts_base.h>

Servo_vector hand{5};
int hand_pin[5] = {8, 7, 6, 5, 4};
int init_pos[5] = {165, 165, 165, 165, 165};

Strip s{';', 4};

void setup() {
  Serial.begin(9600);
  hand.attach(hand_pin);
  hand.move_arr(init_pos, 100);
}

void serial_init(){
  while (Serial.available()) Serial.read();
}

void loop() {
  int temp[5];
  String received = receive_String('/');
  if(received.length() == 0) return;
  s.decomposition(received);
  substitution(temp);
  hand.move_arr(temp, 100);
  serial_init();
}

void substitution(int temp[]){
  for(int i=0; i<5; i+=1) temp[i] = select_map( i, s[i].toInt() );
}

int select_map(int n, int x){
  if      (n == 0) return map(x, 0, 40, 0, 165);
  else if (n == 1) return map(x, 0, 70, 0, 165);
  else if (n == 2) return map(x, 0, 70, 0, 165);
  else if (n == 3) return map(x, 0, 70, 0, 165);
  else if (n == 4) return map(x, 0, 65, 0, 165);
}







