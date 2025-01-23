//Right Motor (A)
#define AIN1 5  //Right Motor Forward
#define AIN2 4  //Right Motor Backward
#define PWMA 3  //Right Motor Speed

//Left Motor (B)
#define BIN1 6  //Left Motor Forward
#define BIN2 7  //Left Motor Backward
#define PWMB 9  //Left Motor Speed

void setup() {
  //Motor Pins are output
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
}

void loop() {
  rotate_motor(255, 255);  //forward
  delay(3000);
  rotate_motor(0, 0);  //forward
  delay(1000);
  rotate_motor(100, 100); //forward slow
  delay(3000);
  rotate_motor(-255, -255); //backward
  delay(3000);
  rotate_motor(0, 0);  //forward
  delay(1000);
}

//Operate Motor Function
void rotate_motor(int left, int right) {
  if (left > 0) {
    //left motor forward run
    digitalWrite(BIN1, 1);
    digitalWrite(BIN2, 0);
  } else {
    //left motor backward run
    left = -(left);
    digitalWrite(BIN1, 0);
    digitalWrite(BIN2, 1);
  }
  if (right > 0) {
    //right motor forward run
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 0);
  } else {
    //right motor backward run
    right = -(right);
    digitalWrite(AIN1, 0);
    digitalWrite(AIN2, 1);
  }

  //limit PWM value to 255
  if (left > 255) left = 255;
  if (right > 255) right = 255;

  //Speed
  analogWrite(PWMB, left);
  analogWrite(PWMA, right);
}