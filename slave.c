#include <Servo.h>

Servo myservo;
#define Gripper_1_Pin 10
#define Servo_1_Pin 11
bool axis_1_center = true;
bool turned_right = false;
bool turned_left = false;

void setup() {
  Serial.begin(9600);
  turn_axis_1_left();
  gripper_open();
  turn_axis_1_right();
  gripper_close();
  go_home();
}

void turn_axis_1_right() {
  if (axis_1_center == true){
    myservo.attach(Servo_1_Pin);
    myservo.write(0);
    delay(600);
    myservo.detach();
    axis_1_center = false;
    turned_right = true;
  } else if (axis_1_center == false) {
    myservo.attach(Servo_1_Pin);
    myservo.write(0);
    delay(600);
    myservo.detach();

    myservo.attach(Servo_1_Pin);
    myservo.write(0);
    delay(600);
    myservo.detach();
    axis_1_center = true;
    turned_right = true;
  }
}

void turn_axis_1_left() {
  if (axis_1_center == true){
    myservo.attach(Servo_1_Pin);
    myservo.write(180);
    delay(600);
    myservo.detach();
    axis_1_center = false;
    turned_left = true;
  } else if (axis_1_center == false) {
    myservo.attach(Servo_1_Pin);
    myservo.write(180);
    delay(600);
    myservo.detach();

    myservo.attach(Servo_1_Pin);
    myservo.write(180);
    delay(600);
    myservo.detach();
    axis_1_center = true;
    turned_left = true;
  }
}

void gripper_open() {
  myservo.attach(Gripper_1_Pin);
  myservo.write(90);
  delay(1000);
  myservo.detach();
}

void gripper_close() {
  myservo.attach(Gripper_1_Pin);
  myservo.write(0);
  delay(1000);
  myservo.detach();
}

void go_home(){
  if (turned_left == true) {
    myservo.attach(Servo_1_Pin);
    myservo.write(180);
    delay(600);
    myservo.detach();
  } else if (turned_right == true) {
    myservo.attach(Servo_1_Pin);
    myservo.write(0);
    delay(600);
    myservo.detach();
  }
}

void loop() { 
}