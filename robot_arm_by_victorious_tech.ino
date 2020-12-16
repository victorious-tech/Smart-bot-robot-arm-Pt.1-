/*
this code is originally Created by Yvan / https://Brainy-Bits.com
modified by Daniel / https://www.youtube.com/channel/UCYQ0enf5LvuMoN-QAcWK4lg
download the library created by Andrew Davies: https://forum.hobbycomponents.com/viewtopic.php?f=58&t=2034
 */
#include "HCPCA9685.h" // Include the HCPCA9685 library created by Andrew Davies
#define I2CAdd 0x40 // define the address of PCA9685 module
HCPCA9685 HCPCA9685(I2CAdd); // Define Library to use I2C communication
// variable
//int RB;//this line not yet been used, this line will be used in part 2
int B;
int E;
int W;
int P;
int J;


void setup() 
{
  Serial.begin(9600);
  HCPCA9685.Init(SERVO_MODE); // Set to Servo Mode
  HCPCA9685.Sleep(false); // Wake up PCA9685 module

}

void loop()
{
  //potensio pin IN
  //  int Rotational_Base = analogRead(A0);//this line not yet been used, this line will be used in part 2
  int Base = analogRead(A1);
  int Elbow = analogRead(A2);
  int Wrist = analogRead(A3);
  int Pivot = analogRead(A6);
  int Jaw = analogRead(A7);
  //mapping
  // RB = map(Rotational_Base, 0, 1023, 10, 420);//this line not yet been used, this line will be used in part 2
  B = map(Base, 0, 1023, 415, 10);
  E = map(Elbow, 0, 1023, 10, 420);
  W = map(Wrist, 0, 1023, 10, 420);
  P = map(Pivot, 0, 1023, 10, 420);
  J = map(Jaw, 0, 1023, 131, 215);
  
  //  HCPCA9685.Servo(11, RB);//this line not yet been used this line will be used in part 2
  HCPCA9685.Servo(8 , B);//servo is in pin 8 
  HCPCA9685.Servo(7, E);//servo is in pin 7
  HCPCA9685.Servo(4, W);//servo is in pin 4
  HCPCA9685.Servo(3, P);//servo is in pin 3
  HCPCA9685.Servo(0, J);//servo is in pin 0
  delay(1);
}
