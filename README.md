# ESP32 Signal Blocker (esp32-signal-blocker-luness02)

Bu proje, hedef çevredeki kablosuz ağ trafiğini ve cihaz bağlantılarını kesintiye uğratmak (bloklamak) amacıyla geliştirilmiş gelişmiş bir ESP32 sinyal karıştırma ve paket enjeksiyon aracıdır.

## Özellikler
- **Dinamik Kanal Tarama:** 1 ile 13 arasındaki Wi-Fi kanallarını sürekli tarar.
- **Yoğun Deauth Enjeksiyonu:** Havaya ardışık deauthentication paketleri fırlatarak cihazların ağda kalmasını engeller.
- **Ham Veri Enjeksiyonu (Raw TX):** ESP-IDF alt seviye fonksiyonlarını kullanır.

## Yasal Uyarı (Disclaimer)
Bu araç yalnızca eğitim ve laboratuvar testleri amaçlıdır. Sorumluluk kullanıcıya aittir.

## Lisans
Bu proje MIT lisansı altında lisanslanmıştır. Detaylar için [LICENSE](LICENSE) dosyasına bakın.