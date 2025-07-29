int r = 2; // Контакт 2 красный.
int g = 3; // Контакт 3 зеленый.
int b = 4; // Контакт 4 голубой.

void setup() {
  // Инициализация цифровых выводов как выходы.
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  digitalWrite(r, HIGH); // Включаем красный.
  delay(500); // Ждем 500 Мс.
  digitalWrite(r, LOW); // Включаем красный.
  digitalWrite(g, HIGH); // Включаем красный.
  delay(500); // Ждем 500 Мс.
  digitalWrite(g, LOW); // Включаем красный.
  digitalWrite(b, HIGH); // Включаем голубой.
  delay(500); // Ждем 500 Мс.
  digitalWrite(b, LOW); // Выключаем голубой.
}
