# KUBOMU-EDWIN-23-U-2223-GIM-PS
Smart Monitoring Environment Systems(SEMs)

# Temperature and Humidity Monitoring System

## Overview
This project uses a DHT11 sensor to measure temperature and humidity levels. The readings are displayed on an I2C LCD and indicated by two LEDs (green and red). The system alerts when the temperature exceeds 25°C or the humidity exceeds 60%.

## Hardware Components
- Arduino Uno
- DHT11 Temperature and Humidity Sensor
- I2C LCD Display (16x2)
- Green LED
- Red LED
- Resistors (220Ω for LEDs)
- Breadboard and jumper wires

## Software Requirements
- Arduino IDE
- DHT Sensor Library ([Download](https://github.com/adafruit/DHT-sensor-library))
- LiquidCrystal_I2C Library ([Download](https://github.com/johnrickman/LiquidCrystal_I2C))


## Circuit Diagram
![Circuit Diagram](images/circuit_diagram.png)


## Setup Instructions
1. *Hardware Setup:*
   - Connect the DHT11 sensor to the Arduino (VCC to 5V, GND to GND, Data pin to digital pin 2).
   - Connect the LCD to the I2C pins (SDA, SCL) of the Arduino.
   - Connect the LEDs to digital pins 3 and 4 with current-limiting resistors.

2. *Software Setup:*
   - Download and install the required libraries (DHT Sensor Library and LiquidCrystal_I2C Library) in the Arduino IDE.
   - Upload the provided code to the Arduino board.

## Usage
1. Power the Arduino board.
2. The LCD will display the current temperature and humidity.
3. The LEDs will indicate the status:
   - Green LED: Normal conditions (temperature ≤ 25°C and humidity ≤ 60%).
   - Red LED: Alert conditions (temperature > 25°C or humidity > 60%).

## Additional Notes
- Ensure the DHT11 sensor is connected properly to avoid incorrect readings.
- The thresholds for temperature and humidity can be adjusted in the code as needed.
- This project can be extended by adding features like data logging or remote monitoring.
