const int rmotorpin1 = 5;
const int rmotorpin2 = 6;

const int lmotorpin1 = 3;
const int lmotorpin2 = 4;
const int enA = 2;
const int enB = 7;
int count = 0;
const int frontTriggerPin = 8;
const int leftTriggerPin = 9;

const int lEchoPin = 13;
const int fEchoPin = 12;
const int turningSpeed = 240;
const int forwardSpeed = 255;
const int turningDelay = 470;
long durationLeft = 0;
long durationRight = 0;
long durationFront = 0;
long distanceLeft = 0;
long distanceRight = 0;
long distanceFront = 0;

void setup() {
//  Serial.begin(9600);
  pinMode(lmotorpin1, OUTPUT);
  pinMode(lmotorpin2, OUTPUT);
 
  pinMode(rmotorpin1, OUTPUT);
  pinMode(rmotorpin2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enA, OUTPUT);

  //ultrasonic sensor pins.
  pinMode(frontTriggerPin, OUTPUT);
  pinMode(leftTriggerPin, OUTPUT);
  pinMode(lEchoPin, INPUT);
  pinMode(fEchoPin, INPUT);
}

void loop() {
  distanceFront = getDistance("front");
 
//  Serial.println(distanceLeft);
//  Serial.println(distanceRight);
//  Serial.println(distanceFront);

  if(distanceFront > 20){
    moveForward();
  } else {
    distanceLeft = getDistance("left");
    count += 1;
    if(distanceLeft < 50){
      turnRight();
    }
    else {
      turnLeft();
    }
     
  }
  if(count == 12){
    moveForward();
    delay(200);
    stopMoving();
    exit(0);
  }
   
 
//  turnRight();
//  stopMoving();
//  exit(0);
  //delay(500);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void moveForward(){
  analogWrite(enA, forwardSpeed);
  analogWrite(enB, forwardSpeed);
  digitalWrite(rmotorpin1, HIGH);
  digitalWrite(rmotorpin2, LOW);
  digitalWrite(lmotorpin1, HIGH);
  digitalWrite(lmotorpin2, LOW);
}

void stopMoving(){
  digitalWrite(rmotorpin1, LOW);
  digitalWrite(rmotorpin2, LOW);
  digitalWrite(lmotorpin1, LOW);
  digitalWrite(lmotorpin2, LOW);
}

void turnRight(){
  analogWrite(enA, turningSpeed);
  analogWrite(enB, turningSpeed);
  digitalWrite(rmotorpin1, LOW);
  digitalWrite(rmotorpin2, HIGH);
  digitalWrite(lmotorpin1, HIGH);
  digitalWrite(lmotorpin2, LOW);
  delay(turningDelay);
}

void turnLeft(){
  analogWrite(enA, turningSpeed);
  analogWrite(enB, turningSpeed);
  digitalWrite(rmotorpin1, HIGH);
  digitalWrite(rmotorpin2, LOW);
  digitalWrite(lmotorpin1, LOW);
  digitalWrite(lmotorpin2, HIGH);
  delay(turningDelay);
}

long getDistance(String direction){
  int pin = fEchoPin;
  int triggerPin = frontTriggerPin;
  if(direction == "left"){
    pin = lEchoPin;
    triggerPin = leftTriggerPin;
  }
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(40);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(pin, HIGH);
  long distance = microsecondsToCentimeters(duration);
  return distance;
}
