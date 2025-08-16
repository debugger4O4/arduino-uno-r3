#include <Ds1302.h>

/* Экземпляр DS1302 RTC.
   Инициализация DS1302 RTC с следующими подключениями:
   Arduino D10 к RTC RST (Сброс);
   Arduino D13 к RTC CLK (Часы);
   Arduino D11 к RTC DAT (Данные).
*/
Ds1302 rtc(10, 13, 11);

// Массив строк, представляющих дни недели.
const static char* WeekDays[] =
{
    "Понедельник",
    "Вторник",
    "Среда",
    "Четверг",
    "Пятница",
    "Суббота",
    "Воскресенье"
};

// Массив строк, представляющих месяцы.
const static char* Months[] =
{
    "Январь",
    "Февраль",
    "Март",
    "Апрель",
    "Май",
    "Июнь",
    "Июль",
    "Август",
    "Сентябрь",
    "Октябрь",
    "Ноябрь",
    "Декабрь"
};

// Функция setup запускается один раз при нажатии кнопки сброса или подаче питания на плату.
void setup()
{
    // Начать серийную связь со скоростью 9600 бит в секунду.
    Serial.begin(9600);

    // Инициализировать RTC
    rtc.init();

    // Проверить, остановлен ли RTC, и если да, то установить время.
    if (rtc.isHalted())
    {
        Serial.println("RTC остановлен. Установка времени...");

        // Установить RTC на определенную дату и время.
        Ds1302::DateTime dt = {
            .year = 25,         // Год (00-99)
            .month = 5,         // Месяц (1-12)
            .day = 28,          // День месяца (1-31)
            .hour = 16,         // Час дня (0-23)
            .minute = 31,       // Минута (0-59)
            .second = 0,        // Секунда (0-59)
            .dow = 3            // День недели (1-7), 3 = Среда
        };

        // Установить дату и время на RTC.
        rtc.setDateTime(&dt);
    }
}

// Функция loop выполняется снова и снова бесконечно.
void loop()
{
    // Получить текущее время от RTC.
    Ds1302::DateTime now;
    rtc.getDateTime(&now);

    // Отслеживать последнюю обработанную секунду.
    static uint8_t last_second = 0;
    if (last_second != now.second)
    {
        last_second = now.second;

        // Вывести текущую дату и время на серийный монитор.
        Serial.print("20"); // Префикс для года, чтобы сделать его четырехзначным.
        Serial.print(now.year); // Вывести год (00-99).
        Serial.print('-');
        if (now.month < 10) Serial.print('0'); // Вывести ведущий ноль для месяца.
        Serial.print(now.month); // Вывести месяц (1-12).
        Serial.print('-');
        if (now.day < 10) Serial.print('0'); // Вывести ведущий ноль для дня.
        Serial.print(now.day); // Вывести день (1-31).
        Serial.print(' ');
        Serial.print(WeekDays[now.dow - 1]); // Вывести день недели (0-6).
        Serial.print(' ');
        if (now.hour < 10) Serial.print('0'); // Вывести ведущий ноль для часа.
        Serial.print(now.hour); // Вывести час (00-23).
        Serial.print(':');
        if (now.minute < 10) Serial.print('0'); // Вывести ведущий ноль для минуты.
        Serial.print(now.minute); // Вывести минуту (00-59).
        Serial.print(':');
        if (now.second < 10) Serial.print('0'); // Вывести ведущий ноль для секунды.
        Serial.print(now.second); // Вывести секунду (00-59).
        Serial.println(); // Закончить строку.
    }
}
