#include <VarSpeedServo.h>
#include<SPIRremote.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 8, 7, 4, 2);
SPIRremote remote(9);
int IRValue;
int lmt1 = 5;
int lmt2 = 6;
int rmt1 = 11;
int rmt2 = 10; 

//Variables needed for servo control
int S; //variable to create a formulae that is used to make our servo automatic
int az; //Mapping Z axis
int ay;//Mapping Y axis
int ax; //Mapping X axis
int zm=265; //Minimum value of Z axis that has been recorded
int zx=400; // Max value of z axis that has been recorded
double z; //double-precision floating point number
VarSpeedServo l1;


void setup()
{
  //setting up display
  lcd.begin(16, 2);
  //attaching motors
  remote.begin();
  pinMode(lmt1, OUTPUT);
  pinMode(lmt2, OUTPUT);
  pinMode(rmt1, OUTPUT);
  pinMode(rmt2, OUTPUT);
  
 //attaching accelerometer
  pinMode(A0, INPUT);
  l1.attach(10);
}
void loop()
{
  //program for seat to adjust itself to make it comfortable to move in staircase.
  az = analogRead(A0);
  ay = analogRead(A1);
  ax = analogRead(A2);
  
  int za = map(az,zm,zx,-90,90);
  int xa = map(ax,zm,zx,-90,90);
  int ya = map(ay,zm,zx,-90,90);
  z= RAD_TO_DEG * (atan2(-ya, -xa)+PI);
  
  S = map(z, 255, 300, 10,50);

     l1.write(S);

       delay(1000); 

  
  delay(400);

 IRValue=remote.receive();

 if(IRValue==1)
  {
    forward();
      lcd.setCursor(0, 0);
      lcd.print("Moving            ");
      lcd.setCursor(0, 1);
      lcd.print("Forward           ");
    }
  if(IRValue==2)
{
  backward();
      lcd.setCursor(0, 0);
      lcd.print("Moving            ");
      lcd.setCursor(0, 1);
      lcd.print("Backward           ");
  }
if(IRValue==3)
  {
    left();
      lcd.setCursor(0, 0);
      lcd.print("Moving          ");
      lcd.setCursor(0, 1);
      lcd.print("left         ");

    }
if(IRValue==4)
  {
    right();
      lcd.setCursor(0, 0);
      lcd.print("Moving         ");
      lcd.setCursor(0, 1);
      lcd.print("right       ");
    }
if(IRValue==5)
  {
    stpleft();
      lcd.setCursor(0, 0);
      lcd.print("Stop          ");
      lcd.setCursor(0, 1);
      lcd.print("left          ");
    }
  if(IRValue==6)
{
  stpright();
      lcd.setCursor(0, 0);
      lcd.print("Stop        ");
      lcd.setCursor(0, 1);
      lcd.print("right         ");

  }
if(IRValue==7)
  {
    stp();
      lcd.setCursor(0, 0);
      lcd.print("Aye aye!       ");
      lcd.setCursor(0, 1);
      lcd.print("Stop!         ");

    }
}

void forward()
{
  digitalWrite(lmt1, HIGH);
  digitalWrite(lmt2, LOW);
  digitalWrite(rmt1, HIGH);
  digitalWrite(rmt2, LOW);
}
void backward()
{
  digitalWrite(lmt1, LOW);
  digitalWrite(lmt2, HIGH);
  digitalWrite(rmt1, LOW);
  digitalWrite(rmt2, HIGH);
}
void left()
{
  digitalWrite(lmt1, LOW);
  digitalWrite(lmt2, HIGH);
  digitalWrite(rmt1, HIGH);
  digitalWrite(rmt2, LOW);
}
void right()
{
  digitalWrite(lmt1, HIGH);
  digitalWrite(lmt2, LOW);
  digitalWrite(rmt1, LOW);
  digitalWrite(rmt2, HIGH);
}
void stp()
{
  digitalWrite(lmt1, LOW);
  digitalWrite(lmt2, LOW);
  digitalWrite(rmt1, LOW);
  digitalWrite(rmt2, LOW);
}
void stpleft()
{
  digitalWrite(lmt1, LOW);
  digitalWrite(lmt2, LOW);
  digitalWrite(rmt1, HIGH);
  digitalWrite(rmt2, LOW);
}
void stpright()
{
  digitalWrite(lmt1, HIGH);
  digitalWrite(lmt2, LOW);
  digitalWrite(rmt1, LOW);
  digitalWrite(rmt2, LOW);
}
