#include <LiquidCrystal.h>
LiquidCrystal LCD(2,3,4,5,6,7);
int BUZZER = 11;
int LED = 12;
int VERDE = 10;
int ROSSO = 9;
int TASTO = 13;
int tempoled;
int tempobuzzer;
int tempomedio = tempoled + tempobuzzer;
void setup() {
pinMode(LED, OUTPUT);
pinMode(BUZZER, OUTPUT);
pinMode(TASTO, INPUT);
pinMode(ROSSO,OUTPUT);
pinMode(VERDE,OUTPUT);
LCD.begin(16,2);
}

void test(void){
LCD.print("TEST RIFLESSI");
delay(2000);
LCD.clear();
LCD.print("premere il tasto");
LCD.setCursor(0,1);
LCD.print("per iniziare");
while(digitalRead (TASTO) == LOW){}
LCD.clear();
LCD.setCursor(0,0);
LCD.print("TEST CON LED");
delay(1000);
}

void led(void){
  LCD.clear();
  LCD.print("3");
  delay(1000);
  LCD.clear();
  LCD.print("2");
  delay(1000);
  LCD.clear();
  LCD.print("1");
  delay(1000);
  LCD.clear();
  int start = millis();
  digitalWrite(LED,HIGH);
  while(digitalRead (TASTO) == LOW){}
  digitalWrite(LED,LOW);
  int t = millis();
  tempoled = t-start;
  LCD.print(tempoled);
  delay(2000);
  LCD.clear();
}
void buzzer(void){
  LCD.print("TEST CON BUZZER");
  delay(1000);
  LCD.clear();
  LCD.print("3");
  delay(1000);
  LCD.clear();
  LCD.print("2");
  delay(1000);
  LCD.clear();
  LCD.print("1");
  delay(1000);
  LCD.clear();
  int startB = millis();
  tone(BUZZER,1000);
  while(digitalRead (TASTO) == LOW){}
  noTone(BUZZER);
  int tB = millis();
  tempobuzzer = tB-startB;
  LCD.print(tempobuzzer);
  delay(2000);
  LCD.clear();
}
void riflesso(void){
  if(tempomedio/2 < 200 && tempomedio/2 >150)
  {
    LCD.write("SEI PASSATO");
    LCD.setCursor(0,1);
    LCD.write(tempomedio/2);
    digitalWrite(VERDE,HIGH);
    delay(2000);
    digitalWrite(VERDE,LOW);
    LCD.clear();
  }
    if(tempomedio/2 > 200)
  {
    LCD.write("NON SEI PASSATO");
    LCD.setCursor(0,1);
    LCD.write(tempomedio/2);
    digitalWrite(ROSSO,HIGH);
    delay(2000);
    digitalWrite(ROSSO,LOW);
    LCD.clear();
  }
    if(tempomedio/2 < 150)
  {
    LCD.write("NOPE, BARATO");
    delay(2000);
    LCD.clear();
  }
  
}
void loop() {
test();
led();
buzzer();
riflesso();
}
