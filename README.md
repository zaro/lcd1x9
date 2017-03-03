# What

An Arduino library to easily drive  the Olimex LCD 1x9 UEXT module

# How

```cpp
#include "LCD1x9.h"
#include <Wire.h>

LCD1x9 lcd;

void setup() {
  // Use the default SDA,SCL
  Wire.begin();
  delay(3);

  lcd.initialize();
}


void loop() {
  lcd.write("Hello world");
}

```

# Author

Svetlozar Argirov <zarrro@gmail.com>

# LICENSE
Public domain
