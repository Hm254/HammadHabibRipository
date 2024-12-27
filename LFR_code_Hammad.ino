int A[]
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);

}

void forward (float lspeed, float rspeed)
{
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  analogWrite(3,rspeed);
  digitalWrite(8,HIGH);
  digitalWrite(12,LOW);
  analogWrite(9,lspeed);
}

void backward(float lspeed, float rspeed)
{
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  analogWrite(3,rspeed);
  digitalWrite(8,LOW);
  digitalWrite(12,HIGH);
  analogWrite(9,lspeed);
}

void left(float lspeed, float rspeed)
{
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
  analogWrite(3,rspeed);
  digitalWrite(8,LOW);
  digitalWrite(12,HIGH);
  analogWrite(9,lspeed);
}

void right(float lspeed, float rspeed)
{
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  analogWrite(3,rspeed);
  digitalWrite(8,HIGH);
  digitalWrite(12,LOW);
  analogWrite(9,lspeed);
}
void loop() {
  // put your main code here, to run repeatedly:



















}
