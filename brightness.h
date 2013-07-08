/*
* Created By Nick Maiello (aV1rus)
* February of 2013
* Arduino Connect
*/



/*
void refreshBrightness(int *brightness, int *newBright){
  if(brightness<newBright){
    while(brightness<newBright){
      brightness++;
      refreshHalos(false);
      delay(2);
    }
  }else{
    while(brightness>newBright){
       brightness--;
       refreshHalos(false);
       delay(2);
    }
  }
}
*/
int brightness(){
  boolean keepGoing = true;
  int i = 0;
  String integ = "";
  while(Serial.available()>0 && keepGoing){
    char rec = Serial.read();
    if(rec == '0' || rec == '1' || rec == '2' || rec == '3' || rec == '4' || rec == '5' || rec == '6' || rec == '7' || rec == '8' || rec == '9'){
      integ += rec;
    }else{ keepGoing = false; break;}
    
  }
  if(integ.length()>0){
    
    i = integ.toInt();
  }
  if(i > 255) return 255;
  else if(i <0) return 0;
  
  return i;
}

void HandleBrightness(){
  if(Serial.available()>0){
    char rec = Serial.read();
      if(rec == B_HALOS){ 
          BRIGHTNESS_HALOS = brightness();
          refreshHalos(false);
        }else if(rec == B_INTERIOR){
          BRIGHTNESS_INTERIOR = brightness();
          refreshInterior(false);
        }else if(rec == B_FOGS){
          BRIGHTNESS_FOGS = brightness();
          refreshFogs(false);
        }
    }
}
/*
void HandleBrightness(){
  if(Serial.available()>0){
    char rec = Serial.read();
      if(rec == B_HALOS){ 
          refreshBrightness(BRIGHTNESS_HALOS, brightness());
        }else if(rec == B_INTERIOR){
          refreshBrightness(BRIGHTNESS_INTERIOR, brightness());
        }else if(rec == B_FOGS){
          refreshBrightness(BRIGHTNESS_FOGS, brightness());
        }
    }
}*/
/*
if(rec == B_HALOS){
          if(brighten){ BRIGHTNESS_HALOS += 10; if(BRIGHTNESS_HALOS >=255) BRIGHTNESS_HALOS = 255;
          }else{ BRIGHTNESS_HALOS -= 10; if(BRIGHTNESS_HALOS <=0) BRIGHTNESS_HALOS = 0;}
          refreshHalos(false);
        }else if(rec == B_INTERIOR){
          if(brighten){ BRIGHTNESS_INTERIOR += 10; if(BRIGHTNESS_INTERIOR >=255) BRIGHTNESS_INTERIOR = 255;
          }else{ BRIGHTNESS_INTERIOR -= 10;  if(BRIGHTNESS_INTERIOR <=0) BRIGHTNESS_INTERIOR = 0;}
          refreshInterior(false);
        }else if(rec == B_FOGS){
          if(brighten){ BRIGHTNESS_FOGS += 10; if(BRIGHTNESS_FOGS >=255) BRIGHTNESS_FOGS = 255;
          }else{ BRIGHTNESS_FOGS -= 10; if(BRIGHTNESS_FOGS <=0) BRIGHTNESS_FOGS = 0;}
          refreshFogs(false);
        }
*/
