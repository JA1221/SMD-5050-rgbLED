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
    Serial.begin(9600);
    Serial.println("Please enter the RGB values.");
    Serial.println("Value between 0~255.  Ex:0,100,255");
    Serial.println("You can also enter 'random'");
}

void loop()
{
  //==========================亮燈程式碼==========================
  for(byte i=0;i<3;i++)
  {
    analogWrite(rgb[i],RGB[i]);
    }
    delay(10);
    //======================Serial Monitor=========================

      if(Serial.available()) 
    {
      delay(30);               //等待資料輸入齊全
      String s;
      String x;
      byte w=Serial.available(); //計算字元數
      byte n=0;
      int abc[3];
      if(w==6)//random 6位數
      {
        s+=Serial.peek();//檢查用 讀取後不清除
        if(s=="114")//判斷是不是r開頭(r= ASCII 114)
        {
          s="";//清除
          for(byte i=0;i<w;i++)
          {
            s+=Serial.read();
            }
            if(s=="11497110100111109" )//random
            {
              Serial.print("RGB values are ");
              randomSeed(analogRead(A15));//亂數種子 從空腳讀入 避免重複
              for(byte j=0;j<3;j++)
              {
                RGB[j]=random(256);//產生亂數0~255   
                Serial.print(RGB[j]);
                if(j<2)
                Serial.print(",");
                }
                Serial.println();
              }
              else Serial.println("Sorry,please enter the RGB values!");
          }
          else
          {
             s="";//清除
            }
        }
      if(w<=11 && w>=5)
      {
       for(byte i=0;i<w;i++)
       {
         char c=Serial.read();
         if(c<='9' && c>='0')
         {
           s+=c;//顯示用
           x+=c;
          }
           else if(c==',')
           {
            s+=',';
            abc[n]=x.toInt();
            n++;
            x="";
            } 
         }
         if(n==2) 
         {
          abc[2]=x.toInt();
          if(abc[0]<256 && abc[1]<256 && abc[2]<256)
          {
            for(byte i=0;i<3;i++)
          {
            RGB[i]=abc[i];
            }
            Serial.print("RGB values are ");
            Serial.println(s);
           }
           else Serial.println("Sorry,please enter the RGB values!");
          }
          else Serial.println("Sorry,please enter the RGB values!");
        }
        else 
        {
          while(Serial.read()>=0);//清除串列緩衝埠
          Serial.println("Sorry,please enter the RGB values!");
          }
        }
 } 
