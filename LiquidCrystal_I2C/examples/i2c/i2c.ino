/* YourDuino.com Example Software Sketch
 LCD Display Blue: I2C/TWI Interface
 terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
/*-----( Declare Constants )-----*/
/*-----( Declare objects )-----*/
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27
/*-----( Declare Variables )-----*/


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  lcd.init(); // initialize the lcd
  lcd.backlight();
  // Print a message to the LCD.
  //lcd.setCursor(0, 1);
  lcd.print("Hello, world!");
}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  {
    // when characters arrive over the serial port...
    if (Serial.available()) {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      lcd.clear();
      // read all the available characters
      while (Serial.available() > 0) {
        // display each character to the LCD
        lcd.write(Serial.read());
      }
    }
  }

}/* --(end main loop )-- */

/*-----( Declare User-written Functions )-----*/


/* ( THE END ) */
