
// Сначало запускать этот кож для синхранизации времени на часах

#include <ThreeWire.h>
#include <RtcDS1302.h>                                
ThreeWire myWire(7,6,8);                              
RtcDS1302<ThreeWire> Rtc(myWire);

void setup () 
{
    Serial.begin(9600);                              
    Serial.print("Data: ");                          
    Serial.println(__DATE__);                       
    Serial.print("Time: ");                          
    Serial.println(__TIME__);                        
    Rtc.Begin();                                    
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__); 
    Rtc.SetDateTime(compiled);                       
    Serial.println();                                
} 

void loop () 
{
  Rtc.GetDateTime();
  RtcDateTime now = Rtc.GetDateTime();
  Serial.print("DATA RTC ");                        
  Serial.print(now.Month());                         
  Serial.print(".");                                
  Serial.print(now.Day());                           
  Serial.print(".");                                 
  Serial.print(now.Year());                           
  Serial.print(" TIME RTC ");                        
  Serial.print(now.Hour());                           
  Serial.print(":");                                 
  Serial.print(now.Minute());                         
  Serial.print(":");                                
  Serial.println(now.Second());                      
  delay(2000);                                       
}


 
//Затем кормим этот 

#include <DS1302.h> 

DS1302 rtc(8, 7, 6); // Init the DS1302

void setup()
{  
  rtc.halt(false); 
}

void loop()
{
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating :)
  delay (3000);
}