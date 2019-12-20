int led1 = 2;
int led2 = 3;
const int temp = A0;
float tempc;
float vout;
int gas = 4;
int b_ir = 5;
int ir = 6;
int buzzer = 7;
int fan = 8;
int trig = 9;
int echo = 10;
int led1_stat = HIGH;
int led2_stat = HIGH;
void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(gas,INPUT);
  pinMode(b_ir,INPUT);
  pinMode(ir,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(temp,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  digitalWrite(led2,HIGH);
}

void loop() {
  digitalWrite(trig,LOW);
  delay(1000);
  digitalWrite(trig,HIGH);
  delay(1000);
  digitalWrite(trig,LOW);
  int gas_read=digitalRead(gas);
  int bir_read=digitalRead(b_ir);
  int ir_read=digitalRead(ir);
  float distance=pulseIn(echo,HIGH);
  distance=distance/58;
  Serial.println(distance);
  if(gas_read == HIGH){
    digitalWrite(buzzer,LOW);
  }
  else if(gas_read ==LOW){
    digitalWrite(buzzer,HIGH);
  }
  if(bir_read == HIGH){
      digitalWrite(led1,LOW);
      delay(5000);
      digitalWrite(led1,HIGH);
  }
  if(ir_read == HIGH){
    if(led2_stat == LOW){
      digitalWrite(led2,HIGH);
      led2_stat=HIGH;
    }
   else if(led2_stat == HIGH){
      digitalWrite(led2,LOW);
      led2_stat=LOW;
    } 
  }
  if(distance<10.0){
    digitalWrite(buzzer,HIGH);
  }
  vout=analogRead(temp);
  vout=(vout*330)/1023;
  tempc=vout;
  delay(2000);
}
