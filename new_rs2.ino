
void setup() 
{
  Serial.begin(115200);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  
}

void loop() 
{
  String serverLink = "AT+CIPSTART=\"TCP\",\"";
  serverLink += "api.thingspeak.com"; 
  serverLink += "\",80";
  Serial.println(serverLink);
  delay(500);
  
  serverLink = "GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=OZI0TDGIC31L9JXV\r\n";
  String linkLength = "AT+CIPSEND=";
  linkLength+= String(serverLink.length());
  Serial.println(linkLength);
  delay(10);
  String response = "";
  Serial.print(serverLink);
  
  if(Serial.find("LIGHT ON"))
  {
    status="HIGH";
  }
  else
  {
    status="LOW";
  }
