#include <AvrI2c_Greiman.h>
#include <LiquidCrystal_I2C_AvrI2C.h>


LiquidCrystal_I2C_AvrI2C lcd(0x3F, 16, 2);
const byte pHpin = A0;
float Po;

void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}

float okunan = 0.0;
void loop()
{
  
  
  okunan = analogRead(pHpin);
  Po = ((float)1023.0 - okunan) / 73.07;
  //Po = ((float)1023.0 - okunan) / 68.02;
    
  Serial.print("okunan : ");
  Serial.println(okunan);
  
  Serial.println();
  
  Serial.print("Po = ");
  Serial.println(Po);
  lcd.setCursor(1, 0);
  lcd.print("pH:");
  lcd.setCursor(4,0);
  lcd.print(Po, 2);
  delay(1000);
  if((okunan>6) && (okunan<7))
  {
     lcd.setCursor(1, 1);
     lcd.print("SONUC:");
        lcd.setCursor(7, 1);
        lcd.print("TAZE");
    }
  else
  {
    lcd.setCursor(1, 1);
     lcd.print("SONUC:");
        lcd.setCursor(7, 1);
        lcd.print("BOZUK");
    
    }
}

