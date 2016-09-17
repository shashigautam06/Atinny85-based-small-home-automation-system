void ir_RemoteCall() 
{  
  if (irrecv.decode(&results))
  
  
  {
    unsigned int value = results.value;
    switch(value) 
    {
       case code1:
         if(led_toggle[1] == 1)
         {        // if first led is on then
            digitalWrite(led1, LOW);   // turn it off when button is pressed
             Serial.print("button is pressed led1 off");  
            led_toggle[1] = 0;           // and set its state as off
         } 
         else 
         {                      // else if first led is off
             digitalWrite(led1, HIGH); // turn it on when the button is pressed
              Serial.print("button is pressed led1 on");  
             led_toggle[1] = 1;          // and set its state as on
         }
          break; 
       case code2:
         if(led_toggle[2] == 1)
         {
            digitalWrite(led2, LOW);
             Serial.print("button is pressed led2 off");  
            led_toggle[2] = 0;
         } 
         else
         {
             digitalWrite(led2, HIGH);
             Serial.print("button is pressed led2 on"); 
             led_toggle[2] = 1;
         }
          break;
       
         break;
         case code6://code6 used for two Auto mode call ON/OFF
         if(led_toggle[3] == 1)
         {
             
            mode=0;// Auto mode off ,it is manual means irRemote based FAN speed control
              
            Serial.println("Auto mode off"); 
            led_toggle[3] = 0;
         }
         else 
         {
          mode=1;//Auto mode mode on , it is temprature based FAN speed control
             
             Serial.println("Auto mode on"); 
            led_toggle[3] = 1;
         }
          break;          
    }
    Serial.print("  Remote button  code :");
      Serial.println(value);  //print remote code
    irrecv.resume(); // Receive the next value
    ir_fan_Controll(value,mode);//call with parameter ir remote fan speed function
     
  }
}
