//Motor A
#define en1 7
#define in1 6
#define in2 5

//Motor B
#define en2 2
#define in3 4
#define in4 3

int lineStandard = 800;

const int trigPin = 9;
const int echoPin = 8;

const int left;
const int mid;
const int right;

long duration;
int distance;
int safetyDistance;

void setup() {

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  pinMode(left, INPUT); //left sensor
  pinMode(mid, INPUT); //middle sensor
  pinMode(right, INPUT); //right sensor
  
  pinMode(in1, OUTPUT); //Motor A
  pinMode(in2, OUTPUT); //Motor A
  pinMode(in3, OUTPUT); //Motor B
  pinMode(in4, OUTPUT); //Motor B
  pinMode(en1, OUTPUT); //Motor A enable (speed)
  pinMode(en2, OUTPUT); //Motor B enable (speed)
  
  Serial.begin(9600);
  Serial.println("IR Sensor Readings:: ");
  delay(1000);
}

void loop() {

  Serial.print(left);
  Serial.print("\t");
  Serial.print(mid);
  Serial.print("\t");
  Serial.print(right);
  Serial.println();

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  
  //**********************************************
  // safetyDistance = distance;
  //here to change the distance
  //if (safetyDistance <= 20){ 
  //digitalWrite(buzzer, LOW);
  //delay(500);
  //}
  //else{
  //digitalWrite(buzzer, HIGH);
  //delay(1000);
  //}***********************************************

  if (safetyDistance <= 20) {
    if (mid && left && right == 0) {
      analogWrite(en1, 255);
      analogWrite(en2, 255);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    } else if (mid && left && right == 1) {
      analogWrite(en1, 150);
      analogWrite(en2, 150);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    } else { //right
      analogWrite(en1, 255);
      analogWrite(en2, 255);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
  }
  delay(5); // add a delay to decrease sensitivity.
}
