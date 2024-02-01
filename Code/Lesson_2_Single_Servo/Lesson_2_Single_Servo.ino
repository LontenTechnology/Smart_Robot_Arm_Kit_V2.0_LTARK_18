#include <Servo.h>
Servo myservo;// create servo object to control a servo
int i=90;
void setup()
{
  Serial.begin(9600); 
  myservo.attach(5);    // set the control pin of servo 2 to 5 digital I/0 // modify each pin to adjust 
  myservo.write(90);
  delay(1000);
}

void loop() 
{
  for(i;i<180;i++)
  {
    myservo.write(i);
    delay(5);
  }
  delay(1000);
  for(i;i>0;i--)
  {
    myservo.write(i);
    delay(5);
  }
  delay(1000);
}
