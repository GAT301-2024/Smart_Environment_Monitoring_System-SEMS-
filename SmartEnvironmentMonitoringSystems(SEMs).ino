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
