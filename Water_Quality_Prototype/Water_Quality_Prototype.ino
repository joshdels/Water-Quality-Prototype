/*
Project: Crayfish Water Monitoring
Date: 1/26/2025
Reason: To be the best crayfish in my locality

Documentation:
   LCD: https://docs.oyoclass.com/unoeditor/Libraries/liquid_crystal/
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define sensor pin
const int turbidityPin = A0;

// Variables for sensor readings
int T_sensorValue = 0;
float voltage = 0.0;
float turbidity = 0.0;

// Initialize LCD (address 0x27, 16 columns, 4 rows)
LiquidCrystal_I2C lcd(0x27, 16, 4);

// Function to display values on the LCD
void lcd_write(float voltage, float turbidity) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome! CrayDevs");
  lcd.setCursor(0, 2);
  lcd.print("Turbidity: ");
  lcd.setCursor(0, 3);
  lcd.print(turbidity);
  lcd.print(" NTU");
}

void setup() {
  Serial.begin(9600); 
  pinMode(turbidityPin, INPUT);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.print("Initializing....");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read the analog value from the sensor
  T_sensorValu = analogRead(turbidityPin);

  // Calculate voltage and turbidity
  voltage = T_sensorValue * (5.0 / 1023.0); // Convert analog reading to voltage
  turbidity = (4.5 - voltage) * 300;      // Calculate turbidity (adjust calibration as needed)

  // Print values to Serial Monitor for debugging
  Serial.print("Raw Sensor Value: ");
  Serial.print(T_sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print(" | Turbidity: ");
  Serial.print(turbidity);
  Serial.println(" NTU");

  // Display values on the LCD
  lcd_write(voltage, turbidity);

  delay(1000); // Wait 1 second before the next reading
}
