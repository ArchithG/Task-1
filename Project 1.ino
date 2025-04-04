int tempPin= A0;   
int soilPin= A1;   //Initialising pin number for variables
int ldrPin= A2;    

void setup() {
  pinMode(tempPin, INPUT);   
  pinMode(soilPin, INPUT);   
  pinMode(ldrPin, INPUT);    
  Serial.begin(9600);     
}

void loop() {
  int tempValue= analogRead(tempPin);
  float voltage= tempValue * (5.0 / 1023.0); //Converts the arduino value to voltage 

  float temp= (voltage - 0.5) * 100.0; 

  int soilVal= analogRead(soilPin);
  int soilMoisture= map(soilVal, 0, 1023, 0, 100); // mapping moisture level to percentage

  int ldrValue= analogRead(ldrPin);
  int lightIntensity= map(ldrValue, 0, 1023, 0, 80); // Mapping light intensity to percentage

  
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C | Soil Moisture: ");
  Serial.print(soilMoisture);
  Serial.print("% | Light Intensity: ");
  Serial.print(lightIntensity);
  Serial.println("%");

  delay(1000);
}
