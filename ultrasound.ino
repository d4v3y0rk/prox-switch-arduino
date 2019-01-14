// defines pins numbers
const int trigPin = D5;
const int echoPin = D6;
const int relayPin = D7;
volatile byte relayState = LOW;

// defines variables
long duration;
int distance_cm;
int distance_in;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(relayPin, OUTPUT);
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  delay(10);
}

void toggleRelay () {
  if (relayState == LOW ) {
    digitalWrite(relayPin, HIGH);
    relayState = HIGH;
  } else {
    digitalWrite(relayPin, LOW);
    relayState = LOW;
  }
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  /* Reads the echoPin, returns the sound wave 
     travel time in microseconds */
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance_in = duration*0.0135039/2;
  /* Prints the distance on the Serial Monitor */
  if (distance_in < 10) {
    Serial.print("Toggling the relay.\n");
    Serial.print("Distance: ");
    Serial.print(distance_in);
    Serial.println(" inches");
    toggleRelay();
    delay(50);
  }
  delay(1000);
  /*
  Serial.print("Distance: ");
  Serial.print(distance_in);
  Serial.println(" inches");
  */
}
