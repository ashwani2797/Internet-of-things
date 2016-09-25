
String status;
int counter = 0;
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
  //serverLink += "api.thingspeak.com"; 
  serverLink += "\",80";
  Serial.println(serverLink);
  delay(500);
  
 // serverLink = "GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=OZI0TDGIC31L9JXV\r\n";

  serverLink = "GET /fetch.php HTTP/1.1\r\n";
  serverLink+="Host: www.iot.buyoldenbooks.com\r\n\r\n";

  String linkLength = "AT+CIPSEND=";
  linkLength+= String(serverLink.length());
  Serial.println(linkLength);
  delay(10);
  
  Serial.print(serverLink);
/*  Serial.println("COUNTER>>>>>>>");
  Serial.println(counter);
  Serial.println("***************");
*/
if(Serial.available()){
  if(counter < 7){
    if(Serial.find("light on")){
         status="HIGH";
         counter=6;
    }
         counter=counter+1;
  }
  else if(counter == 7){
    if( status == "HIGH")
        digitalWrite(13,HIGH);
    else
        digitalWrite(13,LOW);
    status="LOW";
    counter=0;
  }
 
  //delay(1000);
}
} 
