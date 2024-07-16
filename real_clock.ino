#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// LCD setup (address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C LCD(0x27, 16, 2);

// Replace with your network credentials
const char* ssid = "Bharath Reddy...";
const char* password = "123456789";

// NTP server details
#define NTP_SERVER "pool.ntp.org"
#define UTC_OFFSET 19800 // Offset for IST (UTC+5:30)

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_SERVER, UTC_OFFSET);

void setup() {
  Serial.begin(115200);

  LCD.init(); // Initialize the LCD
  LCD.backlight(); // Turn on the LCD backlight
  LCD.setCursor(0, 0);
  LCD.print("Connecting to ");
  LCD.setCursor(0, 1);
  LCD.print("WiFi ");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    spinner();
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  LCD.clear();
  LCD.setCursor(0, 0);
  LCD.print("Online");
  LCD.setCursor(0, 1);
  LCD.print("Updating time...");

  timeClient.begin();
  timeClient.setTimeOffset(UTC_OFFSET);
}

void loop() {
  printLocalTime();
  delay(1000); // Update every second
}

void printLocalTime() {
  timeClient.update();
  time_t rawTime = timeClient.getEpochTime();
  struct tm* timeinfo = localtime(&rawTime);

  char timeStr[9]; // Buffer for "HH:MM:SS\0"
  snprintf(timeStr, sizeof(timeStr), "%02d:%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

  char dateStr[11]; // Buffer for "DD/MM/YYYY\0"
  snprintf(dateStr, sizeof(dateStr), "%02d/%02d/%04d", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);

  LCD.setCursor(0, 0);
  LCD.print(timeStr); // Print time on the first row
  LCD.setCursor(0, 1);
  LCD.print(dateStr); // Print date on the second row

  // Also print to Serial Monitor
  Serial.println(timeStr);
  Serial.println(dateStr);
}

void spinner() {
  static int8_t counter = 0;
  const char* glyphs = "\xa1\xa5\xdb";
  LCD.setCursor(15, 1);
  LCD.print(glyphs[counter++]);
  if (counter == strlen(glyphs)) {
    counter = 0;
  }
}
