#include <SPI.h>
#include <MFRC522.h>

#define RELAY_PIN 6 // Вывод для управления реле.
#define RELAY_ON 1  // Уровень для включения реле.
#define RELAY_OFF 0 // Уровень для выключения реле.

#define RST_PIN 7   // Вывод RST для RFID-модуля.
#define SS_PIN 10   // Вывод SS для RFID-модуля.
MFRC522 mfrc522(SS_PIN, RST_PIN); // Создание экземпляра MFRC522.

void setup() {
  Serial.begin(9600); // Инициализация последовательного порта.
  SPI.begin();        // Инициализация SPI.
  mfrc522.PCD_Init(); // Инициализация MFRC522.
  pinMode(RELAY_PIN, OUTPUT); // Настройка вывода реле как выход.
  digitalWrite(RELAY_PIN, RELAY_OFF); // Выключение реле.
}

void loop() {
  // Проверка наличия новой RFID-карты.
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Сравнение UID карты с разрешенными значениями.
    if (compare_uid(mfrc522.uid.uidByte, mfrc522.uid.size)) {
      digitalWrite(RELAY_PIN, RELAY_ON); // Включение реле.
      delay(4000); // Время активации реле.
      digitalWrite(RELAY_PIN, RELAY_OFF); // Выключение реле.
    }
  }
}

// Функция сравнения UID.
boolean compare_uid(byte *buffer, byte bufferSize) {
  // Разрешённые UID карт! UID можно узнать из урока “Считыватель RFID-карт”.
  byte allowedUid1[] = {0xA3, 0xD6, 0x85, 0x34}; // Первая карта.
  byte allowedUid2[] = {0xD3, 0xD1, 0xFD, 0xF6}; // Вторая карта.
  
  // Проверка первой карты.
  if (bufferSize == sizeof(allowedUid1)) {
    bool match = true;
    for (byte i = 0; i < bufferSize; i++) {
      if (buffer[i] != allowedUid1[i]) {
        match = false;
        break;
      }
    }
    if (match) return true;
  }
  
  // Проверка второй карты.
  if (bufferSize == sizeof(allowedUid2)) {
    bool match = true;
    for (byte i = 0; i < bufferSize; i++) {
      if (buffer[i] != allowedUid2[i]) {
        match = false;
        break;
      }
    }
    if (match) return true;
  }
  
  return false; // Если ни одна карта не совпала.
}
