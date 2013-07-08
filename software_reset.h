/*
* Created By Nick Maiello (aV1rus)
* February of 2013
* Arduino Connect
*/


int reset_pin = 3;

void setupReset(){
  //digitalWrite(reset_pin, HIGH); //We need to set it HIGH immediately on boot
  //pinMode(reset_pin,OUTPUT);     //We can declare it an output ONLY AFTER it's HIGH
                         // (( HACKHACKHACKHACK ))
}

void resetDevice(){
  //Serial.println("Performing RESET!");
  //digitalWrite(reset_pin, LOW); //Pulling the RESET pin LOW triggers the reset.
}



