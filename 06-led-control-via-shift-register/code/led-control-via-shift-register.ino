// Определение номеров пинов Arduino, подключенных к микросхеме 74HC595.
int latchPin = 8; // Пин, подключенный к ST_CP (RCLK) регистра сдвига. Управляет записью данных.
int clockPin = 12; // Пин, подключенный к SH_CP (SRCLK) регистра сдвига. Синхронизирует передачу.
int dataPin = 11; // Пин, подключенный к DS (DATA) регистра сдвига. Передает биты данных.

void setup() {
  // Настраиваем пины микроконтроллера как выходы.
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  // Инициализируем последовательное соединение для отладки.
  Serial.begin(9600);
}

void loop() {
  // Перебираем числа от 0 до 255 для отображения на светодиодах.
  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
    // Выводим текущее число в последовательный порт.
    Serial.print(numberToDisplay);
    Serial.print(" => ");
    // Выводим двоичное представление числа.
    Serial.println(numberToDisplay, BIN);
    
    // Опускаем latchPin перед началом передачи данных.
    digitalWrite(latchPin, LOW);
    // Отправляем биты в регистр сдвига.
    shiftOut(dataPin, clockPin, LSBFIRST, numberToDisplay); // Последовательно отправляет биты.
    // Поднимаем latchPin после передачи данных для активации выходов регистра сдвига.
    digitalWrite(latchPin, HIGH);
    
    // Задержка между обновлениями светодиодов.
    delay(1000);
  }
}
