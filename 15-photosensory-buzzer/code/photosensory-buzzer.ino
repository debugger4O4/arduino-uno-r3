// Определение номеров контактов для зуммера и фоторезистора.
#define buzzerPin 5 // Номер контакта зуммера.
#define photoPin A3 // Номер контакта фоторезистора.

// Переменнык для хранения значений.
int aVal; // Значение на фоторезисторе.
int sMax = 1023; // Максиальное значение фоторезистора (10-битный АЦП Arduino).
int buzzerFreq; // Частота звука.
const long BUZZ_FREQ_MAX = 2500; // Задаем максимальную частоту излучения.


void setup() {
  pinMode(buzzerPin, OUTPUT); // Установка контакта зуммера как выход.
  Serial.begin(9600); // Инициализация последовательного порта для отладки.
}

void loop() {
  aVal = analogRead(photoPin); // Считываем аналоговое значение с фоторезистора.
  Serial.print("aVal: " + aVal); // Выводим значение в монитор порта.
  buzzerFreq = (aVal * BUZZ_FREQ_MAX) / sMax; // Расчет частоты для зуммера.
  buzz(buzzerPin, buzzerFreq, 10); // Генерация звука на зуммере.
}

// Функция для генерации звука заданной частоты и продолжительности.
void buzz (int targetPin, long frequency, long length) {
   long delayValue = 1000000 / frequency / 2; // Расчет времени задержки для полуволны.
   long numCycles = frequency * length / 1000; // Расчет количества циклов звука.

   // Генерация звукового сигнала.
   for (long i = 0; i < numCycles; i++) {
    digitalWrite(targetPin, HIGH); // Включение пина.
    delayMicroseconds(delayValue); // Задержка для создания полуволны.
    digitalWrite(targetPin, LOW); // Выключение пина.
    delayMicroseconds(delayValue); // Задержка для создания полуволны.
   }
}
