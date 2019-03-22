#include <LiquidCrystal.h>
LiquidCrystal LCD(//pin);
int BUZZER = //;
int LED = //;
int TASTO = //;
int check = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(LED, OUTPUT);
pinMode(BUZZER, OUTPUT);
pinMode(TASTO, INPUT);
LCD.begin(//pin);
randomSeed(analogRead(0));
}

void test(void){
digitalRead(BOTTONE);
check = 1;

  
}
void loop() {
  // put your main code here, to run repeatedly:

}
