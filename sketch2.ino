#include <LiquidCrystal_I2C.h>
#include <DS1302.h> 
#include <dht.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
DS1302 rtc(8, 7, 6);
dht DHT;
#define DHT11_PIN 5

int r = 13;
int g = 12;
int b = 11;

void setup()
{
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  rtc.halt(false);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print(rtc.getDateStr());
  lcd.print(" ");
  lcd.print(rtc.getTimeStr());
  delay(5000);
  lcd.setCursor(0, 1);
  int chk = DHT.read11(DHT11_PIN);
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C  ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  if (DHT.humidity > 60.00)
  {
    digitalWrite(b, LOW); 
    digitalWrite(g, HIGH); //включаем красный;
  }
  else
  {
    digitalWrite(g, LOW);
    digitalWrite(b, HIGH);
  }
  delay(5000);
  
  
}
