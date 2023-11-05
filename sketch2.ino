#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DS1302.h> 

LiquidCrystal_I2C lcd(0x27,16,2);                                    // SDA and SLA        
DS1302 rtc(8, 7, 6); // Init the DS1302


void setup () 
{
    rtc.halt(false); 
    lcd.init();                                                      //  Инициируем работу с LCD дисплеем
    lcd.backlight();                                                 //  Включаем подсветку LCD дисплея
    
}  

void loop () 
{
  lcd.setCursor(0, 0);
  lcd.print(rtc.getDateStr());
  lcd.print(" ");    
  lcd.print(rtc.getTimeStr());                       
  delay (5000);
}               