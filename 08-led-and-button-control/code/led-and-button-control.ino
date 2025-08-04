const int LED = 10; // Вывод для подключеия светодиода (D10);
const int Button = 2; // Вход для подключения кнопки (D2);

void setup() {
  pinMode(LED, OUTPUT); // Кофигурируем вывод подключения светодиода как выход.
  pinMode(Button, INPUT); // Кофигурируем вывод подключения кнопки как вход.
}

void loop() {
  int buttonState = digitalRead(Button); // Считывает состояние кнопки.
  if (buttonState) {
    digitalWrite(LED, HIGH); // Если кнопка нажата, включаем светодиод.
  } else {
    digitalWrite(LED, LOW); // Если кнопка jn;fnf, выключаем светодиод.
  }
}
