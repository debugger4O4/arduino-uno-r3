// Выводы, подключенные к датчику.
#define sensorPower 7
#define sensorPin A0

// Переменная для хранения уровня воды.
int val = 0;

void setup() {
  // Настраиваем D7 на выход.
  pinMode(sensorPower, OUTPUT);

  // Устанавливаем низкий уровень, чтобы на датчик не подавалось питание.
  digitalWrite(sensorPower, LOW);

  Serial.begin(9600);
}

void loop() {
  // Получить показания из функции ниже и напечатать его.
  int level = readSensor();

  Serial.print("Water level: ");
  Serial.println(level);
  delay(1000);
}

// Данная функция используется для получения показаний.
int readSensor() {
  digitalWrite(sensorPower, HIGH); // Включить датчик.
  delay(10); // Ждать 10 миллисекунд.
  int val = analogRead(sensorPin); // Прочитать аналоговое значение от датчика.
  digitalWrite(sensorPower, LOW); // Выключить датчик.
  return val;
}
