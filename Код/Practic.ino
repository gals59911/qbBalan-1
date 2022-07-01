#include <FastLED.h>
#include <Servo.h>
// Количество светодиодов
#define NUM_LEDS 7
// Номер порта
#define LED_PIN 10
// Массив светодиодов
CRGB leds[NUM_LEDS];
char income_symbol;
// для ультразвукового дальномера
const int echoPin = 8;
const int trigPin = 7;
Servo Servo1;
int servoPin=9;
// для оптического датчика
const int prx_pin = 4;
byte v;
long duration,cm;
void back(){
 pinMode(3,INPUT);
 pinMode(6,INPUT);
 pinMode(5,OUTPUT);
 pinMode(11,OUTPUT);
 Serial.print("F");
 int value=0;
 while(value!=255){
  analogWrite(3,value);
  analogWrite(6,value);
  value+=15;
  }
}

void front(){
 pinMode(6,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(5,INPUT);
 pinMode(11,INPUT);
 Serial.print("B");
 int value = 0;
 while(value!=-255){
  analogWrite(3,value);
  analogWrite(6,value);
  value -= 15;
  }
}
void stop(){
 
  Serial.print("S");
  Serial.println(income_symbol, 1); // печатает в консоль символ
  analogWrite(3,0);
  analogWrite(6,0);
  analogWrite(5,0);
  analogWrite(11,0);
}

void rightback(){
  pinMode(6,INPUT);
  pinMode(3,INPUT);
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);
  analogWrite(5,150);
  analogWrite(11,50);
}

void leftback(){
  pinMode(3,INPUT);
  pinMode(6,INPUT);
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);
  analogWrite(5,50);
  analogWrite(11,150);
}

void leftfront(){
  pinMode(5,INPUT);
  pinMode(11,INPUT);
  pinMode(6,OUTPUT);
  pinMode(3,OUTPUT);
  analogWrite(6,-150);
  analogWrite(3,-50);
}

void rightfront(){
  pinMode(5,INPUT);
  pinMode(11,INPUT);
  pinMode(6,OUTPUT);
  pinMode(3,OUTPUT);
  analogWrite(3,-150);
  analogWrite(6,-50);
}

void razvorotR(){
  pinMode(11,INPUT);
  pinMode(5,INPUT);
  analogWrite(11,0);
  analogWrite(5,150);
}
  
void razvorotL(){
  pinMode(5,INPUT);
  pinMode(11,INPUT);
  analogWrite(5,0);
  analogWrite(11,150);
} 
 
void setup() {
  Serial.begin(19200);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(4, INPUT);
  pinMode(10, OUTPUT);
   FastLED.addLeds<WS2812,LED_PIN,GRB>(leds,NUM_LEDS).setCorrection(TypicalLEDStrip);
  // яркость светодиодов (макс значение 255) менять можно в любом месте программы
  FastLED.setBrightness(50);
  Servo1.attach(servoPin);
}

void loop(){
  // 0 градусов
  Servo1.write(90);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  cm=(duration/2)/29;
  if (cm<50){
    leds[0] = CHSV(0,0,255);
    leds[2] = CHSV(0,0,255);
    leds[1] = CHSV(0,0,255);
    leds[4] = CHSV(0,0,255);
    leds[6] = CHSV(0,0,255);
    FastLED.show();
  }
  else{leds[0] = CHSV(0,0,0);
    leds[2] = CHSV(0,0,0);
    leds[1] = CHSV(0,0,0);
    leds[4] = CHSV(0,0,0);
    leds[6] = CHSV(0,0,0);
    FastLED.show();}
  Serial.println(cm);
if (Serial.available()>0)
 {
  income_symbol = Serial.read();
  Serial.println(income_symbol);
  switch (income_symbol)
  {
    case 'F': // Движение вперед
      stop();
      front();
      break;
    case 'B': // Движение назад
      stop();
      back();
      break;
    case 'G': // Движение налево вперед
      leftfront();
      break;
    case 'S': // Стоп
      stop();
      break;
    case 'I': // Движение вперед направо
      stop();
      rightfront();
      break;
    case 'H': // Движение назад налево
      stop();
      leftback();
      break;
    case 'J': // Движение назад направо
      stop();
      rightback();
      break;
    case 'R': // Разворот направо 
      stop();
      razvorotR();
      break;
    case 'L': // Разворот налево
      stop();
      razvorotL();
      break;
   }
  }
}
