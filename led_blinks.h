/*
* Created By Nick Maiello (aV1rus)
* February of 2013
* Arduino Connect
*/
int currentRPM = 0;
bool sBlink = true;
  
void doBlink(){
  while(sBlink){
    if(Serial.available()){//if data is available then read the data
      break;
    }else{
      analogWrite(headlightHaloWHITEPIN, BRIGHTNESS_HALOS);   // turn the LED on (BRIGHTNESS is the voltage level)
      analogWrite(headlightHaloREDPIN, LOW);    // turn the LED off by making the voltage LOW
      analogWrite(foglightHaloWHITEPIN, LOW);   // turn the LED on (BRIGHTNESS is the voltage level)
      analogWrite(foglightHaloREDPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
      delay(100);               // wait for a second
      analogWrite(headlightHaloWHITEPIN, LOW);    // turn the LED off by making the voltage LOW
      analogWrite(headlightHaloREDPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
      analogWrite(foglightHaloWHITEPIN, BRIGHTNESS_HALOS);   // turn the LED on (BRIGHTNESS is the voltage level)
      analogWrite(foglightHaloREDPIN, LOW);    // turn the LED off by making the voltage LOW
      delay(100);               // wait for a second
    }
  }
   refresh();
}
void doBlink2(){
      while(sBlink){
        if(Serial.available()){//if data is available then read the data
          break;
        }else{
          analogWrite(headlightHaloWHITEPIN, BRIGHTNESS_HALOS);   // turn the LED on (BRIGHTNESS is the voltage level)
          analogWrite(headlightHaloREDPIN, LOW);    // turn the LED off by making the voltage LOW
          delay(50);               // wait for a second
          analogWrite(headlightHaloWHITEPIN, LOW);    // turn the LED off by making the voltage LOW
          analogWrite(headlightHaloREDPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
          delay(100);               // wait for a 
          analogWrite(foglightHaloWHITEPIN, LOW);   // turn the LED on (BRIGHTNESS is the voltage level)
          analogWrite(foglightHaloREDPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
          delay(50);               // wait for a second
          analogWrite(foglightHaloWHITEPIN, BRIGHTNESS_HALOS);   // turn the LED on (BRIGHTNESS is the voltage level)
          analogWrite(foglightHaloREDPIN, LOW);    // turn the LED off by making the voltage LOW
          delay(100);               // wait for a second
        }
      }
    refresh();
}
static void doBlink3(){
      analogWrite(headlightHaloREDPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
      analogWrite(foglightHaloREDPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
      while(sBlink){
      if(Serial.available()){//if data is available then read the data
          break;
      }else{
          analogWrite(headlightHaloWHITEPIN, BRIGHTNESS_HALOS);   
          delay(40);               
          analogWrite(headlightHaloWHITEPIN, LOW);
          delay(70);          
          analogWrite(headlightHaloWHITEPIN, BRIGHTNESS_HALOS); 
          delay(40);            
          analogWrite(headlightHaloWHITEPIN, LOW);
          delay(70); 
          
          analogWrite(foglightHaloWHITEPIN, BRIGHTNESS_HALOS);   
          delay(40);               
          analogWrite(foglightHaloWHITEPIN, LOW);
          delay(70);          
          analogWrite(foglightHaloWHITEPIN, BRIGHTNESS_HALOS); 
          delay(40);            
          analogWrite(foglightHaloWHITEPIN, LOW);
          delay(70); 
    }
  }
   refresh();
}
void doBlink4(){
      analogWrite(headlightHaloWHITEPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
      analogWrite(foglightHaloWHITEPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
  while(sBlink){
    if(Serial.available()){//if data is available then read the data
      break;
    }else{
      analogWrite(headlightHaloREDPIN, BRIGHTNESS_HALOS);   
      delay(40);               
      analogWrite(headlightHaloREDPIN, LOW);
      delay(70);          
      analogWrite(headlightHaloREDPIN, BRIGHTNESS_HALOS); 
      delay(40);            
      analogWrite(headlightHaloREDPIN, LOW);
      delay(70); 
      
      analogWrite(foglightHaloREDPIN, BRIGHTNESS_HALOS);   
      delay(40);               
      analogWrite(foglightHaloREDPIN, LOW);
      delay(70);          
      analogWrite(foglightHaloREDPIN, BRIGHTNESS_HALOS); 
      delay(40);            
      analogWrite(foglightHaloREDPIN, LOW);
      delay(70); 
      
    }
  }
   refresh();
}
static void doBlink3OnlyWhite(){
      turnOFF(headlightHaloREDPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
      turnOFF(foglightHaloREDPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
      while(sBlink){
      if(Serial.available()){//if data is available then read the data
        break;
      }else{
          analogWrite(headlightHaloWHITEPIN, BRIGHTNESS_HALOS);   
          delay(40);               
          analogWrite(headlightHaloWHITEPIN, LOW);
          delay(70);          
          analogWrite(headlightHaloWHITEPIN, BRIGHTNESS_HALOS); 
          delay(40);            
          analogWrite(headlightHaloWHITEPIN, LOW);
          delay(70); 
          
          analogWrite(foglightHaloWHITEPIN, BRIGHTNESS_HALOS);   
          delay(40);               
          analogWrite(foglightHaloWHITEPIN, LOW);
          delay(70);          
          analogWrite(foglightHaloWHITEPIN, BRIGHTNESS_HALOS); 
          delay(40);            
          analogWrite(foglightHaloWHITEPIN, LOW);
          delay(70); 
    }
  }
   refresh();
}
void doBlink4OnlyRed(){
      turnOFF(headlightHaloWHITEPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
      turnOFF(foglightHaloWHITEPIN, BRIGHTNESS_HALOS);    // turn the LED off by making the voltage LOW
  while(sBlink){
    if(Serial.available()){//if data is available then read the data
        break;
    }else{
      analogWrite(headlightHaloREDPIN, BRIGHTNESS_HALOS);   
      delay(40);               
      analogWrite(headlightHaloREDPIN, LOW);
      delay(70);          
      analogWrite(headlightHaloREDPIN, BRIGHTNESS_HALOS); 
      delay(40);            
      analogWrite(headlightHaloREDPIN, LOW);
      delay(70); 
      
      analogWrite(foglightHaloREDPIN, BRIGHTNESS_HALOS);   
      delay(40);               
      analogWrite(foglightHaloREDPIN, LOW);
      delay(70);          
      analogWrite(foglightHaloREDPIN, BRIGHTNESS_HALOS); 
      delay(40);            
      analogWrite(foglightHaloREDPIN, LOW);
      delay(70); 
      
    }
  }
   refresh();
}
static void doHeartBeat(bool red){  //HEARTBEAT

  int hPin = headlightHaloWHITEPIN;
  int fPin = foglightHaloWHITEPIN;
  if(red){
    hPin = headlightHaloREDPIN;
    fPin = foglightHaloREDPIN;
  }
      analogWrite(headlightHaloWHITEPIN, LOW);    // turn the LED off by making the voltage LOW
      analogWrite(foglightHaloWHITEPIN, LOW);    // turn the LED off by making the voltage LOW
      analogWrite(headlightHaloREDPIN, LOW);    // turn the LED off by making the voltage LOW
      analogWrite(foglightHaloREDPIN, LOW);    // turn the LED off by making the voltage LOW
  while(sBlink){
    if(Serial.available()){//if data is available then read the data
        break;
    }else{
      analogWrite(hPin, (BRIGHTNESS_HALOS/4)); 
      analogWrite(fPin, (BRIGHTNESS_HALOS/4));   
      delay(100);               
      analogWrite(hPin, LOW);
      analogWrite(fPin, LOW);
      delay(100);
      analogWrite(hPin, BRIGHTNESS_HALOS);  
      analogWrite(fPin, BRIGHTNESS_HALOS);   
      delay(100);               
      analogWrite(hPin, LOW);  
      analogWrite(fPin, LOW);      
      delay(1000); 
    }
  }
   refresh();
}
static void followOBDMix(){
  //Serial1.print("0100\r");  
  delay(1000);
      allLEDOFF();
      currentRPM = vehicleRPM;
      int minRPM = 650;
      int maxRPM = 3000;
      int medRPM = ((maxRPM-minRPM)/2)+minRPM;
      int Bright = 0;
      int hHalo;
      int fHalo;
      float pRPM = 0.000000f;
      if(currentRPM <= 0) sBlink = false;
      while(sBlink){
        if(Serial.available()){//if data is available then read the data
          break;
        }else{
          getRPM();
          currentRPM = vehicleRPM;
          if(currentRPM > maxRPM) currentRPM = maxRPM;
          if(currentRPM < minRPM) currentRPM = minRPM;
          if(currentRPM<medRPM){
            Serial.print("RPMv ");
            pRPM = (float)((float)(currentRPM-minRPM)/(float)(medRPM-minRPM));
            delay(2);
            hHalo = headlightHaloREDPIN;
            fHalo = foglightHaloREDPIN;
            analogWrite(headlightHaloWHITEPIN, 0);
            analogWrite(foglightHaloWHITEPIN, 0); 
          }else{
            Serial.print("RPM^ ");
            pRPM = (float)((float)(currentRPM-medRPM)/(float)(maxRPM-medRPM));
            delay(2);
            hHalo = headlightHaloWHITEPIN;
            fHalo = foglightHaloWHITEPIN;
            analogWrite(headlightHaloREDPIN, 255);
            analogWrite(foglightHaloREDPIN, 255); 
          }
          Serial.println(currentRPM);
          delay(2);
          Bright = (int)255*pRPM;
          if(Bright >=0 && Bright <= 255){
            analogWrite(hHalo, Bright);
            analogWrite(fHalo, Bright); 
          } else if(Bright<0 && Bright>-255){
            Bright = -1*Bright;
            analogWrite(hHalo, Bright);
            analogWrite(fHalo, Bright); 
          }
        }
  }
   refresh();
   //resetOBD();
}
  static void followOBD(int hHalo, int fHalo){
    //Serial1.print("0100\r");  
  delay(1000);
      allLEDOFF();
      sBlink = true;
      currentRPM = vehicleRPM;
      int minRPM = 650;
      if(currentRPM>minRPM) minRPM = currentRPM;
      int maxRPM = 8000;
      int Bright = 0;
      float pRPM = 0.000000f;
      if(currentRPM <= 0) sBlink = false;
      while(sBlink){
        if(Serial.available()){//if data is available then read the data
          break;
        }else{
          getRPM();
          currentRPM = vehicleRPM;
          if(currentRPM > maxRPM) currentRPM = maxRPM;
          if(currentRPM < minRPM) currentRPM = minRPM;
          
            pRPM = (float)((float)(currentRPM-minRPM)/(float)(maxRPM-minRPM));
            hHalo = headlightHaloREDPIN;
            fHalo = foglightHaloREDPIN;
            analogWrite(headlightHaloWHITEPIN, 0);
            analogWrite(foglightHaloWHITEPIN, 0); 
         
          Bright = (int)255*pRPM;
          if(Bright >=0 && Bright <= 255){
            analogWrite(hHalo, Bright);
            analogWrite(fHalo, Bright); 
          } else if(Bright<0 && Bright>-255){
            Bright = -1*Bright;
            analogWrite(hHalo, Bright);
            analogWrite(fHalo, Bright); 
          }
        }
      }
      refresh();
   //resetOBD();
  }
  
void followOBDSmooth(int hHalo, int fHalo){
    //Serial1.print("0100\r");  
  delay(1000);
      allLEDOFF();
      sBlink = true;
      int minRPM = 650;
      int maxRPM = 6000;
      int Bright = 0;
      int oBright = 0;
      currentRPM = vehicleRPM;
      float pRPM = 0.000000f;
      if(currentRPM <= 0) sBlink = false;
      while(sBlink && carON){
        if(Serial.available()){//if data is available then read the data
          break;
        }else{
          getRPM();
          currentRPM = vehicleRPM;
          if(vehicleRPM = 0){
            sBlink = false;
          }else{
            if(currentRPM < minRPM) currentRPM = minRPM;
            if(currentRPM > maxRPM) currentRPM = maxRPM;
            pRPM = (float)((float)(currentRPM-minRPM)/(float)(maxRPM-minRPM));
            
            Bright = (int)255*pRPM;
            if(Bright>255)Bright = 255; //Double check that it is in the proper range
            if(Bright<0)Bright = 0;
            
            if(Bright>oBright){ 
              while(oBright < Bright){
                oBright++;
                analogWrite(hHalo, oBright);
                analogWrite(fHalo, oBright);
                }
            }else if(Bright<oBright && Bright>0){
              while(oBright > Bright){
                oBright--;
                analogWrite(hHalo, oBright);
                analogWrite(fHalo, oBright);
                }
              }
             }
          }
        }//WHILE Loop
      refresh();
   //resetOBD();
    }
