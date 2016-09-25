String fromNetwork;
void setup() 
{
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() 
{
  String serverLink = "AT+CIPSTART=\"TCP\",\"";
  serverLink += "iot.buyoldenbooks.com"; 
  serverLink += "\",80";
  Serial.println(serverLink);
  delay(500);
  
   serverLink = "GET /fetch.php HTTP/1.1\r\n";
  serverLink+="Host: www.iot.buyoldenbooks.com\r\n\r\n";
  String linkLength = "AT+CIPSEND=";
  linkLength+= String(serverLink.length());
  Serial.println(linkLength);
  delay(10);
  
  Serial.print(serverLink);
  delay(10);
  
if(Serial.available()){


  if(Serial.find("LIGHT ON"))
  {
     digitalWrite(13,HIGH);
  }
  else{
     digitalWrite(13,LOW);
  }
    
}

     
    
  //delay(500);
}
