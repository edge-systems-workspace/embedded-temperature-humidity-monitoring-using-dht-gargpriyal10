#include <Arduino.h>
#include<wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
/**
 * @file main.ino
 * @brief Embedded Temperature and Humidity Monitoring using DHT11
 * @author PRIYAL GARG
 * @date 2026-20-02
 *
 *
 * @details
 * This program reads environmental data from the DHT11 sensor
 * and displays temperature and humidity values on Serial Monitor.
 * Students must complete the TODO sections.
 */
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3c
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {

    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT11 Sensor Initialized");
    if (!display.begin(SSD1306_SWITCHCAPVCC , OLED_ADDR)) {
        Serial.println("OLED NOT FOUND");
        while (true);
    }
}

void loop() {

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();  // celsius
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println("Humidity");
    display.println(humidity);
    display.println("Temperature");
    display.println(temperature);
    display.display();
    Serial.print("Humidity: ");
    Serial.println(humidity);
    Serial.print(" % | ");
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print(" C ");
    delay(2000);
}
