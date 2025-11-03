#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <time.h>

const char* ssid = "SEU_WIFI";
const char* password = "SUA_SENHA";
const char* tagoServer = "https://api.tago.io/data";
const char* deviceToken = "SEU_DEVICE_TOKEN";

const int FLOW_PIN = 2;
const int LEAK_PIN = 4;
const int RELAY_PIN = 5;

volatile int flowPulses = 0;
float flowRate = 0.0;
float totalUsage = 0.0;
unsigned long oldTime = 0;
bool leakDetected = false;
bool valveOpen = true;
unsigned long leakTime = 0;

void IRAM_ATTR pulseCounter() { flowPulses++; }

void setup() {
  Serial.begin(115200);
  pinMode(FLOW_PIN, INPUT_PULLUP);
  pinMode(LEAK_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  attachInterrupt(digitalPinToInterrupt(FLOW_PIN), pulseCounter, FALLING);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(1000);
  Serial.println("Wi-Fi OK!");
  configTime(0, 0, "pool.ntp.org");
}

void loop() {
  if ((millis() - oldTime) > 1000) {
    detachInterrupt(digitalPinToInterrupt(FLOW_PIN));
    flowRate = ((1000.0 / (millis() - oldTime)) * flowPulses) / 450.0;
    totalUsage += (flowRate * (millis() - oldTime) / 1000.0) / 60.0;
    oldTime = millis();
    flowPulses = 0;
    attachInterrupt(digitalPinToInterrupt(FLOW_PIN), pulseCounter, FALLING);
  }

  int leakValue = analogRead(LEAK_PIN);
  if (leakValue > 2000 && !leakDetected) {
    leakDetected = true;
    leakTime = millis();
    valveOpen = false;
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("VAZAMENTO! Válvula fechada.");
  }

  if (leakDetected && (millis() - leakTime > 300000)) {
    leakDetected = false;
    valveOpen = true;
    digitalWrite(RELAY_PIN, HIGH);
  }

  if (WiFi.status() == WL_CONNECTED && (millis() % 30000 < 1000)) {
    sendToTagoIO();
  }
  delay(500);
}

void sendToTagoIO() {
  HTTPClient http;
  http.begin(tagoServer);
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Device-Token", deviceToken);

  DynamicJsonDocument doc(1024);
  time_t now; time(&now);
  doc["variable"] = "flow_rate"; doc["value"] = flowRate; doc["unit"] = "L/min"; doc["time"] = now;
  String payload; serializeJson(doc, payload);
  http.POST(payload);
  http.end();
}
