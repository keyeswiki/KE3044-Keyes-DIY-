#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  //LCD的IIC通信地址是0x27,2行显示16个字符

void setup()
{
  lcd.init();                      // 初始化LCD
  lcd.init();
  // 将信息打印到LCD上
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("keyes");
  lcd.setCursor(2,1);
  lcd.print("Hello, world!");
}


void loop()
{
}
