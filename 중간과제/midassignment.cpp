// C++ code
//
void setup()
{
  pinMode(5, INPUT); //Switch
  pinMode(6, OUTPUT); //LED
}
int vol, out;
int sw, number_sw = 0;
int flag = 0;
void loop()
{
  vol = analogRead(A0);
  out = map(vol,0,1023,0,255);
  
  
  if(flag == 0)
  {
    analogWrite(6, out);
    sw = digitalRead(5);
    if(sw == HIGH) {flag++; delay(100);}
  }
  else if(flag == 1)
  {
    digitalWrite(6,HIGH);
    sw = digitalRead(5);
    if(sw == HIGH) {flag--; delay(100);}
    delay(vol);
    sw = digitalRead(5);
    if(sw == HIGH) {flag--; delay(100);}
    digitalWrite(6,LOW);
    sw = digitalRead(5);
    if(sw == HIGH) {flag--; delay(100);}
    delay(vol);
    sw = digitalRead(5);
    if(sw == HIGH) {flag--; delay(100);}
  }
  
}
