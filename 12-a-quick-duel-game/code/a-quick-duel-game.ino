#define BUZZER_PIN 12 // Пин с пищалкой 12.
#define PLAYER_COUNT 2 // Количество игроков-ковбоев.
/* 
 *  Вместо перечисления всех пинов по-одному, мы объявляем пару
 *  списков: один с номерамипинов с кнопками, другой -- со светодиодами.
 *  Списки таже называют массивами (англ. array).
 *  
 */
 int buttonPins[PLAYER_COUNT] = {3, 13};
 int ledPins[PLAYER_COUNT] = {9, 11};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  for (int player = 0; player < PLAYER_COUNT; ++player) {
    /*
     * При помощи квадратных скобок получают значение в массиве под указанным
     * в них номером. Нумерация начинается с нуля.
     */
     pinMode(ledPins[player], OUTPUT);
     pinMode(buttonPins[player], INPUT_PULLUP);
  }
}

void loop() {
  // Даём сигнал "пли!", выждав случайное время от 2 до 7 сек.
  delay(random(2000, 7000));
  tone(BUZZER_PIN, 3000, 250); // 3 килогерца, 250 миллисекунд.
  for (int player = 0; ; player = (player + 1) % PLAYER_COUNT) {
    // Если игрок номер "player" нажал кнопку...
    if (!digitalRead(buttonPins[player])) {
      // ...включаем его светодиод и сигналы победы на 1 сек.
      digitalWrite(ledPins[player], HIGH);
      tone(BUZZER_PIN, 4000, 1000);
      delay(1000);
      digitalWrite(ledPins[player], LOW);
      break; // Есть победитель! Выходим (англ. break) из цикла.
    }
  }
}
