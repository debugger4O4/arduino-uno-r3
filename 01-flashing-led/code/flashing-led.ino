int led = 12; // Контакт 12 подключен к светдиоду через резистор.

void setup() {
  pinMode(led, OUTPUT); // Инициализация цифрового вывода как выход.
}

void loop() {
  digitalWrite(led, HIGH); // Включить светодиод.
  delay(100); // Подождать 100мс.
  digitalWrite(led, LOW); // Выключить светодиод.
  delay(100); // Подождать 100мс.
}
