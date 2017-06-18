void ReadDS3231()
{
  Time[0]=Clock.getSecond();
  Time[1]=Clock.getMinute();
  Time[2]=Clock.getHour(h12, PM);    
//  Serial.print(Time[2],DEC);
//  Serial.print(':');
//  Serial.print(Time[1],DEC);
//  Serial.print(':');
//  Serial.println(Time[0],DEC);
}
