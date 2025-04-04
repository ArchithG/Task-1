int sensPin= A0;
int LED= 5;
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(sensPin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensval=analogRead(sensPin);
  
  float val=map(sensval, 0, 1023, 0, 40);
  
  Serial.print("Intensity : ");
  Serial.print(val);
  Serial.println("%");
  if(val<30){
    digitalWrite(LED,HIGH);
  }
  else{
    
    digitalWrite(LED,LOW);
  }
    delay(400);
  
}