#include <Wire.h>
#include "rgb_lcd.h"  // Grove LCD Library

// Initialize LCD
rgb_lcd lcd;

// Sensor Pins
#define TEMP_SENSOR A1
#define MOISTURE_SENSOR A0

void setup() {
    Serial.begin(9600);
    
    // Initialize LCD
    lcd.begin(16, 2); // 16x2 LCD
    
    lcd.setRGB(0, 255, 0);  // Green Backlight
    lcd.print("Compost Monitor");
    delay(2000);
    lcd.clear();
}

void loop() {
    // Read temperature
      int tempValue = analogRead(TEMP_SENSOR);
    float temperatureC = (tempValue / 40); // LM35 outputs 10mV per °C, so multiply by 100
  

    // Read moisture level
    int moistureLevel = analogRead(MOISTURE_SENSOR);  // Read the moisture sensor
    int moisturePercent = map(moistureLevel, 0, 1023, 0, 100);
    float moisturePercentB = (moisturePercent + 1);  // Map to a percentage (0 to 100%)


    // Display values on LCD
    lcd.setCursor(0, 0);  // First row
    lcd.print("Temp: ");
    lcd.print(temperatureC, 1);  // Show one decimal place
    lcd.print("C");

    lcd.setCursor(0, 1);  // Second row
    lcd.print("Moisture: ");
    lcd.print(moisturePercentB);

    // Print to Serial Monitor too
    Serial.print("Temperature: ");
    Serial.print(temperatureC, 1);  // Print with one decimal place
    Serial.println("°C");

    Serial.print("Moisture Level: ");
    Serial.println(moisturePercentB);

    delay(2000);  // Refresh every 2 seconds
}
