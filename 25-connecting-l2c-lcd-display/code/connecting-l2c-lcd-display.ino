#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Адрес 0х27 для I2C.

void setup() {
  lcd.init(); // Инициализация ЖК-дисплея.
  lcd.backlight(); // Включение подсветки.
  lcd.setCursor(4, 0); // Установка курсора в позицию (4, 0).
  lcd.print("Hello!!!"); // Вывод "Hello!!!" по центру первой строки.
}

void loop() {
  const char *text = "Sinardcom";
  int textLength = strlen(text);
  int maxPosition = 16 - textLength; // Максимальное смещение текста.
  for (int position = 0; position <= maxPosition; position++) {
    lcd.setCursor(position, 1); // Установка курсора в позицию (position, 1). 
    lcd.print(text); // Вывод "Sinardcom".
    delay(300); // Задержка для плавности движения.
    lcd.clear(); // Очистка экрана для следующего кадра.
    lcd.setCursor(4, 0); // Вывод "Hello!!!" по центру первой строки.
    lcd.print("Hello!!!");
  }
  for (int position = maxPosition; position >= 0; position--) {
    lcd.setCursor(position, 1); // Установка курсора в позицию (position, 1). 
    lcd.print(text); // Вывод "Sinardcom".
    delay(300); // Задержка для плавности движения.
    lcd.clear(); // Очистка экрана для следующего кадра.
    lcd.setCursor(4, 0); // Вывод "Hello!!!" по центру первой строки.
    lcd.print("Hello!!!");
  }
}
