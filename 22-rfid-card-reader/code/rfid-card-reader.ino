// Подключение библиотек.
#include <SPI.h>
#include <MFRC522.h>

// Константы подключения контактов SS и RST.
#define RST_PIN 7 // Внимание: здесь должен быть D7 вместо 9.
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN); // Создание экземпляра MFRC522.

void setup() {
  Serial.begin(9600); // Инициализация последовательного порта.\
  SPI.begin(); // Инициализация SPI.
  mfrc522.PCD_Init(); // Инициализация MFRC522.
}

void loop() {
  // Проверка наличия новой RFID-карты.
  if (!mfrc522.PICC_IsNewCardPresent())
    return;
  // Чтение информации с RFID-карты.
  if (!mfrc522.PICC_ReadCardSerial())
    return;
  // Вывод UID карты.
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();
  // Вывод типа карты.
  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  Serial.println(mfrc522.PICC_GetTypeName(piccType));
  // Задержка перед следующим считыванием.
  delay(2000);
}
