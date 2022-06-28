char income_symbol;
void front()
{
 pinMode(3,INPUT);
 pinMode(6,INPUT);
 pinMode(5,OUTPUT);
 pinMode(11,OUTPUT);
 Serial.print("F");
 int value = 0;
 while(value!=255){
  analogWrite(5,value);
  analogWrite(11,value);
  value += 10;
 }
}
void back(){
 pinMode(5,INPUT);
 pinMode(11,INPUT);
 pinMode(6,OUTPUT);
 pinMode(3,OUTPUT);
 Serial.print("F");
 int value = 0;
 while(value!=-255){
  analogWrite(5,value);
  analogWrite(11,value);
  value -= 10;
  }
}
  void stop(){
    Serial.print("S");
      Serial.println(income_symbol, 1); // печатает в консоль символ
      pinMode(3,INPUT);
      pinMode(6,INPUT);
      pinMode(5,INPUT);
      pinMode(11,INPUT);
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
  switch (income_symbol)
  {
    case 'F': // Движение вперед
    front();
    break;
    case 'B': // Движение назад
    back();
    break;
    case 'G': // Движение налево вперед
      leftfront();
      break;
    case 'S': // Стоп
      stop();
      break;
    case 'I': // Движение вперед направо
      rightfront();
      break;
    case 'H': // Движение назад налево
      leftback();
      break;
    case 'J': // Движение назад направо
      rightback();
      break;
    case 'R': // Разворот направо 
      razvorotR();
      break;
    case 'L': // Разворот налево
      razvorotL();
      break;
   }
  }
}
