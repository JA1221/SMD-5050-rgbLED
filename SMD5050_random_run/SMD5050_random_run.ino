byte rgb[3]={3,2,4};//分別為5050的RGB +接腳
byte RGB[3]={10,10,10};//RGB數值 0~255
byte GND[3]={22,24,26};//5050 RGB -接腳
byte xyz[3];//random+run 暫存用
byte mode=0;//mode=0普通模式 ; mode=1 random+run ; mode=2 rainbow
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
    Serial.println("You can also enter 'random' , 'random+run' or 'rainbow'.");
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

    //_____________________  mode=0 普通模式_______________________
    if(mode==0)//普通模式
    {
      if(Serial.available()) 
    {
      delay(30);                      //等待資料輸入齊全
      String s;
      String x;
      byte w=Serial.available();       //計算字元數
      byte n=0;
      int abc[3];
      //---------------------random-------------------------
      if(w==6 ||w==10 ||w==7)                  //random 或 random+run 或rainbow
      {
        s+=Serial.peek();               //檢查用 讀取後不清除
        if(s=="114")                    //判斷是不是r開頭(r= ASCII 114)
        {
          s="";                         //清除
          for(byte i=0;i<w;i++)s+=Serial.read();
            w=0;
            if(s=="11497110100111109" )          //random
            {
              Serial.print("RGB values are ");
              randomSeed(analogRead(A15));      //亂數種子 從空腳讀入 避免重複
              for(byte j=0;j<3;j++)
              {
                RGB[j]=random(256);               //產生亂數0~255
                Serial.print(RGB[j]);
                if(j<2)Serial.print(",");
                }
                Serial.println();
              }
              //-----------------------random+run-------------------------------
              else if(s=="1149711010011110943114117110")  //random+run
              {
                Serial.println("Continuous change.");     //持續變化
                mode=1;                                   //轉為random+run模式
                for(byte i=0;i<3;i++)
                  {
                    randomSeed(analogRead(A15));
                    xyz[i]=random(256);
                    }
                }
                //----------------------------rainbow-------------------------
                else if(s=="1149710511098111119")
                {
                  Serial.println("Rainbow Mode.");
                  mode=2;
                  RGB[0]=255;
                  RGB[1]=0;
                  RGB[2]=0;
                  }
                else Serial.println("Sorry,please enter the RGB values!");
          }//-------------------------------------------------------------------
          else
          {
            s="";             //清除
            }          
        }
        //---------------------------輸入RGB數值---------------------------------
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
        else if(w==0);
        else
        {
          while(Serial.read()>=0);//清除串列緩衝埠
          Serial.println("Sorry,please enter the RGB values!");
          }
        }
      }
      //_____________________ moede=1.2 跳出______________________
      else if(mode==1 || mode==2)
      {
        if(Serial.available())
        {
          delay(10);                      //等待資料輸入齊全
          byte w=Serial.available();      //計算字串數
          String s;          
          for(byte i=0;i<w;i++)s+=Serial.read();
            if(w==4 && s=="115116111112")           //stop
            {
              mode=0;                               //關閉random+run模式
              Serial.println("Has stopped.");
              }
              else Serial.println("If you want to stop.Please enter the 'stop'.");                        
                }
          //_______________________mode=1 random+run____________________________
         //---------------------亂數產生RGB數值 & 漸進變化-------------------------
         if(mode==1)
         {
          for(byte i=0;i<3;i++)
         {
           byte S=1;
           if(xyz[i]<RGB[i])S=-S;                 //亂數比原值小就轉成負值
           if((abs(xyz[i]-RGB[i])>50))RGB[i]+=S;
           else if((abs(xyz[i]-RGB[i])>0))RGB[i]+=S;
            }
            delayMicroseconds(100);                     //延遲0.1ms   
           //----------------相同時再重新產生亂數數值-----------------
           if(xyz[0]==RGB[0] && xyz[1]==RGB[1] && xyz[2]==RGB[2])
            {
              delay(100);
              for(byte i=0;i<3;i++)
              {
              randomSeed(analogRead(A15));
              xyz[i]=random(256);
               }
             }     
          }
          //________________________rainbow________________________
          else if(mode==2)
          {
           if(RGB[0]==255 && RGB[1]<255 && RGB[2]==0)RGB[1]++;
           else if(RGB[0]>0 && RGB[1]==255 && RGB[2]==0)RGB[0]--;
           else if(RGB[0]==0 && RGB[1]==255 && RGB[2]<255)RGB[2]++;
           else if(RGB[0]==0 && RGB[1]>0 && RGB[2]==255)RGB[1]--;
           else if(RGB[0]<255 && RGB[1]==0 && RGB[2]==255)RGB[0]++;
           else if(RGB[0]==255 && RGB[1]==0 && RGB[2]>0)RGB[2]--;
           }  
        }              
 } 
