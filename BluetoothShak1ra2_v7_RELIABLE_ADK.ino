#include "Arduino.h"
#include <SPI.h>
#include <Adb.h>


#include "leds.h"
#include "refresh.h"
#include "obd.h"
#include "led_blinks.h"
#include "brightness.h"
#include "on_receive.h"
#include "ADK.h"

/*
* Created By Nick Maiello (aV1rus)
February of 2013
Arduino Connect
Connect to Arduino and Receive command messages
*/
int StatusLed = 13;
boolean statusLedOn = false;
boolean ran = false;

//int count = 0;
void setup(){
  // start Serial port at 115200 bps:
  //setupReset();
  //pinMode(StatusLed, OUTPUT);
  pinMode(interiorLight, OUTPUT);
  pinMode(headlightHaloWHITEPIN, OUTPUT);
  pinMode(headlightHaloREDPIN, OUTPUT);
  pinMode(foglightHaloWHITEPIN, OUTPUT);
  pinMode(foglightHaloREDPIN, OUTPUT);
  pinMode(foglightPIN, OUTPUT);
  //Setup usb Serial connection to computer
  Serial.begin(57600);
  Serial1.begin(9600);
  Serial2.begin(57600);
  Serial1.println("ATWS\r");
  boolean isON = false;
  analogWrite(StatusLed, LOW); 
  refresh();
  Serial.println("Booted");
  //handleDirectCommand("CurrentState");
  
  setupADK(); //prepare ADK
  
}
void loop(){
  while(Serial.available()==0){  //&& Serial2.available()==0
      myOBDLoop();  //DO obd work
      statusLooping();  //Display work being done
      ADK_LOOP(); //Do ADK work
  }
  
  BRIGHTNESS_HALOS2 = BRIGHTNESS_HALOS;
  BRIGHTNESS_INTERIOR2 = BRIGHTNESS_INTERIOR;
  BRIGHTNESS_FOGS2 = BRIGHTNESS_FOGS;
  HeadHalosRedOn2 = HeadHalosRedOn;
  FogHalosRedOn2 = FogHalosRedOn;
  HeadHalosWhiteOn2 = HeadHalosWhiteOn;
  FogHalosWhiteOn2 = FogHalosWhiteOn;
  InteriorOn2 = InteriorOn;
  FogsOn2 = FogsOn;
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
          if(speak)
          tellAndroid(speak);
      }else{
        handleReceived(received);
        if(!Serial.available()){ 
          refresh();
          checkForChange(); //Update old values with new
        }
      }
    }
  }
  /*
  while(Serial2.available()>0){
    char received = Serial2.read();
    if(received == '!'){
        handleDirectCommand("CurrentState");
    }
  }*/
}



static void statusLooping(){
    //int a = availableMemory();
   if(statusLedOn){
       digitalWrite(StatusLed, LOW); 
       statusLedOn = false;
    }else{
       digitalWrite(StatusLed, HIGH); 
       statusLedOn = true;
    }
    //Serial.print("Available Mem: ");
    //Serial.println(a);
}


static int availableMemory(){
   int size = 8192;
   byte *buf;
   while ((buf = (byte *) malloc(--size)) == NULL);
   free(buf);
   return size;
}


static void handleDirectCommand(String s){
  if(s == "CurrentState"){
    notifyHeadHaloState();
    notifyFogHaloState();
    notifyInteriorState();
    notifyFogState();
    notifyBrightness();
  }
}





