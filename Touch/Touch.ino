byte GND[3]={22,24,26};
int num;
int num2;
int X=500;
byte t;
void setup()
{
  for(byte i=0;i<3;i++)
  {
    pinMode(GND[i],OUTPUT);
    digitalWrite(GND[i],LOW);
  }
  analogReference(INTERNAL2V56);
  Serial.begin(9600);
  analogWrite(2,5);
  num2=analogRead(A0);
}

void loop()
{
  analogWrite(2,5);
  delay(70);
  for(byte i=0;i<3;i++)
  {    
    num=num2;
    num2=analogRead(A0);
    if(abs(num2-num)>X)
    {
      t++;
      Serial.print("Touch ");
      Serial.println(t);
      delay(500);
      break;
    }
    delay(10);
  }




  if(Serial.available()) 
  {
    delay(10);
    byte w=Serial.available();
    String S;
    for(byte i=0;i<w;i++)
    {
      S+=Serial.read()-48;
    }
    X=S.toInt();
    Serial.println(X);
    delay(1500);
  }  
}
