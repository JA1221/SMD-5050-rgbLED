const byte DataPin[14]={6,5,4,3,2,44,45  ,  13,12,11,10,9,8,7};
const byte Scan[2]={46,47};

byte Display[2][14]=//[LED][a~g G-B]
 //   Green             Blue
 //a b c d e f g     a b c d e f g
{ {1,1,1,1,1,1,0  ,  1,1,1,1,1,1,0},//LED1
  {0,1,1,0,0,0,0  ,  0,1,1,0,0,0,0}};//LED2

void setup()
{
  for(byte i=0;i<2;i++)
  {
    pinMode(Scan[i],OUTPUT);
    digitalWrite(Scan[i],HIGH);
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
}
