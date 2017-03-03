#include "LCD1x9.h"
#include <Wire.h>

LCD1x9 lcd;

void setup() {
  // Use the default SDA,SCL
  Wire.begin(); 
  delay(3);

  lcd.initialize();
}

// put your main code here, to run repeatedly:
char * txt = "Hello, LCD world!";
int offset = 0 ;
int inc = 1;

void loop() {
  lcd.write(txt + offset);
  offset += inc;
  if (offset  >= strlen(txt) - 9 ){
    inc  = -1;
  } 
  if(offset <= 0){
    inc = 1;
  }
  delay(500);
}
