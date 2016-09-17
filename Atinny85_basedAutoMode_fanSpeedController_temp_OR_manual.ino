/* Atinny85 based small home automation system with 5 channel IRremote control with temprature controller
 * (ANY type of IRremote  buttons code canbe set easly in "conFig.h")
 * It has three function 
 *  1.IRremote based toggle switch
 *  2.IRremote based FAN Speed controller
 *  3.Temprature based FAN Speed controller
 *  where as function (2) and (3) are work at a time by AUTO_MODE_BUTTON
 *  means that by pressing AUTO_MODE_BUTTON FAN will work automatically 
 *  with LM35 temp sensor ,again pressing AUTO_MODE_BUTTON it change 
 *  the mode to MANUAL ,by pressing (+,-)FanKeys manually to change FanSpeed.
 *  Where as function (1) work freely ,on/off your electronic applience.
 *  
 *  Pin setup:-
 *  Pin A2 is used FOR INPUT, to connect LM35 sensor
 *  Pin A3 is used FOR INPUT, to connect TSOP4838 which is IR sensor
 *  Pin 1 (PWM)is used for OUTPUT ,for FAN
 *  Pin 0 is used for OUTPUT, for toggle1
 *  Pin A1 is used for OUTPUT, for toggle2
 * 
 */ 

#include "ConFig.h"      
#include <IRremote.h>  




IRrecv irrecv(RECV_PIN);
 

decode_results results;

void setup() 
{
  Serial.begin(9600);

 // fan controller  
   pinMode(fan, OUTPUT);  //fan output
 
  // ir setup
  irrecv.enableIRIn();  // Start the receiver
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
 }


void loop() 
{

ir_RemoteCall() ;

if(mode==1)
{
  fan_Controll();  
}
 
}
