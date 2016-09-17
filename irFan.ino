

void ir_fan_Controll(int value2,int mode)
    {
      if(mode==0)
      {
        if(count<=-1)// remove over (-ve) range
        count=0;
        if(count>=50)   // remove over limit (+ve) range
        count=50;       //Max limit
        if(code4==value2)
        count=count+5;
        if(code5==value2)
        count=count-5;

        if(count<=0)
        {   // if count is lower than minimum count
       fanSpeed2 = 0;      // fan is not spinning
       digitalWrite(fan, LOW);    
       Serial.print("fan stop:"); 
        }


       if((count >= speedMin) && (count <= speedMax)) 
          { 
            // if temperature is higher than minimum temp
       fanSpeed2 = map(count, speedMin, speedMax, 32, 255); // the actual speed of fan
       fanLCD2 = map(count, speedMin, speedMax, 0, 50);  // speed of fan to display on LCD
       
       analogWrite(fan, fanSpeed2);  // spin the fan at the fanSpeed speed
       Serial.print("fan speed :"); 
      Serial.print(fanLCD2);
       Serial.println("%"); 
          
         } 
         if(count > speedMax)
        {        // if count is higher than speedMax
          digitalWrite(fan , HIGH);  // turn on fan full speed
          Serial.print("Fan speed full 100% :"); 
      
         } 
        
      Serial.print("count :"); 
      Serial.println(count); 
      Serial.print("Remote pressed button code  :"); 
      Serial.println(value2); 
        
         irrecv.resume();
      }
      else
      {
        
       fan_Controll();
      }
   
   }
      
