/*
* Created By Nick Maiello (aV1rus)
* February of 2013
* Arduino Connect
*/
 void handleDirectCommand(String s){
  if(s == "CurrentState"){
    notifyHeadHaloState();
    notifyFogHaloState();
    notifyInteriorState();
    notifyFogState();
    notifyBrightness();
  }
 }
 void handleReceivedRaw(){
   while(Serial.available()>0){
    char received = Serial.read();
    //Serial.print("Handling ");
    //Serial.println(received);
    
    if(received == '!'){
        handleDirectCommand("CurrentState");
    }else{
      if(received == '$'){ //Speech
          char speak[5];
          int index = 2;
          speak[0]='$';
          speak[1]=':';
          while(Serial.available()){
            char s = Serial.read();
            if(s == '<') break;
            speak[index] = s;
            index++;
          }
          for(int i=index; i<5;i++){
            speak[i]=':';
          }
          if(speak) tellAndroid(speak);
      }else{
        handleReceived(received);
        if(!Serial.available()) checkForChange(); //Update old values with new
      }
    }
  }
 }
 
 
 void handleReceived(char rec){
      Serial.print("Handling-");
      Serial.print(rec);
      Serial.println("-");
      
  //HANDLE HEAD HEALOS
  if(rec == HEADS_RED_ON){
      turnON(headlightHaloREDPIN, BRIGHTNESS_HALOS); //Turn ON
      HeadHalosRedOn = true;
      
  }else if(rec == HEADS_RED_OFF){
      turnOFF(headlightHaloREDPIN, BRIGHTNESS_HALOS); //turn off
      HeadHalosRedOn = false;
      
  }else if(rec == HEADS_WHITE_ON){
      turnON(headlightHaloWHITEPIN, BRIGHTNESS_HALOS); //Turn On
      HeadHalosWhiteOn = true;
  }else if(rec == HEADS_WHITE_OFF){
      turnOFF(headlightHaloWHITEPIN, BRIGHTNESS_HALOS); //turn off
      HeadHalosWhiteOn = false;
      
  }else if(rec == HEADS_BOTH_ON){
      turnON(headlightHaloWHITEPIN, BRIGHTNESS_HALOS);  //Turn On
      turnON(headlightHaloREDPIN, BRIGHTNESS_HALOS);  //Turn On
      HeadHalosRedOn = true;
      HeadHalosWhiteOn = true;
  }else if(rec == HEADS_BOTH_OFF){
      turnOFF(headlightHaloWHITEPIN, BRIGHTNESS_HALOS);  //Turn OFF
      turnOFF(headlightHaloREDPIN, BRIGHTNESS_HALOS); //Turn OFF
      HeadHalosRedOn = false;
      HeadHalosWhiteOn = false;
  }
  //HANDLE FOGS HALOS
  else if(rec == FOGS_RED_ON){
      turnON(foglightHaloREDPIN, BRIGHTNESS_HALOS);  //Turn On
      FogHalosRedOn = true;
  }else if(rec == FOGS_RED_OFF){
      turnOFF(foglightHaloREDPIN, BRIGHTNESS_HALOS); //Turn OFF
      FogHalosRedOn = false;
      
  }else if(rec == FOGS_WHITE_ON){
      turnON(foglightHaloWHITEPIN, BRIGHTNESS_HALOS);  //Turn On
      FogHalosWhiteOn = true;
      
  }else if(rec == FOGS_WHITE_OFF){
      turnOFF(foglightHaloWHITEPIN, BRIGHTNESS_HALOS); //Turn OFF
      FogHalosWhiteOn = false;
  }else if(rec == FOGS_BOTH_ON){
      turnON(foglightHaloWHITEPIN, BRIGHTNESS_HALOS);  //Turn On
      turnON(foglightHaloREDPIN, BRIGHTNESS_HALOS);  //Turn On
      FogHalosWhiteOn = true;
      FogHalosRedOn = true;
  }else if(rec == FOGS_BOTH_OFF){
      turnOFF(foglightHaloWHITEPIN, BRIGHTNESS_HALOS); //Turn OFF
      turnOFF(foglightHaloREDPIN, BRIGHTNESS_HALOS); //Turn OFF
      FogHalosWhiteOn = false;
      FogHalosRedOn = false;
   }
   //HANDLE FOGS  
  else if(rec == FOGS_ON){
      turnON(foglightPIN, BRIGHTNESS_FOGS); //Turn On
      FogsOn = true;      
  }else if(rec == FOGS_OFF){
      turnOFF(foglightPIN, BRIGHTNESS_FOGS); //Turn OFF
      FogsOn = false;
  }
  //HANDLE INTERIOR
  else if(rec == INTERIOR_ON){
      turnON(interiorLight, BRIGHTNESS_INTERIOR); //Turn On
      InteriorOn = true;
  }else if(rec == INTERIOR_OFF){
      turnOFF(interiorLight, BRIGHTNESS_INTERIOR); //Turn OFF
      InteriorOn = false;
  }
  //HANDLE BRIGHTNESS
  else if(rec == BRIGHTNESS_UP){
    HandleBrightness();
  }else if(rec == BRIGHTNESS_DOWN){
    HandleBrightness();
  }
  //HANDLE PRESETS
  else if(rec == Emergency1){
    doBlink();
  }else if(rec == Emergency2){
    doBlink2();
  }else if(rec == Emergency3){
    doBlink3();
  }else if(rec == Emergency4){
    doBlink4();
  }else if(rec == Emergency3OnlyWhite){
    doBlink3OnlyWhite();
  }else if(rec == Emergency4OnlyRed){
    doBlink4OnlyRed();
  }else if(rec == HeartBeatRed){
    doHeartBeat(true);
  }else if(rec == HeartBeatWhite){
    doHeartBeat(false);
  }else if(rec == HaloFollowRPMMix  && vehicleRPM > 0){
    followOBDMix();
  }else if(rec == HaloFollowRPMWHITE  && vehicleRPM > 0){
    followOBD(headlightHaloWHITEPIN, foglightHaloWHITEPIN);
    
  }else if(rec == HaloFollowRPMRED  && vehicleRPM > 0){
    followOBD(headlightHaloREDPIN, foglightHaloREDPIN);
    
  }else if(rec == HaloFollowRPMREDSMOOTH  && vehicleRPM > 0){
    followOBDSmooth(headlightHaloREDPIN, foglightHaloREDPIN);
    
  }else if(rec == HaloFollowRPMWHITESMOOTH  && vehicleRPM > 0){
    followOBDSmooth(headlightHaloWHITEPIN, foglightHaloWHITEPIN);
  }
  
}

