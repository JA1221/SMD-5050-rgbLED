const boolean number[10][7]=
{//a b c d e f g
  {1,1,1,1,1,1,0},//0
  {0,1,1,0,0,0,0},//1
  {1,1,0,1,1,0,1},//2
  {1,1,1,1,0,0,1},//3
  {0,1,1,0,0,1,1},//4
  {1,0,1,1,0,1,1},//5
  {1,0,1,1,1,1,1},//6
  {1,1,1,0,0,1,0},//7
  {1,1,1,1,1,1,1},//8
  {1,1,1,1,0,1,1}//9
};
void clock0()
{  
  ReadDS3231();
  if(Time[0]==second2)return;
  else
  {
    second2=Time[0];//更新
    
    if(t>second2)
    {
      if((60-t+second2)>=5)
      {
        t=second2;
        if(mode<2)mode++;
        else mode=0;
      }
    }
    else
    {
      if((second2-t)>=5)
      {        
        t=second2;
        if(mode<2)mode++;
        else mode=0;
      }
    }
    for(byte i=0;i<2;i++)
    {
      for(byte j=0;j<7;j++)
      {
        if(i==0)
        {
          if(number[Time[mode]%10][j]==1)
          {
            Display[i][j]=color[mode][0];
            Display[i][j+7]=color[mode][1];
          }
          else
          {
            Display[i][j]=0;
            Display[i][j+7]=0;
          }
        }
        else
        {
          if(number[Time[mode]/10][j]==1)
          {
            Display[i][j]=color[mode][0];
            Display[i][j+7]=color[mode][1];
          }
          else 
          {
            Display[i][j]=0;
            Display[i][j+7]=0;
          }
        }
      }
    }
  }
}

