/* This programm calculate voltage from analog input */
#include <Wire.h>
// Load I2C Library Display
#include <LiquidCrystal_I2C.h>

/* Need connect pins Display as:
 *  SDA en pin A4
 *  SCL en pin A5
*/

// Setup input PIN
int sensorPin = A0;

//Create an object on 0x27 with 16 columns x 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2); //

void setup() {
  // Inicialize LCD
  lcd.init();

  //Switch on backlight.
  lcd.backlight();
  //if you like switch off backlight, load the next sentence.
  //lcd.noBacklight();

}

void loop() {
 // Analogic sensor
 float analogPin = analogRead(A0);
 float value = 5 * analogPin /1023;
 
 // Write text on display
 lcd.setCursor(0,0);
 lcd.print("Voltaje");
 lcd.setCursor(0,1);
 lcd.print(value);
 lcd.print(" V");

delay(1500);
}
