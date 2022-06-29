char income_symbol;
int value=0;
void front(int value)
{
 pinMode(3,INPUT);
 pinMode(6,INPUT);
 pinMode(5,OUTPUT);
 pinMode(11,OUTPUT);
 Serial.print("F");
 while(value!=30){
  analogWrite(3,value);
  analogWrite(6,value);
  value+=25;
 }
}
void back(){
 pinMode(5,INPUT);
 pinMode(11,INPUT);
 pinMode(6,OUTPUT);
 pinMode(3,OUTPUT);
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
  void leftfront(){
    pinMode(6,INPUT);
    pinMode(3,INPUT);
    pinMode(5,OUTPUT);
    pinMode(11,OUTPUT);
  analogWrite(5,150);
  analogWrite(11,50);
}
void rightfront(){
  pinMode(3,INPUT);
  pinMode(6,INPUT);
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);
  analogWrite(5,50);
  analogWrite(11,150);
}
void leftback(){
  pinMode(5,INPUT);
  pinMode(11,INPUT);
  pinMode(6,OUTPUT);
  pinMode(3,OUTPUT);
  analogWrite(11,-150);
  analogWrite(5,-50);
}
void rightback(){
  pinMode(5,INPUT);
  pinMode(11,INPUT);
  pinMode(6,OUTPUT);
  pinMode(3,OUTPUT);
  analogWrite(5,-150);
  analogWrite(11,-50);
}
void razvorotR(){
  pinMode(3,INPUT);
  pinMode(6,INPUT);
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);
  analogWrite(5,10);
  analogWrite(11,150);}
void razvorotL(){
  pinMode(3,INPUT);
  pinMode(6,INPUT);
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);
  analogWrite(11,10);
  analogWrite(5,150);
 }   
void setup() {
  Serial.begin(19200);
}
void loop(){
while (Serial.available()>0)
 {
  income_symbol = Serial.read();
  Serial.println(income_symbol);
  switch (income_symbol)
  {
    case 'F': // Движение вперед
    stop();
    front(value);
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
    case '1':
    stop();
    int value=5;
    Serial.println(value);
    break;
   }
  }
}
