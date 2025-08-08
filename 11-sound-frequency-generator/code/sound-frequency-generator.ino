int buzzer = 11; // Пин 11 подключен к пьезоизлучателю.

void setup() {
  pinMode(buzzer, OUTPUT); // Инициализация цифрового вывода как выход.
}

void loop() {
  unsigned char i, j; // Задаем переменные.
  while (1) { // Бесконечный цикл.
    for (int i = 1; i < 80; i++) { // Первая частота звука.
      digitalWrite(buzzer, HIGH); // Пьезоизлучатель издает звук.
      delay(1); // Задержка 1 мс.
      digitalWrite(buzzer, LOW); // Пьезоизлучатель издает звук.
      delay(1); // Задержка 1 мс.
    }
    for (int i = 0; i < 100; i++) { // Вторая частота звука.
      digitalWrite(buzzer, HIGH); // Пьезоизлучатель издает звук.
      delay(2); // Задержка 2 мс.
      digitalWrite(buzzer, LOW); // Пьезоизлучатель издает звук.
      delay(2); // Задержка 2 мс.
    }
  }
}
