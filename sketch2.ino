#include <ThreeWire.h>                                // Подключаем библиотеку ThreeWire
#include <RtcDS1302.h>// Подключаем библиотеку RtcDS1302
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

ThreeWire myWire(7,6,8);                              // Указываем вывода IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);


void setup () 
{
    Serial.begin(9600);                              // Установка последовательной связи на скорости 9600
    Serial.println(__DATE__);                        // Получение даты и времени с ПК
    Serial.println(__TIME__);                        // Получение даты и времени с ПК
    Rtc.Begin();                                     // Инициализация RTC
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__); // Копирование даты и времени в compiled
    Rtc.SetDateTime(compiled);                       // Установка времени
    Serial.println();
    lcd.init();                       //  Инициируем работу с LCD дисплеем
    lcd.backlight();                  //  Включаем подсветку LCD дисплея
    
}  

void loop () 
{
  Rtc.GetDateTime();
  RtcDateTime now = Rtc.GetDateTime();
  lcd.setCursor(0, 0);
  lcd.print(now.Day());
  lcd.print(".");
  lcd.print(now.Month());
  lcd.print(".");         
  lcd.print(now.Year());
  lcd.print(" ");
  lcd.print(now.Hour());                          
  lcd.print(":");                             
  lcd.print(now.Minute());                        
  delay (5000);
}               