#include "Arduino.h"
#include "SiI2Cscan.h"
#include <SPI.h>
#include <Wire.h>



SiI2Cscan::SiI2Cscan()
{

}

void SiI2Cscan::begin()
{
	Wire.begin();
	scan();
}

void SiI2Cscan::scan(){
	byte error, address;
    	int nDevices;
    	Serial.println(F("Scanning..."));
    	nDevices = 0;
    	for(address = 1; address < 127; address++ )
    	{
      		// The i2c_scanner uses the return value of
      		// the Write.endTransmisstion to see if
      		// a device did acknowledge to the address.
      		Wire.beginTransmission(address);
      		error = Wire.endTransmission();
  
     
   
	      if (error == 0)
	      {
	        Serial.print(F("I2C Devise found at 0x"));
	        if (address<16)
	          Serial.print(F("0"));
	        Serial.print(address,HEX);
	        Serial.println(F("  !"));
	   
	        nDevices++;
	      }
	      else if (error==4)
	      {
	        Serial.print(F("Erreur inconnue a cette address 0x"));
	        if (address<16)
	          Serial.print(F("0"));
	        Serial.print(address,HEX);
	      }
	      else
	      {
	      	Serial.print(F("Error: ")); Serial.println(error);
	      }
	    }
	    if (nDevices == 0)
	      Serial.println(F("Aucun appareil I2C trouve\n"));
	    else
	      Serial.println(F("Fin\n"));
   
	delay(5000);           // wait 5 seconds for next scan
}
