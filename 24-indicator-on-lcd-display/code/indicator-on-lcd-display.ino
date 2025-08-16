#include <LiquidCrystal.h>

// Инициализация объекта LiquidCrystal: RS, E, DB4, DB5, DB6, DB7.
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

void setup() {
  // Установка количества столбцов и строк ЖК-дисплея:
  lcd.begin(16, 2);

  // Текст для вывода.
  String line1 = "Hello!!!";
  String line2 = "Sinardcom";

  // Вычисление позиции для центрирования текста.
  int position1 = (16 - line1.length()) / 2;
  int position2 = (16 - line2.length()) / 2;

  // Вывод текста на первой строке по центру:
  lcd.setCursor(position2, 1);
  lcd.print(line2);
}

void loop() {
  // Здесь ничего не происходит, текст статичен.
}
