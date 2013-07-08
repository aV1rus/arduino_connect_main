/*
* Created By Nick Maiello (aV1rus)
* February of 2013
* Arduino Connect
*/

 void refreshHalos(bool offFirst){
  // TURN OFF ALL
  if(offFirst){ //If off first turn off all LEDS
      analogWrite(headlightHaloWHITEPIN, LOW);   
      analogWrite(headlightHaloREDPIN, LOW);    
      analogWrite(foglightHaloWHITEPIN, LOW);   
      analogWrite(foglightHaloREDPIN, LOW);
  }
      if(HeadHalosWhiteOn) analogWrite(headlightHaloWHITEPIN, BRIGHTNESS_HALOS);   
      if(HeadHalosRedOn) analogWrite(headlightHaloREDPIN, BRIGHTNESS_HALOS);    
      if(FogHalosWhiteOn) analogWrite(foglightHaloWHITEPIN, BRIGHTNESS_HALOS);   
      if(FogHalosRedOn) analogWrite(foglightHaloREDPIN, BRIGHTNESS_HALOS);
      
          
}
 void refreshInterior(bool offFirst){
      if(offFirst){ //If off first turn off all LEDS
        analogWrite(interiorLight, LOW);   
      }
      if(InteriorOn) analogWrite(interiorLight, BRIGHTNESS_INTERIOR); 
}
 void refreshFogs(bool offFirst){
      if(offFirst){ //If off first turn off all LEDS
        analogWrite(foglightPIN, LOW);   
      }
      if(FogsOn) analogWrite(foglightPIN, BRIGHTNESS_FOGS); 
}
 void refresh(){
  refreshHalos(true);
  refreshInterior(true);
  refreshFogs(true);
}

