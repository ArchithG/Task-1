int tiltPin = 4;
int forcePin = A0; //Initialising variables according to their pin numbers
int buzzerPin = 3;  
int tiltLED=5;

void setup() {
  pinMode(tiltPin, INPUT); 
  pinMode(forcePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(tiltLED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int tiltState = digitalRead(tiltPin);
  int forceVal = analogRead(forcePin);

  float forceN = map(forceVal, 0, 1023, 0, 10); // linear mapping for simplicity
  
  Serial.print("Tilt: ");
  if(tiltState==HIGH)
    Serial.print("Tilted");
  else
    Serial.print("Stable");
  Serial.print(" | Force: ");
  Serial.print(forceN);
  Serial.println(" N");

  if (forceN >= 6.0 || tiltState==HIGH) //If applied force is more than 9 or tiltstate is high buzzer buzzes on
  {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  
  if(tiltState==HIGH){ 
    digitalWrite(tiltLED,HIGH);
  }
  else{
    digitalWrite(tiltLED,LOW);
  }
  delay(200);
}
