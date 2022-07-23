int Led=13;                                       //設定LED接腳為第13孔
int buttonpin=3; 
//int analogPin = 3;
//#define buttonpin 3 //設定觸摸感測器接腳為第3孔
int val;                                                //設定變量val

#include <LiquidCrystal_I2C.h> 
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27,16,2);  //設定LCD位置0x27,設定LCD大小為16*2

#include "DHT.h"
#define DHTPIN 8 
#define DHTTYPE DHT11
//#define DHTTYPE DHT22   // DHT 22 如果用的是DHT22，就用這行
//#define DHTTYPE DHT21   // DHT 21
DHT dht(DHTPIN, DHTTYPE);

#include <OneWire.h> 
#include <DallasTemperature.h> 

// Hello friends Welcome to "TECHNO-E-SOLUTION"
// Here is the code for Coffin Song

// output pin is 10, you can change it down in the void setup.
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

int melody[] = {
NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, 
NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, 
NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_F4,
NOTE_G4, 0, NOTE_G4, NOTE_D5,
NOTE_C5, 0, NOTE_AS4, 0,
NOTE_A4, 0, NOTE_A4, NOTE_A4,
NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
NOTE_G4,0, NOTE_G4, NOTE_AS5,
NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
NOTE_G4,0, NOTE_G4, NOTE_AS5,
NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
NOTE_G4, 0, NOTE_G4, NOTE_D5,
NOTE_C5, 0, NOTE_AS4, 0,
NOTE_A4, 0, NOTE_A4, NOTE_A4,
NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
NOTE_G4,0, NOTE_G4, NOTE_AS5,
NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
NOTE_G4,0, NOTE_G4, NOTE_AS5,
NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5

};

int noteDurations[] = {
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
};



void setup(){ 
  pinMode(Led,OUTPUT);                 //設定LED為输出
  pinMode( buttonpin,INPUT);           //設定感測器為输入
  Serial.begin(9600);
  
  lcd.init(); //初始化LCD 
  lcd.backlight(); //開啟背光
  lcd.print("Touch:0");
  //lcd.print("

  Serial.println("DHTxx test!");
  dht.begin();  //初始化DHT
  
}
  int sum=0;
  int count=-1;
void loop(){
  count++;

  float hum = dht.readHumidity();   //取得濕度
  float tem = dht.readTemperature();  //取得溫度C

  lcd.setCursor(0, 1);
  lcd.print("H:"); //顯示Hello, World!
  lcd.print(hum); //顯示Hello, World!
  lcd.setCursor(6, 1);
  lcd.print("%\t");

  if (count % 2) {
    lcd.setCursor(7, 1);
    lcd.print("|");

  }
  else {
    lcd.setCursor(7, 1);
    lcd.print("-");
  }


  //  lcd.setCursor(7,1);
  //  lcd.print(" ");
  lcd.setCursor(8, 1);
  lcd.print("T:"); //顯示Hello, World!
  lcd.print(tem); //顯示Hello, World!
  lcd.setCursor(14, 1);
  lcd.print("*C"); //顯示Hello, World!


  //顯示在監控視窗裡
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(tem);
  Serial.println(" *C ");


  
  
  val=digitalRead(buttonpin);            //將感測器的讀值傳给val
  if(val==HIGH){ 
    sum++;
    digitalWrite(Led,HIGH);
    //val = analogRead(analogPin);
    //analogWrite(Led,HIGH);
  Serial.println(sum);
  lcd.setCursor(0,0);
  lcd.print("Touch:"); //顯示Hello, World!
  lcd.print(sum); //顯示Hello, World!
    //Serial.println(val);
    //Serial.println("ksjgiodfjgi");
    
    delay(100);
  }
  else{ 
    digitalWrite(Led,LOW);
  }

  if(hum>=94){
          for (int thisNote = 0; thisNote < 92; thisNote++) 
      {
      
      int noteDuration = 750 / noteDurations[thisNote];
      tone(2, melody[thisNote], noteDuration);
      
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      
      noTone(2);}
  }
  

}
