#include <DS3231.h>
#include <LiquidCrystal.h>

DS3231 rtc;

int SignalPin = 7; 
int LEDPin = 8;
int Object = HIGH;
bool h12 = 0;
bool ampm = 0;
bool fourbitmode = 1; 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setupRTC(){
  // rtc.setDoW(THURSDAY);     // Set Day-of-Week to SUNDAY
  // rtc.setSecond(0);
  // rtc.setMinute(35);
  // rtc.setHour(00);  // Set the time to 12:00:00 (24hr format)
  // rtc.setDate(27);
  // rtc.setMonth(10);
  // rtc.setYear(2022);
  //return;
}

void displayTime(){
  lcd.print("Time: ");
  lcd.print(rtc.getHour(h12, ampm));
  lcd.print("-");
  lcd.print(rtc.getMinute());
  lcd.print("-");
  lcd.print(rtc.getSecond());
  lcd.print("");
  return;
}

void setup() {
  lcd.begin(16,2);

  Serial.begin(9600); 
  
  pinMode(SignalPin, INPUT); // Initialize D2 as an INput pin
  pinMode(LEDPin, OUTPUT);

  Wire.begin();
  //setupRTC();

}
  

void loop() {
  Object = digitalRead(SignalPin);

  lcd.setCursor(0,0);
  lcd.clear();    

  if (Object == LOW)
  {
    
    displayTime();
    
    digitalWrite(LEDPin, HIGH);
    
    delay(1000);
    
  }

  digitalWrite(LEDPin, LOW);
  
  delay(100);
}