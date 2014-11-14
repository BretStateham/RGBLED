<a name="rgbled" />
# RGBLED #

<a name="overview" />
## Overview ##


**RGBLED** is an Arduino library for controlling four pin RGB LEDs.

It supports both Common Anode and Common Cathode RGB LEDs and has basic functions for showing specific RGB values, random values, and for displaying a "Hue, Saturation, Value" (HSV) color wheel.

Read below for more information:

- [Installation](#installation)
- [Example Circuits](#exampleCircuits)
- [Example Sketch](#exampleSketch)
- [Walkthrough Video](#video)

<a name="installation" />
## Installation  ##

To install the "RGBLED" library on your computer:

1. Download the lasted zip file from this repository: https://github.com/BretStateham/RGBLED/archive/master.zip

1. Unblock the downloaded .ZIP file

	![01010-UnblockZip](images/01010-unblockzip.png?raw=true "Unblock Zip File")

1. Next, we'll extract the zip file to the default arduino libraries folder on your computer.  This folder should have been created automatically for you when you installed the Arduino IDE.  You can read more about Library paths for each operating system here: http://arduino.cc/en/Guide/Libraries

	> **Note:** Starting with v1.0.5 of the Arduino IDE, the ability to add new libraries is built in.  However, when you download a repository from GitHub, the .zip file and internal folder include **"-master"** as part of the name (**"RGBLED-master.zip"**) in our case.  That makes the extracted folder name (**"RGBLED-master"**) not match the actual library name (**"RGBLED"**).  For that reason, we will manually extract the folder to the appropriate folder so we can rename it.  As mentioned above, you can learn more about Library paths and installation methods here: http://arduino.cc/en/Guide/Libraries

1. Right click on the downloaded **"RGBLED-master.zip"** file, and choose **"Extract All..." from the pop-up menu:

	![01020-ExtractZipFile](images/01020-extractzipfile.png?raw=true "Extract Zip File")

1. In the **"Extract Compressed (Zipped) Folders"** window, use the **"Browse..."** button to locate your **"/Documents/Arduino/Libraries"** folder (as documented [here](http://arduino.cc/en/Guide/Libraries)), and click **"Extract"**:

	![01030-ExtractToLibrariesFolder](images/01030-extracttolibrariesfolder.png?raw=true "Extract to Libraries Folder")

1. Navigate to the newly extracted folder, then right-click on it and select **"Rename"** from the pop-up menu:

	![01040-RenameFolder](images/01040-renamefolder.png?raw=true "Rename Folder")

1. Rename the folder to just **"RGBLED"**:

	![01050-RenameToRGBLED](images/01050-renametorgbled.png?raw=true "Rename to RGBLED")

1. Now, open the Arduino IDE, and from the menu select **"Sketch"** | **"Import Library..."**, and select the **"RGBLED"** library from the menu:

	![01060-ImportRGBEDLibrary](images/01060-importrgbedlibrary.png?raw=true "Import RGBLED Library")

1. And the appropriate include statement should be added to the top of your sketch:

	![01070-IncludeStatement](images/01070-includestatement.png?raw=true "Include Statement")


<a name="exampleCircuits" />
## Example Circuits ##

### Common Anode RGB LED ###

Common Anode RGB LEDs have a single, "common", Anode.  You connect the Anode to the Voltage supply (5Vdc in the case of the arduino).  You would then connect the R,G & B legs each to their own PWM capable digital PIN on the Arudino (with appropriate current limiting resistors of course).  PWM signals 0-255 on each pin vary that color from all the way on (0) to all the way off (255).  Yes, you read that right.  a PWM value of 0 turns that color all the way on, and a value of 255 turns that color all the way off.  This is because the LED has a common anode connected to 5V.  A PWM value of 255 basically means the pin is at 5V, and there is no voltage differential (no color) between the pin and the Anode.  When the PWM value on a pin is 0, there is a 5V voltage drop relative to the common Anode, and the color is shown at full brightness.  PWM values between 0 and 255 will show the color at a brightness relative to the PWM value.

![02010-CommonAnodeCircuit](images/02010-commonanodecircuit.png?raw=true "Common Anode Circuit")

### Common Cathode RGB LED ###

Common Anode RGB LEDs have a single, "common", Cathode.  You connect the Cathode to ground (GND) on the Arduino.  You would then connect the R,G & B legs each to their own PWM capable digital PIN on the Arudino (with appropriate current limiting resistors of course).  PWM signals 0-255 on each pin vary that color from all the way off (0) to all the way on (255).  This seems to make more sense than the inverted value-to-brightness relationship on the Common Anode LEDs.  PWN values 0-255 cause a relative brightness on that pin color from all the way off (0) to all the way on (255).

![02020-CommonCathodeCircuit](images/02020-commoncathodecircuit.png?raw=true "Common Cathode Circuit")

<a name="exampleSketch" />
## Example Sketch ##

1. You can open the example sketch from the Arduino IDE (assuming you following the [installation instructions above](#installation)).  From the Arduino IDE menu, select **"File"** | **"Examples"** | **"RGBLED"** | **"RGBLedExample"**

	![03010-RGBLedExample](images/03010-rgbledexample.png?raw=true "Open RGBLedExample")

1. The following sketch should be loaded into the editor:

````C++
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
````

1. The sketch is pretty well documented, so the reader is left to review the sketch on their own.

<a name="video" />
## Walkthrough Video ##

I've recorded a quick walkthrough video that demonstrates the usage of the library.  You can get the video from here: http://youtu.be/eQKDne_CPyQ

[![04010-VideoPic](images/04010-videopic.png?raw=true "Video Pic")](http://youtu.be/eQKDne_CPyQ)
