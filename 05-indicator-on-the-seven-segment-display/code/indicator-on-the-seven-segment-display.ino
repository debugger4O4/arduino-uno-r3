const int ledA = 3; // Сегмент А.
const int ledB = 2; // Сегмент B.
const int ledC = 4; // Сегмент C.
const int ledD = 5; // Сегмент D.
const int ledE = 6; // Сегмент E.
const int ledF = 8; // Сегмент F.
const int ledG = 7; // Сегмент G.

void setup() {
  // Настройка выводов как выходов для управления сегментами индикатора.
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop() {
  int i = 200; // Время задержки в миллисекундах.

  // Последовательное включение и выключение сегментов индикатора.
  digitalWrite(ledA, HIGH); // Включение сегмента А.
  delay(i); // Задержка.
  digitalWrite(ledA, LOW); // Выключение сегмента А.
  delay(i); // Задержка.

  digitalWrite(ledB, HIGH); // Включение сегмента B.
  delay(i); // Задержка.
  digitalWrite(ledB, LOW); // Выключение сегмента B.
  delay(i); // Задержка.

  digitalWrite(ledC, HIGH); // Включение сегмента C.
  delay(i); // Задержка.
  digitalWrite(ledC, LOW); // Выключение сегмента C.
  delay(i); // Задержка.

  digitalWrite(ledD, HIGH); // Включение сегмента D.
  delay(i); // Задержка.
  digitalWrite(ledD, LOW); // Выключение сегмента D.
  delay(i); // Задержка.

  digitalWrite(ledE, HIGH); // Включение сегмента E.
  delay(i); // Задержка.
  digitalWrite(ledE, LOW); // Выключение сегмента E.
  delay(i); // Задержка.

  digitalWrite(ledF, HIGH); // Включение сегмента F.
  delay(i); // Задержка.
  digitalWrite(ledF, LOW); // Выключение сегмента F.
  delay(i); // Задержка.

  digitalWrite(ledG, HIGH); // Включение сегмента G.
  delay(i); // Задержка.
  digitalWrite(ledG, LOW); // Выключение сегмента G.
  delay(i); // Задержка.
}
