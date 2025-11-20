#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <time.h>

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 19800; // +5:30 for India
const int   daylightOffset_sec = 0;

// ==================== CONFIGURATION ====================
const char* ssid = "JioFiber-aM6m3";
const char* password = "arzan2011";

String BOT_TOKEN = "8529559407:AAFeABkwhT7pG2zoxPWq8z2fXvhrVApFNaY";  // Your full token
String CHAT_ID = "2029841901";                 // Your chat ID

// ==================== SYSTEM VARIABLES ====================
String deviceLocation = "CSE Ground Floor Washroom";
unsigned long lastAlertTime = 0;

// Sensor values
int soundLevel = 0;
int wifiDevices = 0;
int btDevices = 0;

// ==================== SETUP ====================
void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT); // Status LED
  
  Serial.println();
  Serial.println("🚀 Campus Emergency System Starting...");
  Serial.println("=====================================");
  
  // Connect to WiFi
  connectToWiFi();
  
  // Test Telegram immediately
  testTelegram();
  
  Serial.println("\n✅ System Ready! Commands:");
  Serial.println("test     - Test Telegram");
  Serial.println("audio    - Check microphone");
  Serial.println("wifi     - Scan WiFi networks");
  Serial.println("alert    - Send emergency alert");
  Serial.println("status   - System status");
  Serial.println("=====================================\n");
}

// ==================== MAIN LOOP ====================
void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    handleCommand(command);
  }
  
  // Simulate sensor monitoring
  static unsigned long lastSensorUpdate = 0;
  if (millis() - lastSensorUpdate > 5000) {
    updateSensorReadings();
    lastSensorUpdate = millis();
    
    // Check for emergency
    checkEmergency();
  }
  
  // Blink LED
  digitalWrite(2, (millis() % 2000 < 1000) ? HIGH : LOW);
  delay(100);
}

// ==================== COMMAND HANDLER ====================
void handleCommand(String command) {
  command.toLowerCase();
  
  if (command == "test") {
    testTelegram();
  }
  else if (command == "audio") {
    checkMicrophone();
  }
  else if (command == "wifi") {
    scanWiFi();
  }
  else if (command == "alert") {
    sendEmergencyAlert();
  }
  else if (command == "status") {
    showStatus();
  }
  else if (command == "debug") {
    showDebug();
  }
  else {
    Serial.println("❓ Commands: test, audio, wifi, alert, status, debug");
  }
}

// ==================== SENSOR SIMULATION ====================
void updateSensorReadings() {
  // Simulate WiFi device count
  wifiDevices = random(3, 15);
  
  // Simulate Bluetooth devices
  btDevices = random(2, 8);
  
  // Read actual microphone
  soundLevel = analogRead(34);
  
  Serial.print("📊 Sensors - Sound:");
  Serial.print(soundLevel);
  Serial.print(" | WiFi:");
  Serial.print(wifiDevices);
  Serial.print(" | BT:");
  Serial.println(btDevices);
}

void checkEmergency() {
  int confidence = 0;
  
  if (soundLevel > 500 && soundLevel < 2500) confidence += 40;
  if (wifiDevices > 8) confidence += 30;
  if (btDevices > 4) confidence += 30;
  
  if (confidence >= 70 && (millis() - lastAlertTime > 30000)) {
    sendEmergencyAlert();
  }
}

// ==================== TELEGRAM FUNCTIONS - ULTIMATE FIX ====================
void testTelegram() {
  Serial.println("🧪 Testing Telegram connection...");
  
  String message = "🧪 TEST MESSAGE\n";
  message += "📍 Location: " + deviceLocation + "\n";
  message += "✅ ESP32 System Test\n";
  message += "🕐 Time: " + getTime() + "\n";
  message += "📡 Status: OPERATIONAL";
  
  if (sendToTelegram(message)) {
    Serial.println("✅ Telegram test PASSED - Check your bot!");
  } else {
    Serial.println("❌ Telegram test FAILED");
  }
}

void sendEmergencyAlert() {
  Serial.println("🚨 Sending emergency alert...");
  
  String message = "🚨 CAMPUS EMERGENCY 🚨\n\n";
  message += "📍 " + deviceLocation + "\n";
  message += "📊 High confidence disturbance detected\n";
  message += "🕐 " + getTime() + "\n\n";
  message += "📈 Current Readings:\n";
  message += "• Sound Level: " + String(soundLevel) + "\n";
  message += "• WiFi Devices: " + String(wifiDevices) + "\n";
  message += "• BT Devices: " + String(btDevices) + "\n\n";
  message += "⚠️ Immediate attention required!";
  
  if (sendToTelegram(message)) {
    Serial.println("✅ Emergency alert sent successfully!");
    lastAlertTime = millis();
    
    // Blink LED rapidly
    for(int i=0; i<10; i++) {
      digitalWrite(2, HIGH);
      delay(150);
      digitalWrite(2, LOW);
      delay(150);
    }
  } else {
    Serial.println("❌ Failed to send emergency alert");
  }
}

// ==================== ULTIMATE TELEGRAM FIX ====================
bool sendToTelegram(String message) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("❌ No WiFi connection");
    return false;
  }
  
  Serial.println("📤 Connecting to Telegram...");
  
  // Method 1: Try HTTPS with detailed debugging
  if (tryTelegramHTTPS(message)) {
    return true;
  }
  
  // Method 2: Try alternative approach
  Serial.println("🔄 Trying alternative method...");
  return tryTelegramAlternative(message);
}

bool tryTelegramHTTPS(String message) {
  WiFiClientSecure *client = new WiFiClientSecure;
  HTTPClient http;
  
  // Configure client
  client->setInsecure();
  client->setTimeout(10000);
  
  String url = "https://api.telegram.org/bot" + BOT_TOKEN + "/sendMessage";
  
  Serial.println("🔗 Using HTTPS method...");
  
  if (!http.begin(*client, url)) {
    Serial.println("❌ HTTP begin failed");
    delete client;
    return false;
  }
  
  http.addHeader("Content-Type", "application/json");
  
  // Simple JSON payload
  String payload = "{\"chat_id\":\"" + CHAT_ID + "\",\"text\":\"" + simpleEscape(message) + "\"}";
  
  Serial.println("📦 Sending payload...");
  
  int httpCode = http.POST(payload);
  String response = http.getString();
  
  Serial.println("📥 Response Code: " + String(httpCode));
  
  if (httpCode == 200) {
    Serial.println("✅ Telegram: Message sent via HTTPS!");
    http.end();
    delete client;
    return true;
  } else {
    Serial.println("❌ HTTPS failed: " + String(httpCode));
    if (response.length() > 0) {
      Serial.println("💡 Response: " + response);
    }
    http.end();
    delete client;
    return false;
  }
}

bool tryTelegramAlternative(String message) {
  HTTPClient http;
  WiFiClient client;
  
  // Use HTTP (not HTTPS) - some networks block HTTPS
  String base_url = "http://api.telegram.org/bot" + BOT_TOKEN;
  String full_url = base_url + "/sendMessage?chat_id=" + CHAT_ID + "&text=" + urlEncode(message);
  
  Serial.println("🔄 Using HTTP alternative...");
  Serial.println("🔗 URL: " + base_url + "/sendMessage?chat_id=" + CHAT_ID + "&text=[message]");
  
  if (!http.begin(client, full_url)) {
    Serial.println("❌ Alternative HTTP begin failed");
    return false;
  }
  
  int httpCode = http.GET();
  String response = http.getString();
  
  Serial.println("📥 Alt Response: " + String(httpCode));
  
  if (httpCode == 200) {
    Serial.println("✅ Alternative method worked!");
    http.end();
    return true;
  } else if (httpCode == 301) {
    Serial.println("ℹ️ HTTP redirected to HTTPS - network requires secure connection");
  } else {
    Serial.println("❌ Alternative failed: " + String(httpCode));
  }
  
  http.end();
  return false;
}

String simpleEscape(String input) {
  String output = "";
  for (int i = 0; i < input.length(); i++) {
    char c = input[i];
    if (c == '\"') output += "\\\"";
    else if (c == '\n') output += "\\n";
    else output += c;
  }
  return output;
}

String urlEncode(String str) {
  String encoded = "";
  for (int i = 0; i < str.length(); i++) {
    char c = str[i];
    if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
      encoded += c;
    } else if (c == ' ') {
      encoded += "%20";
    } else if (c == '\n') {
      encoded += "%0A";
    } else {
      encoded += "%" + String(c, HEX);
    }
  }
  return encoded;
}

// ==================== WIFI CONNECTION ====================
void connectToWiFi() {
  Serial.print("📡 Connecting to WiFi: ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 30) {
    delay(500);
    Serial.print(".");
    attempts++;
    if (attempts % 10 == 0) Serial.println();
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi Connected!");
    Serial.println("📶 IP: " + WiFi.localIP().toString());
    Serial.println("📡 RSSI: " + String(WiFi.RSSI()) + " dBm");
  } else {
    Serial.println("\n❌ WiFi Failed!");
    Serial.println("💡 Check: SSID, password, and signal strength");
  }
}

// ==================== MICROPHONE CHECK ====================
void checkMicrophone() {
  Serial.println("\n🎤 MICROPHONE DIAGNOSTIC");
  Serial.println("======================");
  
  Serial.println("📊 Reading microphone on GPIO 34...");
  
  int readings[10];
  int sum = 0;
  
  for (int i = 0; i < 10; i++) {
    readings[i] = analogRead(34);
    sum += readings[i];
    Serial.println("  Reading " + String(i+1) + ": " + String(readings[i]));
    delay(300);
  }
  
  int average = sum / 10;
  Serial.println("📈 Average: " + String(average));
  
  // Analyze the readings
  if (average == 0) {
    Serial.println("❌ PROBLEM: Microphone reading 0");
    Serial.println("💡 SOLUTION: Check wiring - OUT pin to GPIO 34");
  }
  else if (average > 2500) {
    Serial.println("❌ PROBLEM: Microphone reading >2500 (floating pin)");
    Serial.println("💡 SOLUTION: Ensure proper GND connection");
  }
  else if (average < 100) {
    Serial.println("⚠️  Microphone very quiet (normal for quiet room)");
  }
  else if (average >= 100 && average <= 1000) {
    Serial.println("✅ Microphone working normally");
  }
  else {
    Serial.println("📢 Microphone detecting sound");
  }
  
  Serial.println("💡 Expected range: 100-800 (normal), 0 or >2500 = wiring issue");
  Serial.println("======================");
}

// ==================== WIFI SCAN ====================
void scanWiFi() {
  Serial.println("\n📡 SCANNING WiFi NETWORKS");
  Serial.println("========================");
  
  int n = WiFi.scanNetworks();
  if (n == 0) {
    Serial.println("❌ No networks found");
  } else {
    Serial.println("📶 Found " + String(n) + " networks:");
    for (int i = 0; i < n; ++i) {
      Serial.printf("   %d: %s (%ddBm) Ch%d\n", 
                   i+1, WiFi.SSID(i).c_str(), WiFi.RSSI(i), WiFi.channel(i));
    }
  }
  Serial.println("========================");
}

// ==================== UTILITY FUNCTIONS ====================
void showStatus() {
  Serial.println("\n📊 SYSTEM STATUS");
  Serial.println("================");
  Serial.println("📍 " + deviceLocation);
  Serial.println("📶 WiFi: " + String(WiFi.status() == WL_CONNECTED ? "✅ Connected" : "❌ Disconnected"));
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("📡 IP: " + WiFi.localIP().toString());
  }
  Serial.println("🎤 Sound: " + String(soundLevel));
  Serial.println("📡 WiFi Devices: " + String(wifiDevices));
  Serial.println("📱 BT Devices: " + String(btDevices));
  Serial.println("================");
}

void showDebug() {
  Serial.println("\n🔍 DEBUG INFORMATION");
  Serial.println("===================");
  Serial.println("WiFi Status: " + String(WiFi.status()));
  Serial.println("RSSI: " + String(WiFi.RSSI()) + " dBm");
  Serial.println("Bot Token: " + BOT_TOKEN.substring(0, 20) + "...");
  Serial.println("Chat ID: " + CHAT_ID);
  Serial.println("Free Memory: " + String(esp_get_free_heap_size()) + " bytes");
  Serial.println("===================");
}

String getTime() {
  unsigned long sec = millis() / 1000;
  unsigned long min = sec / 60;
  unsigned long hr = min / 60;
  return String(hr % 24) + ":" + String(min % 60) + ":" + String(sec % 60);
}