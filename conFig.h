/*Atinny85 Configuration*/

#define temp_sensor  A2   //temprature sensor LM35 to analog pin A0
#define RECV_PIN  A3      // the pin where you connect the output pin of TSOP4838
#define fan    1          // the pin where fan is
#define led1    0         //output pin 2
#define led2    A1        //output pin
int mode=0;               //variable to store mode

int led_toggle[] = {0,0,0,0,0};    //state of LEDs is OFF (zero)

int temp,fanSpeed,fanLCD,tempMin = 27,tempMax = 40;          //the temperature to start the fan and the maximum temperature when fan is at 100%
int count=0,fanSpeed2,fanLCD2,speedMin = 1,speedMax = 50;    //IRremot based fan speed configration

/******             SETUP YOUR ANY IR REMOTE CODE VALUE BELOW          ************/
/****** You can find IR REMOTE CODE on SERIAL MONITOR BY RUNNING this project using Arduino uno ****/
#define code1  28815       // code received from Toggle button1
#define code2  24735       // code received from Toggle button2
#define code4  -24736     // for fanButton speed +
#define code5  8160       // for fanButton speed -
#define code6  12240      //for AutoModeButton on/off









