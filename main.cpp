#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
// (RS, Enable, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// 1. DEFINE the pixel patterns
//Can copy these binary codes from simulated code.
byte batteryIcon[8] = {
  B01110,
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
  B00000
};

byte heartIcon[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000
};

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 4);

  // 2. LOAD the patterns into CG-RAM
  // We can store up to 8 characters (0-7)
  
  // Load battery icon into slot 0
  lcd.createChar(0, batteryIcon);
  
  // Load heart icon into slot 1
  lcd.createChar(1, heartIcon);

  // 3. DISPLAY the custom characters
  
  // Move to the first line
  lcd.setCursor(0, 0);
  lcd.print("Custom Chars:");

  // Move to the second line
  lcd.setCursor(0, 1);
  
  // Print the battery (from slot 0)
  lcd.write(byte(0)); 
  
  // Print a space
  lcd.print(" ");
  
  // Print the heart (from slot 1)
  lcd.write(byte(1));

  // You can also mix them with normal text
  lcd.setCursor(0, 2);
  lcd.print("I ");
  lcd.write(byte(1)); // Print heart
  lcd.print(" Arduino!");
}

void loop() {
  // No code needed here for this example
}