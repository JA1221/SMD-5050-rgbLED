const byte rgb[3]={6,5,7};//分別為5050的RGB +接腳
const byte Button[3]={2,3,4};//設定按鈕接腳
byte RGB[3]={50,50,50};//RGB數值 0~255
//const byte GND[3]={8,9,10};//5050 RGB -接腳

long ButtonT;
byte Maximum=255;
boolean light=1;
boolean LD=1;

//==============================================================================
void setup()
{
  for(byte i=0;i<3;i++)
  {
    pinMode(rgb[i],OUTPUT);
    pinMode(Button[i],INPUT);
    }
}

//==============================================================================
void loop()
{
  //==========================亮燈程式碼==========================
  if(light==1)
  {
    if(RGB[0]==0 && RGB[1]==0 && RGB[2]==0)
    {
      for(byte i=0;i<3;i++)RGB[i]=1;
    }
    for(byte i=0;i<3;i++)analogWrite(rgb[i],RGB[i]);
  }
  else
  {
    for(byte i=0;i<3;i++)analogWrite(rgb[i],0);
  }
    //==============================按鈕程式碼=========================
    //-------2開關 調正亮度--------
    if(digitalRead(2)==HIGH)
    {
      ButtonT=millis();
      while(digitalRead(2)!=LOW)//開關未放開時無限回圈
      {
        if((millis()-ButtonT)>300)break;//按壓超過300ms跳出
      }
      if((millis()-ButtonT)<=300)//按壓秒數小於300ms:開關功能
      { 
        light=!light;                 //5050關閉
      }
      else//按壓超過300ms
      {        
        while(digitalRead(2)==HIGH)
        {                    
          if(LD==1)//-------------變亮--------------
          {
            light=1;
            for(byte i=0;i<3;i++)
            {
              if(RGB[i]<255)RGB[i]++;
            }
            for(byte i=0;i<3;i++)analogWrite(rgb[i],RGB[i]);
            delay(10);
          }
          else if(LD==0)//----------變暗--------------
          {
            light=1;
            for(byte i=0;i<3;i++)
            {
              if(RGB[i]>1)RGB[i]--;
            }
            for(byte i=0;i<3;i++)analogWrite(rgb[i],RGB[i]);
            delay(10);
          }          
        }
        LD=!LD;//上升下降模式變換
      }
    }
    //------------------3七彩正序;4七彩反序------------------
    if(digitalRead(3)==HIGH)raindow();
    else if(digitalRead(4)==HIGH)raindow2();
 } 
