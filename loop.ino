int counter = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(11200);
}

void loop() {
  // put your main code here, to run repeatedly:
i=i+1;
Serial/.println(counter);
delay(1000);
}
