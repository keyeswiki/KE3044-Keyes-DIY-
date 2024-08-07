#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // LCD的通信地址的0x27,2行显示16个字符
#define soilPin1 A0                //定义土壤传感器引脚
#define soilPin2 A1
#define soilPin3 A2
#define soilPin4 A3
#define IN1 3                     //定义水泵引脚
#define IN2 5
#define IN3 6
#define IN4 9

int count, count_flag;

void setup()
{
  lcd.init();                      // 初始化lcd 
  lcd.init();
  //LCD清屏
  lcd.backlight();
}


void loop()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);     //设置引脚为输出
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  int val1 = analogRead(soilPin1);
  int val2 = analogRead(soilPin2);
  int val3 = analogRead(soilPin3);
  int val4 = analogRead(soilPin4);
  
  //LCD上打印数值
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
  delay(200);
  count = count + 1;
  if(count >= 50)  //10秒钟后，关闭lCD1602背光
  {
    count = 50;
    lcd.noBacklight();
  }
  if(val1 > 550){             //当土壤的湿度大于550时水泵开始抽水（实际的土壤湿度越大数值越小，数值小于550就停止抽水）
    lcd.backlight();
    count = 0;
    digitalWrite(IN1, HIGH);  //打开水泵 1
    delay(3000);              //延时3S
    digitalWrite(IN1, LOW);   //关闭水泵1
    delay(5000);              //延时5S
  }else{
    digitalWrite(IN1, LOW);
  }
  if(val2 > 550){
    lcd.backlight();
    count = 0;
    digitalWrite(IN2, HIGH);
    delay(3000);
    digitalWrite(IN2, LOW);
    delay(5000);
  }else{
    digitalWrite(IN2, LOW);
  }
  if(val3 > 550){
    lcd.backlight();
    count = 0;
    digitalWrite(IN3, HIGH);
    delay(3000);
    digitalWrite(IN3, LOW);
    delay(5000);
  }else{
    digitalWrite(IN3, LOW);
  }
  if(val4 > 550){
    lcd.backlight();
    count = 0;
    digitalWrite(IN4, HIGH);
    delay(3000);
    digitalWrite(IN4, LOW);
    delay(5000);
  }else{
    digitalWrite(IN4, LOW);
  }
}
