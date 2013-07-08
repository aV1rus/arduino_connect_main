/*
* Created By Nick Maiello (aV1rus)
* February of 2013
* Arduino Connect
*/
Connection * shell;  ///Declared for ADK.h this class and ADK both use shell and connection
Connection * connection;



char HEADS_RED_ON = 'A';
char HEADS_RED_OFF = 'a';
char HEADS_WHITE_ON = 'B';
char HEADS_WHITE_OFF = 'b';
char HEADS_BOTH_ON = 'C';
char HEADS_BOTH_OFF = 'c';

char FOGS_RED_ON = 'D';
char FOGS_RED_OFF = 'd';
char FOGS_WHITE_ON = 'E';
char FOGS_WHITE_OFF = 'e';
char FOGS_BOTH_ON = 'F';
char FOGS_BOTH_OFF = 'f';

char FOGS_ON = 'G';
char FOGS_OFF = 'g';
char INTERIOR_ON = 'H';
char INTERIOR_OFF = 'h';

char BRIGHTNESS_UP = '+';
char BRIGHTNESS_DOWN = '-';

char B_HALOS = 'A';
char B_INTERIOR = 'B';
char B_FOGS = 'C';

int BRIGHTNESS_HALOS = 220;
int BRIGHTNESS_INTERIOR = 220;
int BRIGHTNESS_FOGS = 220;

//PRESETS
const char Emergency1= 'Z';
const char Emergency2= 'Y';
const char Emergency3= 'X';
const char Emergency4= 'W';
const char HeartBeatRed= 'V';
const char HeartBeatWhite= 'U';
const char HaloFollowRPMMix= 'T';
const char HaloFollowRPMWHITE= 'S';
const char HaloFollowRPMRED= 'R';
const char HaloFollowRPMWHITESMOOTH= 'Q';
const char HaloFollowRPMREDSMOOTH= 'P';
const char Emergency3OnlyWhite= 'O';
const char Emergency4OnlyRed= 'N';




boolean HeadHalosRedOn = false;
boolean FogHalosRedOn = false;
boolean HeadHalosWhiteOn = false;
boolean FogHalosWhiteOn = false;

boolean InteriorOn = false;
boolean FogsOn = false;

int headlightHaloWHITEPIN = 12;
int headlightHaloREDPIN = 11;
int foglightHaloWHITEPIN = 10;
int foglightHaloREDPIN = 9;

int headlightHaloPIN = headlightHaloWHITEPIN; // DEFAULT pin for white halo
int foglightHaloPIN = foglightHaloWHITEPIN; // DEFAULT pin for white halo

int foglightPIN = 8;
int interiorLight = 7;
//This is a character buffer that will store the data from the serial port


//Keep track of old values with a copy of above values
int BRIGHTNESS_HALOS2 = 170;
int BRIGHTNESS_INTERIOR2 = 220;
int BRIGHTNESS_FOGS2 = 170;

bool HeadHalosRedOn2 = false;
bool FogHalosRedOn2 = false;
bool HeadHalosWhiteOn2 = false;
bool FogHalosWhiteOn2 = false;

bool InteriorOn2 = false;
bool FogsOn2 = false;

void turnON(int led, int itsBright){
  int Bright = 0;
  while(Bright < itsBright){
    Bright++;
    analogWrite(led, Bright); 
    delay(1);
  }
}
void turnOFF(int led, int itsBright){
  int Bright = itsBright;
  while(Bright > 0){
    Bright--;
    analogWrite(led, Bright); 
    delay(1);
  }
}

void allLEDOFFFADE(){
  if(HeadHalosWhiteOn) turnOFF(headlightHaloWHITEPIN, BRIGHTNESS_HALOS);   
  if(HeadHalosRedOn) turnOFF(headlightHaloREDPIN, BRIGHTNESS_HALOS);    
  if(FogHalosWhiteOn) turnOFF(foglightHaloWHITEPIN, BRIGHTNESS_HALOS);   
  if(FogHalosRedOn) turnOFF(foglightHaloREDPIN, BRIGHTNESS_HALOS);
  analogWrite(interiorLight, LOW);  
  analogWrite(foglightPIN, LOW); 
}
void allLEDOFF(){
  analogWrite(headlightHaloWHITEPIN, LOW);   
  analogWrite(headlightHaloREDPIN, LOW);    
  analogWrite(foglightHaloWHITEPIN, LOW);   
  analogWrite(foglightHaloREDPIN, LOW);
  analogWrite(interiorLight, LOW);  
  analogWrite(foglightPIN, LOW); 
}
void allBool(boolean f){
  HeadHalosRedOn = f;
  FogHalosRedOn = f;
  HeadHalosWhiteOn = f;
  FogHalosWhiteOn = f;
  InteriorOn = f;
  FogsOn = f;
}


void notifyAllConnections(char string[]){
  Serial.println(string);
  Serial2.println(string);
  connection->writeString(string);
}



void notifyHeadHaloState(){
  if(HeadHalosRedOn && HeadHalosWhiteOn){
    notifyAllConnections("DT:S:HB:1");
    delay(10);
  }
  else if(!HeadHalosRedOn && !HeadHalosWhiteOn){
    notifyAllConnections("DT:S:HB:0");
    delay(10);
  }
  else{
    if(HeadHalosRedOn){
      notifyAllConnections("DT:S:HR:1");
      delay(10);
    }
    else if(HeadHalosWhiteOn){
      notifyAllConnections("DT:S:HW:1");
      delay(10);
    }
  }
}
void notifyFogHaloState(){
  if(FogHalosRedOn && FogHalosWhiteOn){
    notifyAllConnections("DT:S:FB:1");
    delay(10);
  }
  else if(!FogHalosRedOn && !FogHalosWhiteOn){
    notifyAllConnections("DT:S:FB:0");
    delay(10);
  }
  else{
    if(FogHalosRedOn){
      notifyAllConnections("DT:S:FR:1");
      delay(10);
    }
    else if(FogHalosWhiteOn){
     notifyAllConnections("DT:S:FW:1");
      delay(10);
    }
  }
}
void notifyInteriorState(){
  if(InteriorOn){
    notifyAllConnections("DT:S:IN:1");
    delay(10);
  }
  else{
    notifyAllConnections("DT:S:IN:0");
    delay(10);
  }
}
void notifyFogState(){
  if(FogsOn){
    notifyAllConnections("DT:S:FS:1");
    delay(10);
  }
  else{
    notifyAllConnections("DT:S:FS:0");
    delay(10);
  }
}
char* getString(String s1, int s2){
  String newString = s1;
  newString+=s2;
  char charBuff[newString.length()];
  newString.toCharArray(charBuff, newString.length());
  return charBuff;
}
void notifyHaloBrightness(){
  String s = "DT:B:HB:";
  int s2 = BRIGHTNESS_HALOS;
  notifyAllConnections(getString(s, s2));
  
  
  delay(10);
}
void notifyInteriorBrightness(){
  String s = "DT:B:IB:";
  int s2 = BRIGHTNESS_INTERIOR;
  notifyAllConnections(getString(s, s2));
  delay(10);
}
void notifyFogBrightness(){
  String s = "DT:B:FB:";
  int s2 = BRIGHTNESS_FOGS;
  notifyAllConnections(getString(s, s2));
  delay(10);
}
void notifyBrightness(){
  if(BRIGHTNESS_HALOS2 != BRIGHTNESS_HALOS){
    BRIGHTNESS_HALOS2 = BRIGHTNESS_HALOS;
    notifyHaloBrightness();
  }
  if(BRIGHTNESS_INTERIOR2 != BRIGHTNESS_INTERIOR){
    notifyInteriorBrightness();
    BRIGHTNESS_INTERIOR2 = BRIGHTNESS_INTERIOR;
  }
  if(BRIGHTNESS_FOGS2 != BRIGHTNESS_FOGS){
    BRIGHTNESS_FOGS2 = BRIGHTNESS_FOGS;
    notifyFogBrightness();
  }
}





void checkForChange(){
  if(BRIGHTNESS_HALOS2 != BRIGHTNESS_HALOS){
    delay(100);
    notifyHaloBrightness();
  }
  if(BRIGHTNESS_INTERIOR2 != BRIGHTNESS_INTERIOR){
    delay(100);
    notifyInteriorBrightness();
  }
  if(BRIGHTNESS_FOGS2 != BRIGHTNESS_FOGS){
    delay(100);
    notifyFogBrightness();
  }
  if(HeadHalosRedOn2 != HeadHalosRedOn || HeadHalosWhiteOn2 != HeadHalosWhiteOn){
    delay(100);
    notifyHeadHaloState();
  }
  if(FogHalosRedOn2 != FogHalosRedOn || FogHalosWhiteOn2 != FogHalosWhiteOn){
    delay(100);
    notifyFogHaloState();
  }
  if(InteriorOn2 != InteriorOn){
    delay(100);
    notifyInteriorState();
  }
  if(FogsOn2 != FogsOn){
    delay(100);
    notifyFogState();
  }
}



