/* Este programa mide voltajes desde 0V a 5V utilizando la entrada analógica*/
#include <Wire.h>
// Cargar libreria LCD para I2C
#include <LiquidCrystal_I2C.h>

/* Para que funcione la pantalla hay que conectar:
 *  SDA en pin A4
 *  SCL en pin A5
*/

// Configurar pin de entrada
int sensorPin = A0;

//Crear el objeto lcd  direccion  0x27 y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27, 16, 2); //

void setup() {
  // Inicializar el LCD
  lcd.init();

  //Encender la luz de fondo.
  lcd.backlight();
  //Apagar la luz de fondo.
  //lcd.noBacklight();

}

void loop() {
 // Sensor analógico
 float analogPin = analogRead(A0);
 float value = 5 * analogPin /1023;
// float value = fmap(analogPin, 0, 1023, 0.0, 5.0);
 
 // Escribir texto
 lcd.setCursor(0,0);
 lcd.print("Voltaje");
 lcd.setCursor(0,1);
 lcd.print(value);
 lcd.print(" V");

delay(1500);
}

/**
float fmap (float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
**/
