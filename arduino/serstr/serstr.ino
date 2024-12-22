#include "Servo_vector.h"
#include "IO_helper.h"

const int motor_count = 5;

Servo_vector hand{motor_count};
const int hand_pin[motor_count] = {4,5,6,7,8};
const int speed = 500;
int angle[motor_count] = {165,165,165,165,165};

Protocol p{',', motor_count};

void setup()
{
  Serial.begin(9600);
  hand.attach(hand_pin);
  hand.move_arr(angle, speed);
}

void loop()
{
  String input = receive_String('\n');
  p.strip(input);
  p.fillintarr(angle);
  hand.move_arr(angle, speed);
}