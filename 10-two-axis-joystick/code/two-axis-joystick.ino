const int axisX = A0; // Ось X подключена к A0.
const int axisY = A1; // Ось Y подключена к A1.
const int buttonPin = 7; // Кнопка джойстика подключена к D7.
int valX, valY, valButton = 0; // Переменые для хранения значений осей и кнопки.

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Конфигурируем D7 как INPUT с включением подтягивающего резистора.
  Serial.begin(9600);
}

void loop() {
  valX = analogRead(axisX); // Значение оси X.
  valY = analogRead(axisY); // Значение оси Y.
  valButton = 1 - digitalRead(buttonPin); // Значение кнопки (инвертированное).
  // Выводим значения в монитор порта.
  Serial.print("X:");
  Serial.print(valX, DEC);
  Serial.print("    |   Y:");
  Serial.print(valY, DEC);
  Serial.print("    |   Button:   ");
  Serial.print(valButton, DEC);
  delay(500);
}
