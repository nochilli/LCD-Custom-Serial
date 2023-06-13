#include <LiquidCrystal.h>

LiquidCrystal lcd(16, 17, 22, 26, 27, 28);

char val = 'h';
int n = 0;

byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte man[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

byte eye[8] = {
  0b01110,
  0b10001,
  0b10101,
  0b10101,
  0b10101,
  0b10001,
  0b10001,
  0b01110
};

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.createChar(0, heart);
  lcd.createChar(1, smiley);
  lcd.createChar(2, frownie);
  lcd.createChar(3, man);
  lcd.createChar(4, eye);
}

void loop() {
  if (Serial.available()) {
    val = Serial.read();
    switch (val) {
      case 'h':
        n = 0;
        break;
      case 's':
        n = 1;
        break;
      case 'f':
        n = 2;
        break;
      case 'm':
        n = 3;
        break;
      case 'e':
        n = 4;
        break;
    }
    for (int i = 0; i < 16; i++) {
      lcd.setCursor(i, 0);
      lcd.write(byte(n));
      delay(50);
    }
  }
}
