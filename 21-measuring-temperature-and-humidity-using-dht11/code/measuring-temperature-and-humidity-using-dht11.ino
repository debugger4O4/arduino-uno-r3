#include <DHT.h>

// Инициализация DHT11.
#define DHTPIN 2 // Пин, к которому подключен датчик DHT11.
#define DHTTYPE DHT11 // Используемый тип датчика DHT11.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // Инициализация серийного порта.
  dht.begin(); // Запуск датчика DHT11.
}

void loop() {
  // Чтение влажности и температуры.
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Проверка, удалось ли считать показания с датчика.
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Не удалось считать данные с датчика DHT11.");
    return;
  }

  // Вывод показаний влажности и температуры в консоль.
  Serial.println("Влажность: " + humidity + "%\t" + "Температура: " + temperature + "°C");
}
