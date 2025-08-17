#define Trig 9 // Пин для отправки ультразвукового импульса.
#define Echo 8 // Пин для приема отраженного сигнала.

void setup() {
  // Настройка пинов.
  pinMode(Trig, OUTPUT); // Пин Trig настроен как выход (отправка сигнала).
  pinMode(Echo, INPUT); // Пин Echo настроен как вход (прием сигнала).
  Serial.begin(9600); // Скорость передачи.
}

void loop() {
  // Генерация ультразвукового импульса.
  digitalWrite(Trig, HIGH); // Подаем высокий уровень на Trig.
  delayMicroseconds(10);
  digitalWrite(Trig, LOW); // Возвращаем низкий уровень.

  // Измерение длительности отраженного импульса.
  unsigned int impulse = pulseIn(Echo, HIGH); // Замеряем длительность высокого уровня на пине Echo.
  unsigned int distance = impulse / 58;
  Serial.println(distance); // Отправляем расстояние в монитор порта.
  delay(1000); // Ждем 1 секунду перед следующим измерением.
}
