#include <HardwareSerial.h>

// Definicja pinów UART dla XIAO ESP32C6 (GPIO pins not work for me! This use hardware UART! Sometimes you have to disconnect one of the pins when uploading a sketch.)
#define RX_PIN D7
#define TX_PIN D6

void setup() {
  // Inicjalizacja monitora szeregowego dla debugowania
  Serial.begin(115200);
  // Inicjalizacja UART dla GPS NEO-6M (9600 baud, domyślna prędkość NEO-6M)
  Serial1.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
  
  Serial.println("Starting GPS data receiver...");
}

void loop() {
  // Odczyt danych z GPS i przesyłanie do monitora szeregowego
  if (Serial1.available()) {
    String gpsData = Serial1.readStringUntil('\n');
    Serial.println(gpsData); // Wyświetlenie surowych danych NMEA
  }
}
