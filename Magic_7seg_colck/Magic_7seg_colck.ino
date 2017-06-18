#include <DS3231.h>
#include <Wire.h>
DS3231 Clock;
byte Time[3];
byte second2;
bool h12,PM;
byte t;
byte mode=0;

const byte DataPin[14]={6,5,4,3,2,44,45  ,  13,12,11,10,9,8,7};
const byte Scan[2]={46,47};
const byte color[3][2]={{10,0},{0,10},{10,10}};
byte Display[2][14]=//[LED][a~g G-B]
 //   Green             Blue
 //a b c d e f g     a b c d e f g
{ {0,0,0,0,0,0,0  ,  0,0,0,0,0,0,0},//LED1
  {0,0,0,0,0,0,0  ,  0,0,0,0,0,0,0}};//LED2


void setup()
{
//  Serial.begin(9600);
  Wire.begin();
  ReadDS3231();//讀取時間
  t=Time[0];//切換hms用
  second2=Time[0];//更新用
  for(byte i=0;i<2;i++)
  {
    pinMode(Scan[i],OUTPUT);
  }
}

void loop()
{
  for(byte i=0;i<2;i++)
  {
    for(byte j=0;j<14;j++)analogWrite(DataPin[j],Display[i][j]);
    delay(1);
    digitalWrite(Scan[i],LOW);
    delay(2);
    digitalWrite(Scan[i],HIGH);
  }
  clock0();  
}



