/*
* Created By Nick Maiello (aV1rus)
* February of 2013
* Arduino Connect
*/

boolean APP_DISPLAYED = false;  //Is app displayed on connected android
boolean APP_SU = false;

// Elapsed time for ADC sampling
long lastTime;


// Event handler for the shell connection. 
void adbEventHandler(Connection * connection, adb_eventType event, uint16_t length, uint8_t * data){
  int i;
  if (event == ADB_CONNECTION_RECEIVE){
    for (i=0; i<length; i++){
      handleReceived((char)data[i]);
    }
      
    if(i>0){
      Serial.print("\n");
      //Serial.println("Gotcha");
      //uint16_t data = data;
      //connection->writeString("Gotcha");
      //connection->write(2, (uint8_t*)&data);
    }
  }
  
  /*
  if(!APP_SU){
        shell->writeString("su\n");
        APP_SU = true;
  }
  */
}

// Event handler for the shell connection. 
void adbShellHandler(Connection * connection, adb_eventType event, uint16_t length, uint8_t * data){
  int i;
  if (event == ADB_CONNECTION_RECEIVE){
    for (i=0; i<length; i++){
      Serial.print((char)data[i]);
    }
      Serial.print("\n");
  }
  
  /*
  if(!APP_SU){
        shell->writeString("su\n");
        APP_SU = true;
  }
  */
}



void setupADK(){  //Prepare the adk bridge
  // Initialise the ADB subsystem.  
  ADB::init();
  
  // Note start time
  lastTime = millis();

  // Open an ADB stream to the phone's shell. Auto-reconnect
  shell = ADB::addConnection("shell:", true, adbShellHandler); 
  //Open adb on tcp port
  connection = ADB::addConnection("tcp:4567", true, adbEventHandler);  
  
}



void ADK_LOOP(){  //What needs to be constantly done for ADB
  ADB::poll();
  //char charArray[200];
  // Check for incoming serial data
  
   if (!shell->isOpen()){
     APP_DISPLAYED = false;
     APP_SU = false;
   }
    
   if(!APP_DISPLAYED){
    if (shell->status == ADB_OPEN){
        delay(500);
        shell->writeString("am start -n av1rus.arduinoconnect.adk/av1rus.arduinoconnect.adk.MActivity\n");
        delay(2);
        APP_DISPLAYED = true;
        Serial.println("App Opened on Connected Device");
    }
   }
      
      /*
        if ((millis() - lastTime) > 1000){
          //uint16_t data = 'a';
          //connection->write(2, (uint8_t*)&data);
          //Serial.println("timer");
          connection->writeString("Gotcha");  //**THIS WORKED**
          lastTime = millis();
        }
      
    */
  // Poll the ADB subsystem.
  while(shell->status == ADB_RECEIVING || shell->status == ADB_WRITING){    
    ADB::poll();
  }
  
}
void tellAndroid(char s[]){
          Serial.print("Telling USB Android");
          Serial.println(s);
          connection->writeString(s);
}
