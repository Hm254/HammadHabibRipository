int mass,x=0,y=0,maxSpeed_lMotor=255, maxSpeed_rMotor=233;
int cal_delay= 50;
float _A0,_A1,_A2,_A3,_A4,_A5,_A6, l_weight, r_weight;
int A[]={0, 1, 2, 3, 4, 5, 6};

void setup() {
Serial.begin(9600);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
pinMode(A4, INPUT);
pinMode(A5, INPUT);
pinMode(A6, INPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
}
void forward (float lspeed,float rspeed)
{
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
    analogWrite(5, lspeed);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
    analogWrite(6, rspeed);
}
void right (float lspeed,float rspeed)
{
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
    analogWrite(5, lspeed);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
    analogWrite(6, rspeed);
}
void left (float lspeed,float rspeed)
{
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
    analogWrite(5, lspeed);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
    analogWrite(6, rspeed);
}

void loop() {

 for(int m=0; m<7; m++){
  A[m]= analogRead(m);
   if(A[m]<450)A[m]=0;
   else A[m]=1;
  Serial.print(A[m]);
  Serial.print("   ");
 }
  Serial.print("\n");
mass= A[0]+A[1]+A[2]+A[3]+A[4]+A[5]+A[6];
            
//converting white line to black line:
while(A[0]==1 && A[6]==1 && (A[2]==0 || A[3]==0 || A[4]==0)){      
   for(int i=0;i<6;i++){
        A[i]=1-A[i];
   }
}


if(mass ==1 && A[3]==1) forward(maxSpeed_lMotor, maxSpeed_rMotor);

else if((A[0]==1 && A[1]==1 && A[2]==1) && (A[5]==0 && A[6]==0)){
  delay (cal_delay);
  right(maxSpeed_lMotor*0.6, maxSpeed_rMotor*0.6); 
}

else if((A[6]==1 && A[5]==1 && A[4]==1) && (A[1]==0 && A[0]==0)){
  delay (cal_delay);
  left(maxSpeed_lMotor*0.6, maxSpeed_rMotor*0.6); 
}

else if(A[1]==1 && A[2]==1 && A[3]==1 && A[4]==1 && A[5]==1){
  
  x=x+1;
  if(x<5){
    delay(cal_delay);
    return;           //destination cheking
  }
  else forward(0,0);           //Condition for stop
}

else if(mass==0){
  if(x==1){            //for T crossing
   
     if(mass<3 && (A[2]==1 || A[3]==1 || A[4]==1)) {
      right(maxSpeed_lMotor*0.6, maxSpeed_rMotor*0.6);   //for a cross(+)
     }
    
   y=y+1;
   if(y<4){
    delay(cal_delay);
    return;
   }
   else right(maxSpeed_lMotor*0.6, maxSpeed_rMotor*0.6); 
   }
  else           //is it a line terminal?
  {
   y=y+1;
   if(y<5){
   delay(cal_delay);
   return;
   }
   else right(maxSpeed_lMotor*0.6, maxSpeed_rMotor*0.6);  //U turn
  }
}


else
{
 
byte _position = 0b0000000;
        bitWrite(_position, 0, A[0]);
        bitWrite(_position, 1, A[1]);
        bitWrite(_position, 2, A[2]);
        bitWrite(_position, 3, A[3]);
        bitWrite(_position, 4, A[4]); 
        bitWrite(_position, 5, A[5]);
        bitWrite(_position, 6, A[6]);
  
  switch (_position){
    case 64:  //1000000
    forward(maxSpeed_lMotor*.2,  maxSpeed_rMotor);
    break;
    
    case 96: //1100000
    forward(maxSpeed_lMotor*.4,  maxSpeed_rMotor);
    break;

    case 32:  //0100000
    forward(maxSpeed_lMotor*.5,  maxSpeed_rMotor);
    break;

    case 48:  //0110000
    forward(maxSpeed_lMotor*.6,  maxSpeed_rMotor);
    break;

    case 16:  //0010000
    forward(maxSpeed_lMotor*.8,  maxSpeed_rMotor);
    break;

    case 24:  //0011000
    forward(maxSpeed_lMotor*.9,  maxSpeed_rMotor);
    break;

    case 28:  //0011100
    forward(maxSpeed_lMotor,  maxSpeed_rMotor);  // straight forward
    break;

    case 12:   //0001100
    forward(maxSpeed_lMotor,  maxSpeed_rMotor*.9);
    break;

    case 4:   //0000100
    forward(maxSpeed_lMotor,  maxSpeed_rMotor*.8);
    break;

    case 6:   //0000110
    forward(maxSpeed_lMotor,  maxSpeed_rMotor*.6);
    break;

     case 2:   //0000010
    forward(maxSpeed_lMotor,  maxSpeed_rMotor*.5);
    break;

     case 3:   //0000011
    forward(maxSpeed_lMotor,  maxSpeed_rMotor*.4);
    break;

     case 1:   //0000001
    forward(maxSpeed_lMotor,  maxSpeed_rMotor*.2);
    break;
  }
}
}
// forward:   0001000
//                    
//left zig-zag:   1000000  1100000  0100000  0110000  0010000  0011000  
// right zig_zag :0001100  0000100  0000110  0000010  0000011  0000001  
