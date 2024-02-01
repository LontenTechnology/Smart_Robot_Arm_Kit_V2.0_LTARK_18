#include <Servo.h>  // add the servo libraries
Servo myservo1;     // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;
int pos1=90, pos2=90, pos3=90, pos4=90;  // define the variable of 4 servo angle and assign the initial value( that is the boot posture angle value)
char val;
void setup()
{
  myservo1.attach(3);  // set the control pin of servo 1 to D3
  myservo2.attach(5);  // set the control pin of servo 2 to D5
  myservo3.attach(6);   // set the control pin of servo 3 to D6
  myservo4.attach(9);   // set the control pin of servo 4 to D9
  myservo1.write(pos1);  
  myservo2.write(pos2);
  myservo3.write(pos3);
  myservo4.write(pos4);
  delay(1000);
  Serial.begin(9600); //  set the baud rate to 9600
}

void loop() 
{
  while (Serial.available())
  {
    val = Serial.read();   
    Serial.print(val);         
    switch(val)   
    {
      case 'L':  T_left();  break;    // turn left
      case 'R':  T_right(); break;    //turn right 
      case 'B':  RB();  break;        // the lower arm will retracted 
      case 'F':  RF();  break;        // the lower arm will stretch out
      case 'C':  CC();  break;        //close the claw
      case 'O':  CO();  break;        //open the claw
      case 'U':  LU();  break;        //the upper arm will lift up 
      case 'D':  LD();  break;        //the upper arm will go down 
    }
  }
}   

   
//**************************************************
// turn left
void T_left()
{
  pos1=pos1+8;
  myservo1.write(pos1);
  delay(5);
  if(pos1>180)
  {
    pos1=180;
  }
}
//turn right 
void T_right()
{
  pos1=pos1-8;
  myservo1.write(pos1);
  delay(5);
  if(pos1<1)
  {
    pos1=1;
  }
}



//********************************************
// the lower arm will draw back 
void RB()
{
  pos2=pos2-8;
  myservo2.write(pos2);
  delay(5);
  if(pos2<25)
  {
    pos2=25;
  }
}
// the lower arm will  stretch out
void RF()
{
  pos2=pos2+8;
  myservo2.write(pos2);
  delay(5);
  if(pos2>180)
  {
    pos2=180;
  }
}

//********************************************
//close the claw
void CC()
{
  pos4=pos4+8;
  Serial.println(pos4);
  myservo4.write(pos4);
  delay(5);
  if(pos4<45)
   {
      pos4=45;
   } 
}
// open the claw
void CO()
{
  pos4=pos4-8;
   Serial.println(pos4);
   myservo4.write(pos4);
   delay(5);
   if(pos4>120)
  {
     pos4=120;
  }
}

//***************************************
//the upper arm will lift up  
void LU()
{
  pos3=pos3+8;
  myservo3.write(pos3);
  delay(5);
  if(pos3>150)
  {
    pos3=150;
  }
}

//the upper arm will go down  
void LD()
{
  pos3=pos3-8;
  myservo3.write(pos3);
  delay(5);
  if(pos3<1)
  {
    pos3=1;
  }
}
