//Motor A
#define ENA 6
#define IN1 7
#define IN2 8

//Motor B
#define IN3 9
#define IN4 10
#define ENB 11

#define Speed 100

void setup() {
  //Sensor pins
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  //Motor A
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  //Motor B
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}
void loop() {
  bool SOne = digitalRead(2);
  bool STwo = digitalRead(3);
  bool SThree = digitalRead(4);
  bool SFour = digitalRead(5);

  if (SOne == 0 && STwo == 1 && SThree == 1  ) {
    forward();
  } else if (SOne == 1 && STwo == 1 && SThree == 1) {
    stopAll();
  } else if (SOne == 0 && STwo == 0 && SThree == 0) {
    stopAll();
  }  else if (SOne == 1 && STwo == 1 && SThree == 0) {
    turnLeft();
  } else if (SOne == 0 && STwo == 0 && SThree == 1) {
    turnRight();
  }
}

void forward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void turnRight() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void turnLeft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopAll() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
