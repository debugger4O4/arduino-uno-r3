#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Ds1302.h>

// Инициализация DHT11.
#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Пины для RTC DS1302.
#define RTC_RST 10
#define RTC_DAT 11
#define RTC_CLK 13

// Инициализация RTC DS1302.
Ds1302::DateTime t;
Ds1302 rtc(RTC_RST, RTC_CLK, RTC_DAT);

// Инициализация LCD дисплея.
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Массивы для преобразования чисел в строки.
const char* months[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

const char* daysOfWeek[] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

void setup() {
  Serial.begin(9600);
  Wire.begin();
  dht.begin();
  rtc.init();
  lcd.init();
  lcd.backlight();

  if (rtc.isHalted()) {
    Serial.println("RTC остановлен. Установка времени...");
    
    // Используем числовые значения вместо перечислений.
    Ds1302::DateTime dt = {
        .year = 25,     // 2025 год.
        .month = 5,      // Май (1-12).
        .day = 28,       // 28 число.
        .hour = 17,      // 21 часов.
        .minute = 22,     // 22 минут.
        .second = 0,    // 0 секунд.
        .dow = 4        // Вторник (1=воскресенье, 2=понедельник, 3=вторник и т.д.).
    };
    
    rtc.setDateTime(&dt);
  }
}

void loop() {
  // Получение данных с датчиков.
  rtc.getDateTime(&t);
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Проверка на ошибки чтения DHT11
  if (isnan(temp) || isnan(humidity)) {
    temp = 0;
    humidity = 0;
  }

  // Формирование строки с датой и временем.
  char dateTimeStr[17];
  sprintf(dateTimeStr, "%02d-%s-%02d %02d:%02d", 
          t.day, 
          months[t.month - 1], // Месяц (1-12 -> 0-11)
          t.year, 
          t.hour, 
          t.minute);

  // Формирование строки статуса.
  char statusStr[17];
  sprintf(statusStr, "%-3s %2dC %2d%%", 
          daysOfWeek[t.dow - 1], // День недели (1-7 -> 0-6)
          (int)temp, 
          (int)humidity);

  // Вывод на LCD.
  lcd.setCursor(0, 0);
  lcd.print(dateTimeStr);
  lcd.setCursor(0, 1);
  lcd.print(statusStr);

  delay(1000);
}
