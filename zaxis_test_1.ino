#include <VarSpeedServo.h>
int S;
int az;
int ay;
int ax;
int zm=265;
int zx=402;
double z;
VarSpeedServo l1;

void setup()
{
  pinMode(A0, INPUT);
  
  l1.attach(10);
}

void loop()
{
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

}



