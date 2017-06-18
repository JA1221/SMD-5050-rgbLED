byte rgb[3]={3,2,4};//分別為5050的RGB +接腳
byte RGB[3]={10,10,10};//RGB數值 0~255
byte GND[3]={22,24,26};//5050 RGB -接腳

void setup()
{
  for(int i=0;i<3;i++)
  {
    pinMode(rgb[i],OUTPUT);
    pinMode(GND[i],OUTPUT);
    digitalWrite(GND[i],LOW);
    }
}

void loop()
{
  for(byte i=0;i<3;i++)
  {
    analogWrite(rgb[i],RGB[i]);
    }
    delay(10);
 } 
