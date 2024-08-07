#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //LCD的IIC通信地址是0x27,2行显示16个字符
#define soilPin1 A0
#define soilPin2 A1
#define soilPin3 A2
#define soilPin4 A3

void setup()
{
  lcd.init();                      //  初始化LCD
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}


void loop()
{
  int val1 = analogRead(soilPin1);
  int val2 = analogRead(soilPin2);
  int val3 = analogRead(soilPin3);
  int val4 = analogRead(soilPin4);
   // 将信息打印到LCD上
  lcd.setCursor(0,0);
  lcd.print("S1:");
  lcd.setCursor(3,0);
  lcd.print(val1);
  lcd.setCursor(7,0);
  lcd.print(" ");
  lcd.setCursor(9,0);
  lcd.print("S2:");
  lcd.setCursor(12,0);
  lcd.print(val2);

  lcd.setCursor(0,1);
  lcd.print("S3:");
  lcd.setCursor(3,1);
  lcd.print(val3);
  lcd.setCursor(7,1);
  lcd.print(" ");
  lcd.setCursor(9,1);
  lcd.print("S4:");
  lcd.setCursor(12,1);
  lcd.print(val4);

  delay(100);
}
