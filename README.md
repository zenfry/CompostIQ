# Smart Composting Bin - Compost Monitor

This project monitors the temperature and moisture level of your compost bin using an Arduino with sensors. It utilizes a temperature sensor (LM35) and a moisture sensor to keep track of the compost's conditions. The readings are displayed on an RGB LCD screen and can also be monitored through the Serial Monitor.
https://smartbin4.godaddysites.com/

## Features:
- Displays compost temperature and moisture level on an LCD.
- Real-time data updates every 2 seconds.
- Supports serial output for temperature and moisture for logging or analysis.

## Components Used:
- **Arduino Board** (e.g., Arduino Uno or similar)
- **LM35 Temperature Sensor**
- **Soil Moisture Sensor**
- **RGB LCD Display** (16x2)
- **Jumper Wires** for connections

## Pin Configuration:
- **TEMP_SENSOR**: Connected to analog pin A1
- **MOISTURE_SENSOR**: Connected to analog pin A0

## Libraries Required:
- **rgb_lcd**: Grove RGB LCD Library for controlling the 16x2 LCD.
- **Wire**: Standard I2C library for communication with the LCD.

## Circuit Diagram:
- Connect the **LM35** temperature sensor to analog pin A1.
- Connect the **Moisture sensor** to analog pin A0.
- Connect the **RGB LCD** to the appropriate I2C pins (SDA, SCL) on your Arduino.

## Code Explanation:
- **`setup()`**: Initializes the LCD and serial communication. It also displays an initial message "Compost Monitor" for 2 seconds.
- **`loop()`**: Continuously reads the temperature and moisture sensor values, maps them, and displays the readings on the LCD. The values are also printed to the serial monitor for debugging and monitoring.

## Temperature Calculation:
The LM35 sensor gives an output of 10mV per °C, so the temperature in Celsius is calculated by dividing the analog reading by 40.

## Moisture Level Calculation:
The moisture sensor gives an analog output, which is then mapped to a percentage (0-100%) to reflect the moisture content of the compost.

## Example Output:
**LCD Screen:**
```
Temp: 22.5C
Moisture: 65
```

**Serial Monitor:**
```
Temperature: 22.5°C
Moisture Level: 65
```

## Usage:
- Upload the code to your Arduino board.
- Monitor the compost's temperature and moisture through the LCD and Serial Monitor.
- Adjust your composting process accordingly based on these readings (e.g., add water if moisture is low, turn compost if temperature is too high).

## Troubleshooting:
- If the LCD does not display properly, check your wiring and ensure the correct library is installed.
- If the temperature or moisture readings seem off, check the calibration of your sensors.

## Future Enhancements:
- Add Wi-Fi or Bluetooth support to remotely monitor the compost.
- Implement thresholds for temperature and moisture levels to trigger notifications.

---

This README covers all the essentials, from setting up the hardware to understanding the code. If you need further tweaks or explanations, feel free to ask!
