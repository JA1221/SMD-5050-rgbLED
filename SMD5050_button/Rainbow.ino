void raindow()//七彩
{
  if(RGB[0]==Maximum && RGB[1]<Maximum && RGB[2]==0)RGB[1]++;
  else if(RGB[0]>0 && RGB[1]==Maximum && RGB[2]==0)RGB[0]--;
  else if(RGB[0]==0 && RGB[1]==Maximum && RGB[2]<Maximum)RGB[2]++;
  else if(RGB[0]==0 && RGB[1]>0 && RGB[2]==Maximum)RGB[1]--;
  else if(RGB[0]<Maximum && RGB[1]==0 && RGB[2]==Maximum)RGB[0]++;
  else if(RGB[0]==Maximum && RGB[1]==0 && RGB[2]>0)RGB[2]--;
  else
  {
    RGB[0]=Maximum;
    RGB[1]=0;
    RGB[2]=0;            
  }
  delay(500/Maximum);
}

void raindow2()
{
  if(RGB[0]==Maximum && RGB[1]==0 && RGB[2]<Maximum)RGB[2]++;
  else if(RGB[0]>0 && RGB[1]==0 && RGB[2]==Maximum)RGB[0]--;
  else if(RGB[0]==0 && RGB[1]<Maximum && RGB[2]==Maximum)RGB[1]++;
  else if(RGB[0]==0 && RGB[1]==Maximum && RGB[2]>0)RGB[2]--;
  else if(RGB[0]<Maximum && RGB[1]==Maximum && RGB[2]==0)RGB[0]++;
  else if(RGB[0]==Maximum && RGB[1]>0 && RGB[2]==0)RGB[1]--;
  else
  {
    RGB[0]=Maximum;
    RGB[1]=0;
    RGB[2]=0;            
  }
  delay(500/Maximum);
}
