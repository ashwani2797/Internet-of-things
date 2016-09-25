
String Host_name = "htc";
String password = "abcd2798";


void setup()
{
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(115200);
 Time();
 
}

void Time(){
  Serial.println("AT+CWMODE=1");
  delay(10);
  
   /*char inv = '"';
    String conn = "AT+CWJAP";
  conn += "=";
  conn += inv;
  conn += Host_name;  // Host name
  conn += inv;
  conn += ",";
  conn += inv;
  conn += password; // Password
  conn += inv;
 // conn += "\r\n\r\n";
  Serial.println(conn);
  delay(1000);*/

  
  String add = "AT+CIPSTART";
  add += "=";
  add += inv;
  add += "TCP";
  add += inv;
  add += ",";
  add += inv;
  add += "api.thingspeak.com";  // Host_server_name
  add += inv;
  add += ",";
  add += "80";
  add += "\r\n";  
  Serial.println(add);
  delay(3000);
//sendData(add, 3000, 1);  // Establishing a TCP Connection. ( AT+CIPSTART = "TCP","Host_server_name",80 )
  digitalWrite(13,LOW); 

   String rest = "AT+CIPSEND=85";
   Serial.println(rest);
   delay(10);
   String hostt = "GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=NXKG78X9JOF1A2WN";
  hostt += "\r\n";
  String response = "";
  Serial.println(hostt);
 //String Times = sendData(hostt, 2000, 1);
  delay(1000);
  
    while (Serial.available())
    {

      // The esp has data so display its output to the serial window
      char c = Serial.read(); // read the next character.
      response += c;
    }
  Serial.print(response);
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
/*
  String rest = "AT+CIPSEND=90";
  rest += "\r\n";
  Serial.println(rest);
  delay(1000);
//  sendData(rest, 2000, 0); //Number of characters to send. ( "AT+CIPSEND=90" )


  String hostt = "GET /apps/thinghttp/send_request?api_key=NXKG78X9JOF1A2WN";
  hostt += "\r\n";
  hostt += "Host:api.thingspeak.com";
  hostt += "\r\n\r\n\r\n\r\n\r\n";
  String Time = sendData(hostt, 2000, 1);
 */
}



