#define IN1 3
#define IN2 5
#define IN3 6
#define IN4 9

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  digitalWrite(IN1, HIGH);//打开水泵1
  digitalWrite(IN2, HIGH);//打开水泵2
  digitalWrite(IN3, HIGH);//打开水泵3
  digitalWrite(IN4, HIGH);//打开水泵4
  delay(3000);            //延时3S
  digitalWrite(IN4, LOW);//关闭水泵1
  digitalWrite(IN3, LOW);//关闭水泵2
  digitalWrite(IN2, LOW);//关闭水泵3
  digitalWrite(IN1, LOW);//关闭水泵4
  delay(1000);            //延时1S
}
