/*
  RGBLedExample
  Example for the RGBLED Library
  Created by Bret Stateham, November 13, 2014
  You can get the latest version from http://github.com/BretStateham/RGBLED
*/
#include <RGBLED.h>

// Declare an RGBLED instanced named rgbLed
// Red, Green and Blue LED legs are connected to PWM pins 11,9 & 6 respectively
// In this example, we have a COMMON_ANODE LED, use COMMON_CATHODE otherwise
RGBLED rgbLed(11,9,6,COMMON_ANODE);

//How long to show each color in the example code (in milliseconds);
int delayMs = 1000;

void setup() {
  //Initialize Serial communications
  Serial.begin(9600);
  
  //Report the LED type and pins in use to the serial port...
  Serial.println("Welcome to the RGBLED Sample Sketch");
  String ledType = (rgbLed.commonType==0) ? "COMMON_CATHODE" : "COMMON_ANODE";
  Serial.println("Your RGBLED instancse is a " + ledType + " LED");
  Serial.println("And the Red, Green, and Blue legs of the LEDs are connected to pins:");
  Serial.println("r,g,b = " + String(rgbLed.redPin) + "," + String(rgbLed.greenPin) + "," + String(rgbLed.bluePin) );
  Serial.println("");
}

void loop() {

  //The code in the loop shows multiple exampls

  //Set the RGBLED to show RED only
  //printRgbValues() prints various LED values to the Serial port
  //you can monitor the serial port to see the values printed
  //The delay(delayMs) waits for 1 second to be able to see the color shown
  rgbLed.writeRGB(255,0,0);
  printRgbValues();
  delay(delayMs);

  //Set the RGBLED to show GREEN only
  rgbLed.writeRGB(0,255,0);
  printRgbValues();
  delay(delayMs);

  //Set the RGBLED to show BLUE only
  rgbLed.writeRGB(0,0,255);
  printRgbValues();
  delay(delayMs);

  //Set the RGBLED to show YELLOW (RED & GREEN) only
  rgbLed.writeRGB(255,255,0);
  printRgbValues();
  delay(delayMs);

  //Set the RGBLED to show ORANGE (RED & partial GREEN) only
  rgbLed.writeRGB(255,128,0);
  printRgbValues();
  delay(delayMs);

  //Set the RGBLED to show PURPLE (RED & BLUE) only
  rgbLed.writeRGB(255,0,255);
  printRgbValues();
  delay(delayMs);

  //Set the RGBLED to show PINK (RED & partial BLUE) only
  rgbLed.writeRGB(255,0,128);
  printRgbValues();
  delay(delayMs);

  //Set the RGBLED to show a random color
  rgbLed.writeRandom();
  printRgbValues();
  delay(delayMs);
  
  //Set the pins individually if needed
  rgbLed.writeRed(255);
  rgbLed.writeGreen(255);
  rgbLed.writeBlue(255);
  printRgbValues();
  delay(delayMs);
  
  //The above code does the same thing as...
  rgbLed.writeRGB(255,255,255);
  printRgbValues();
  delay(delayMs);

  //Show the color wheel
  Serial.println("Showing RGB Color Wheel...");
  Serial.println("------------------------------");
  //Use a 25ms delay between each color in the wheel
  rgbLed.writeColorWheel(25);

  //Turn off the RGBLED
  rgbLed.turnOff();
  printRgbValues();
  delay(delayMs);
  

}

//printRgbValues prints the LED pins and values to the serial port
//You can monitor the serial port to see those values
void printRgbValues() {
  Serial.println("Requested RGB Values:");
  Serial.println("(r,g,b)=(" + String(rgbLed.redValue) + "," + String(rgbLed.greenValue) + "," + String(rgbLed.blueValue) + ")");
  Serial.println("Mapped RGB Values based on type (COMMON_ANODE or COMMON_CATHODE):");
  Serial.println("Mapped(r,g,b)=(" + String(rgbLed.redMappedValue) + "," + String(rgbLed.greenMappedValue) + "," + String(rgbLed.blueMappedValue) + ")");
  Serial.println("------------------------------");
}
