
 
    void fan_Controll()
    
    {

      
          float reading=analogRead(temp_sensor);
          float cel=reading*(5.0/1023.0)*100;
          
          temp = cel;     // get the temperature
   if(temp < tempMin)
        {   // if temp is lower than minimum temp
       fanSpeed = 0;      // fan is not spinning
         digitalWrite(fan , LOW);      
        } 
   if((temp >= tempMin) && (temp <= tempMax)) 
          { 
            // if temperature is higher than minimum temp
       fanSpeed = map(temp, tempMin, tempMax, 32, 255); // the actual speed of fan
       fanLCD = map(temp, tempMin, tempMax, 0, 100);  // speed of fan to display on LCD
       analogWrite(fan, fanSpeed);  // spin the fan at the fanSpeed speed
          
         } 
    
      if(temp > tempMax)
        {        // if temp is higher than tempMax
          //fanSpeed = map(temp, tempMin, tempMax, 32, 255); // the actual speed of fan
          digitalWrite(fan , HIGH);  // turn on led 
           Serial.println("temp is higher than tempMax");
         } 


   
       Serial.print("TEMPRATURE=");  
       Serial.print(temp);  
       Serial.print("*C  ");  
       Serial.print("FAN SPEED=");  
       Serial.print(fanLCD);  
       Serial.print("%");  
       //delay(1000);
       Serial.println();
       
      
        
 
    
    }
