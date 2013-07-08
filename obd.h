/*
* Created By Nick Maiello (aV1rus)
* February of 2013
* Arduino Connect
*/
char rxData[20];
char rxIndex=0;
boolean carON = false;
int vehicleRPM = 0;
int vehicleRunTime = 0;
int vehicleSpeed = 0;



void onStart(){ //Startup Process
    
  } //Startup END

void getResponse(void){
  char inChar=0;
  int missed = 0;
  //Keep reading characters until we get a carriage return
  while(inChar != '\r'){
    //If a character comes in on the serial port, we need to act on it.
    if(Serial1.available() > 0){
      //Start by checking if we've received the end of message character ('\r').
      if(Serial1.peek() == '\r'){
        //Clear the Serial buffer
        inChar=Serial1.read();
        //Put the end of string character on our data string
        rxData[rxIndex]='\0';
        //Reset the buffer index so that the next character goes back at the beginning of the string.
        rxIndex=0;
      }
      //If we didn't get the end of message character, just add the new character to the string.
      else{
        //Get the new character from the Serial port.
        inChar = Serial1.read();
        //Add the new character to the string, and increment the index variable.
        rxData[rxIndex++]=inChar;
      }
    }else{
      missed++;
      if(missed>500){
        if(rxData[0] == 'S' && rxData[1] == 'E' && rxData[2] == 'A' && rxData[3] == 'R' && rxData[4] == 'C' && rxData[5] == 'H' && rxData[6] == 'I' && rxData[7] == 'N'){
          inChar='\r';
        }else if(rxData[0] == 'S' && rxData[1] == 'T' && rxData[2] == 'O' && rxData[3] == 'P' && rxData[4] == 'P' && rxData[5] == 'E' && rxData[6] == 'D'){
          inChar='\r';
        }else{
            inChar='\r';
            rxData[0] = 'E';
            rxData[1] = 'L';
            rxData[2] = 'M';
        }
      }
    }
    delay(3);
  }
   //Serial.println(rxData);     
}
void getResponseFAST(void){
  char inChar=0;
  //Serial.println("Checking");
  //Keep reading characters until we get a carriage return
  while(inChar != '\r'){
    //If a character comes in on the serial port, we need to act on it.
    if(Serial1.available() > 0){
      //Start by checking if we've received the end of message character ('\r').
      if(Serial1.peek() == '\r'){
        //Clear the Serial buffer
        inChar=Serial1.read();
        //Put the end of string character on our data string
        rxData[rxIndex]='\0';
        //Reset the buffer index so that the next character goes back at the beginning of the string.
        rxIndex=0;
      }
      //If we didn't get the end of message character, just add the new character to the string.
      else{
        //Get the new character from the Serial port.
        inChar = Serial1.read();
        //Add the new character to the string, and increment the index variable.
        rxData[rxIndex++]=inChar;
      }
    }
    delay(5);
  }
}
void onCarTurnedOn(){
  Serial.println("ON");
  carON = true;
    allLEDOFFFADE();
    HeadHalosRedOn = false;
    FogHalosRedOn = false;
    HeadHalosWhiteOn = true;
    FogHalosWhiteOn = true;
    
      int bright = 0;
      int bright2 = 0;
      int i = 0;
      while(bright<=255){
        analogWrite(headlightHaloREDPIN, bright); 
        analogWrite(foglightHaloREDPIN, bright);   
        bright++;
        delay(5); 
      } 
        bright = 255;
      while(bright2<255){
        if(bright>=0){
            analogWrite(headlightHaloREDPIN, bright); 
            analogWrite(foglightHaloREDPIN, bright);   
            bright--;
        }
        if(bright2<255 && bright< 30){
          analogWrite(headlightHaloWHITEPIN, bright2); 
          analogWrite(foglightHaloWHITEPIN, bright2);   
          bright2++;
        }
        delay(5); 
      }
      refresh();
  Serial1.flush();
  //setupOBD();
}
void onCarTurnedOff(){
    Serial.println("OFF");
    carON = false;  
    vehicleRPM = 0;
    //Store state of old settings
    BRIGHTNESS_HALOS2 = BRIGHTNESS_HALOS;
    BRIGHTNESS_INTERIOR2 = BRIGHTNESS_INTERIOR;
    BRIGHTNESS_FOGS2 = BRIGHTNESS_FOGS;
    HeadHalosRedOn2 = HeadHalosRedOn;
    FogHalosRedOn2 = FogHalosRedOn;
    HeadHalosWhiteOn2 = HeadHalosWhiteOn;
    FogHalosWhiteOn2 = FogHalosWhiteOn;
    InteriorOn2 = InteriorOn;
    FogsOn2 = FogsOn;
    
    allLEDOFFFADE(); //Make all lights off
    allBool(false); //Make all lights off
    
    turnON(headlightHaloREDPIN, BRIGHTNESS_HALOS);  //Turn On
    turnON(foglightHaloREDPIN, BRIGHTNESS_HALOS);  //Turn On
    delay(10);
    turnOFF(headlightHaloREDPIN, BRIGHTNESS_HALOS); //turn off
    turnOFF(foglightHaloREDPIN, BRIGHTNESS_HALOS);  //Turn On
    
    
    checkForChange(); //Update user new values
}

void setZeroRPM(){
   rxData[0] = '4';
   rxData[1] = '1';
   rxData[2] = ' ';
   rxData[3] = '0';
   rxData[4] = 'C';
   rxData[5] = ' ';
   rxData[6] = '0';
   rxData[7] = '0';
   rxData[8] = ' ';
   rxData[9] = '0';
   rxData[10] = '0';
}
void getRPM(){
  while(Serial1.available()>0) Serial1.read(); //Clear Serial buffer
  delay(10);
  Serial1.print("010C\r");
  delay(80);
  int wait = 0;
  while(Serial1.available() == 0 && wait < 5000){ wait++; delay(1);}
  //Get the response from the OBD-II-UART board
  getResponse();
    //Serial.println("Send 1");
  
  getResponse();
    //Serial.println("Send 2");
    
    //Serial.println("Getting");
  if(rxData[0] == '4' && rxData[1] == '1' && rxData[3] == '0' && rxData[4] == 'C'){
    vehicleRPM = ((strtol(&rxData[6],0,16)*256)+strtol(&rxData[9],0,16))/4;
    //Print the rpm data to debug serial window
    Serial.print("RPM:");
    Serial.println(vehicleRPM);
  }else if(rxData[0] == 'E' && rxData[1] == 'L' && rxData[2] == 'M' && rxData[3] != '3' && rxData[4] != '2' && rxData[5] != '7'){ onCarTurnedOff(); }
  
  
  while(Serial1.available()>0) Serial1.read(); //Clear Serial buffer
}
void getRunTime(){
  Serial.flush();
  delay(10);
  Serial1.print("011f\r");
  delay(20);
  //Get the response from the OBD-II-UART board
  do{
    getResponse();
  }while(rxData[0] == 'S' && rxData[1] == 'E' && rxData[2] == 'A' && rxData[3] == 'R' && rxData[4] == 'C' && rxData[5] == 'H' && rxData[6] == 'I' && rxData[7] == 'N' && Serial.available() == 0);
         //Serial.println("Called");
  getResponse();
         //Serial.println("Called");
  if(rxData[0] == '4' && rxData[1] == '1' && rxData[3] == '1' && rxData[4] == 'F'){
    vehicleRunTime = ((strtol(&rxData[6],0,16)*256)+strtol(&rxData[9],0,16))/4;
    //Print the rpm data to debug serial window
    Serial.print("RunTime: ");
    Serial.println(vehicleRunTime);
  }else if(rxData[0] == 'E' && rxData[1] == 'L' && rxData[2] == 'M' && rxData[3] != '3' && rxData[4] != '2' && rxData[5] != '7'){ onCarTurnedOff(); }
} 
 int updateVehicleSpeed(){
  //Delete any data that may be in the serial port before we begin.  
  Serial.flush();
  delay(30);
  //Query the OBD-II-UART for the Vehicle Speed
  Serial1.println("010D\r");
  delay(20);
  //Get the response from the OBD-II-UART board
  do{
    getResponse();
  }while(rxData[0] == 'S' && rxData[1] == 'E' && rxData[2] == 'A' && rxData[3] == 'R' && rxData[4] == 'C' && rxData[5] == 'H' && rxData[6] == 'I' && rxData[7] == 'N' && Serial.available() == 0);
         //Serial.println("Called");
  getResponse();
         //Serial.println("Called");
  if(rxData[0] == '4' && rxData[1] == '1' && rxData[3] == '0' && rxData[4] == 'D'){
    vehicleSpeed = ((strtol(&rxData[6],0,16)*256)+strtol(&rxData[9],0,16))/4;
    //Print the rpm data to debug serial window
    Serial.print("Speed:");
    Serial.println(vehicleSpeed);
  }else if(rxData[0] == 'E' && rxData[1] == 'L' && rxData[2] == 'M'){ onCarTurnedOff(); }
}


//FAST


void getRPMFast(){
  Serial1.println("010c\r");
  delay(20);
  //Get the response from the OBD-II-UART board
  getResponseFAST();
  getResponseFAST();
         //Serial.println("Called");
  if(rxData[0] == '4' && rxData[1] == '1' && rxData[3] == '0' && rxData[4] == 'C'){
    int newRPM = ((strtol(&rxData[6],0,16)*256)+strtol(&rxData[9],0,16))/4;
    if(newRPM >= 0 && newRPM <7000) 
    vehicleRPM = newRPM;
    //Print the rpm data to debug serial window
    Serial.print("RPM:");
    Serial.print(vehicleRPM);
    Serial.println(" ");
  }
}
  
  
  /*
//Keep On Bottom
void doVehicleIsOffCheck(){
  vehicleRPM = updateVehicleRPM();
   if(rebootedLast <= 100) rebootedLast++;
    if(vehicleRPM >= DEFAULTOnRPM && !FULLVEHICLEOFFCHECK){
      Serial.println("Vehicle turned on");
      HeadHalosWhiteOn = true;
      FogHalosWhiteOn = true;
      if(rebootedLast > 100){
      Serial.println("Rebooting OBD");
        Serial1.print("ATWS\r");
        delay(1000);
        Serial1.print("0100\r");  
        delay(1000);
        Serial1.flush();
        resetOBDArray();
      }
      //matchHalosWithRPM(true, true);
    }else{
      if(rebootedLast >= 15) resetOBDArray();
    }
    delay(20);
}

void doRegularVehicleCheck(){
  vehicleRPM = updateVehicleRPM();
   if(rebootedLast <= 100) rebootedLast++;
    if(vehicleRPM <= DEFAULTOnRPM && FULLVEHICLEOFFCHECK){
      //resetDevice();
      allBool(false);
      allLEDOFF();
      Serial.println("Vehicle turned off");
      //resetOBDArray();
    }
    delay(20);
}
*/

void myOBDLoop(){
    if(!carON){
        if(Serial1.available()>1){
          getResponse();
          if(rxData[0] == 'E' && rxData[1] == 'L' && rxData[2] == 'M' && rxData[3] == '3' && rxData[4] == '2' && rxData[5] == '7'){
            onCarTurnedOn();
          }else if(rxData[0] == 'S' && rxData[1] == 'E' && rxData[2] == 'A' && rxData[3] == 'R' && rxData[4] == 'C' && rxData[5] == 'H' && rxData[6] == 'I' && rxData[7] == 'N'){
            onCarTurnedOn();
          }
        }
     }else{
       getRPM();
     }
     delay(50);
} //LOOP

