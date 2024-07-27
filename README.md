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

## Code
cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Define DHT sensor type and pin
#define DHTTYPE DHT11
#define DHTPIN 2

// Initialize DHT sensor and LCD screen
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define LED pins
const int greenLedPin = 3;
const int redLedPin = 4;

// Define temperature and humidity thresholds
const float tempThreshold = 25.0;
const float humidThreshold = 60.0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize LCD screen
  lcd.backlight();
  lcd.begin();

  // Initialize LED pins
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  // Initialize DHT sensor
  dht.begin();
}

void loop() {
  // Read temperature and humidity
  float temp = dht.readTemperature();
  float humid = dht.readHumidity();

  // Check if readings are valid
  if (isnan(temp) || isnan(humid)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print readings to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C, Humidity: ");
  Serial.print(humid);
  Serial.println(" %");

  // Display readings on LCD screen
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(humid);
  lcd.print("%");

  // Control LED indicators based on readings
  if (temp > tempThreshold || humid > humidThreshold) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }

  // Wait for 2 seconds before next reading
  delay(2000);
}


## Additional Notes
- Ensure the DHT11 sensor is connected properly to avoid incorrect readings.
- The thresholds for temperature and humidity can be adjusted in the code as needed.
- This project can be extended by adding features like data logging or remote monitoring.
