#define sensorPin 7

// Переменная для хранения времени, когда произошло последнее событие.
unsigned long lastEvent = 0;

void setup() {
  // Настраиваем вывод, к которому подключен датчик, как вход.
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Прочитать показания датчика.
  int sensorData = digitalRead(sensorPin);

  // Если на вывод подан низкий логический уровень, то звук обнаружен.
  if (sensorData == LOW) {
    /*
     * Если прошло 25 мс с момента последнего состояния низкого логического уровня
     * это значит, что обнаружен хлопок, а не какие-либо ложные звуки.
     */
     if (millis() - lastEvent > 25) {
      Serial.println("Clap detected!");
     }

     // Запомнить, когда произошло последнее событие.
     lastEvent = millis();
  }
}
