void setup()
{
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  Serial.println("AT+CIPMUX=1");
  delay(10);
  Serial.println("AT+CIPSERVER=1,1111");
  digitalWrite(13,LOW); 
}

void loop() 
{
  // put your main code here, to run repeatedly:
 if(Serial.available())
 {
  if(Serial.find("ON"))
  {
   digitalWrite(13,HIGH);  
  }
  else
  {
   digitalWrite(13,LOW); 
  }
 }
}
