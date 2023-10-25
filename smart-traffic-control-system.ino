#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;

#define ldr1 22
#define ldr2 23
#define ldr3 24
#define ldr4 25

#define servo1 26
#define servo2 27
#define servo3 28

#define ledA1 2
#define ledA2 3
#define ledA3 4

#define ledB1 5
#define ledB2 6
#define ledB3 7

#define ledC1 8
#define ledC2 9
#define ledC3 10

#define ledD1 11
#define ledD2 12
#define ledD3 13

#define Zled1 29
#define Zled2 30
#define Zbuzzer 31

LiquidCrystal_I2C lcd(0x27, 16, 2);


int a1 = 0;
int ads = 10, PARK1=0, ass = 0, pos = 0;

void setup() {

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  myservo1.attach(servo1);
  myservo2.attach(servo2);
  myservo3.attach(servo3);

  pinMode(ledA1, OUTPUT);
  pinMode(ledA2, OUTPUT);
  pinMode(ledA3, OUTPUT);

  pinMode(ledB1, OUTPUT);
  pinMode(ledB2, OUTPUT);
  pinMode(ledB3, OUTPUT);

  pinMode(ledC1, OUTPUT);
  pinMode(ledC2, OUTPUT);
  pinMode(ledC3, OUTPUT);

  pinMode(ledD1, OUTPUT);
  pinMode(ledD2, OUTPUT);
  pinMode(ledD3, OUTPUT);

  pinMode(Zled1, OUTPUT);
  pinMode(Zled2, OUTPUT);
  pinMode(Zbuzzer, OUTPUT);

  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  pinMode(ldr4, INPUT);

  myservo1.write(95);
  myservo2.write(180);
  myservo3.write(180);

  digitalWrite(Zled1, HIGH);
  digitalWrite(Zled2, LOW);
  noTone(Zbuzzer);

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Parking!");
  lcd.setCursor(0, 1);
  lcd.print("Parking Entry:0");
  lcd.print(4);
}

void loop() {

   if (a1 == 0 )
  {
    roadBopen();
    if (a1 == 0 )
    {
      roadDopen();
    }
    if (a1 == 0 )
    {
      roadAopen();
    }
    if (a1 == 0 )
    {
      roadCopen();
    }
  }
}

void roadAopen()
{

  digitalWrite(ledA3, LOW);

  digitalWrite(ledA1, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  for (int asds = 0; asds <= (ads * 1000); asds++) {
    parking1();
    if (digitalRead(ldr3) == 0 && pos == 0) {
      delay(300);
      if (digitalRead(ldr3) == 0) {
        pos = 1;
      }
    }
    delay(1);
  }

  digitalWrite(ledA1, LOW);
  digitalWrite(ledA2, HIGH);
  for (int asds = 0; asds <= (ads * 200); asds++) {
    parking1();
    if (digitalRead(ldr3) == 0 && pos == 0) {
      delay(300);
      if (digitalRead(ldr3) == 0) {
        pos = 1;
      }
    }
    delay(1);
  }
  digitalWrite(ledA2, LOW);
  if (pos == 1) {
    digitalWrite(Zled1, LOW);
    digitalWrite(Zled2, HIGH);
    tone(Zbuzzer, 800);
    myservo2.write(90);
    myservo3.write(90);
    ral();
  }
}

void roadBopen()
{

  digitalWrite(ledB3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB1, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);

  for (int asds = 0; asds <= (ads * 1000); asds++) {
    parking1();
    if (digitalRead(ldr3) == 0 && pos == 0) {
      delay(300);
      if (digitalRead(ldr3) == 0) {
        pos = 1;
      }
    }
    delay(1);
  }

  digitalWrite(ledB1, LOW);
  digitalWrite(ledB2, HIGH);
  for (int asds = 0; asds <= (ads * 200); asds++) {
    parking1();
    if (digitalRead(ldr3) == 0 && pos == 0) {
      delay(300);
      if (digitalRead(ldr3) == 0) {
        pos = 1;
      }
    }
    delay(1);
  }
  digitalWrite(ledB2, LOW);
  if (pos == 1) {
    digitalWrite(Zled1, LOW);
    digitalWrite(Zled2, HIGH);
    tone(Zbuzzer, 800);
    myservo2.write(90);
    myservo3.write(90);
    ral();
  }
}

void roadCopen()
{

  digitalWrite(ledC3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC1, HIGH);
  digitalWrite(ledD3, HIGH);

  for (int asds = 0; asds <= (ads * 1000); asds++) {
    parking1();
    if (digitalRead(ldr3) == 0 && pos == 0) {
      delay(300);
      if (digitalRead(ldr3) == 0) {
        pos = 1;
      }
    }
    delay(1);
  }

  digitalWrite(ledC1, LOW);
  digitalWrite(ledC2, HIGH);
  for (int asds = 0; asds <= (ads * 200); asds++) {
    parking1();
    if (digitalRead(ldr3) == 0 && pos == 0) {
      delay(300);
      if (digitalRead(ldr3) == 0) {
        pos = 1;
      }
    }
    delay(1);
  }
  digitalWrite(ledC2, LOW);
  if (pos == 1) {
    digitalWrite(Zled1, LOW);
    digitalWrite(Zled2, HIGH);
    tone(Zbuzzer, 800);
    myservo2.write(90);
    myservo3.write(90);
    ral();
  }
}

void roadDopen()
{

  digitalWrite(ledD3, LOW);

  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD1, HIGH);
  for (int asds = 0; asds <= (ads * 1000); asds++) {
    parking1();
    if (digitalRead(ldr3) == 0 && pos == 0) {
      delay(300);
      if (digitalRead(ldr3) == 0) {
        pos = 1;
      }
    }
    delay(1);
  }

  digitalWrite(ledD1, LOW);
  digitalWrite(ledD2, HIGH);
  for (int asds = 0; asds <= (ads * 200); asds++) {
    parking1();
    if (digitalRead(ldr3) == 0 && pos == 0) {
      delay(300);
      if (digitalRead(ldr3) == 0) {
        pos = 1;
      }
    }
    delay(1);
  }
  digitalWrite(ledD2, LOW);
  if (pos == 1) {
    digitalWrite(Zled1, LOW);
    digitalWrite(Zled2, HIGH);
    tone(Zbuzzer, 800);
    myservo2.write(90);
    myservo3.write(90);
    ral();
  }
}

void parking1() {
  if (digitalRead(ldr1) == 0) {
    if (ass == 0) {
      PARK1++;
      if (PARK1 > 4) {
        PARK1 = 4;
        myservo1.write(95);
      }
      else {
        myservo1.write(0);
        ass = 2;
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Parking!");
        lcd.setCursor(0, 1);
        lcd.print("Parking Entry:0");
        lcd.print(4 - PARK1);
        if (PARK1 == 4) {
          lcd.clear();
          lcd.setCursor(4, 0);
          lcd.print("Parking!");
          lcd.setCursor(2, 1);
          lcd.print("Full No Entry");
        }
      }
    }
    if (ass == 1) {
      ass = 0;
      myservo1.write(95);
    }
    delay(500);
  }
  if (digitalRead(ldr2) == 0) {
    if (ass == 0) {
      PARK1--;
      if (PARK1 < 0) {
        PARK1 = 0;
        myservo1.write(95);
      }
      else {
        myservo1.write(0);
        ass = 1;
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Parking!");
        lcd.setCursor(0, 1);
        lcd.print("Parking Entry:0");
        lcd.print(4 - PARK1);
      }
    }
    if (ass == 2) {
      ass = 0;
      myservo1.write(95);
    }
    delay(500);
  }
}

void ral() {
  while (1) {
    // Road A
    digitalWrite(ledA3, LOW);

    digitalWrite(ledA1, HIGH);
    digitalWrite(ledB3, HIGH);
    digitalWrite(ledC3, HIGH);
    digitalWrite(ledD3, HIGH);
    for (int asds = 0; asds <= (ads * 1000); asds++) {
      parking1();
      if (digitalRead(ldr4) == 0 && pos == 1) {
        delay(300);
        if (digitalRead(ldr4) == 0) {
          pos = 0;
        }
      }
      delay(1);
    }

    digitalWrite(ledA1, LOW);
    digitalWrite(ledA2, HIGH);
    for (int asds = 0; asds <= (ads * 200); asds++) {
      parking1();
      if (digitalRead(ldr4) == 0 && pos == 1) {
        delay(300);
        if (digitalRead(ldr4) == 0) {
          pos = 0;
        }
      }
      delay(1);
    }
    digitalWrite(ledA2, LOW);
    if (pos == 0) {
      digitalWrite(Zled1, HIGH);
      digitalWrite(Zled2, LOW);
      noTone(Zbuzzer);
      myservo2.write(180);
      myservo3.write(180);
      break;
    }

    // Road C

    digitalWrite(ledC3, LOW);

    digitalWrite(ledA3, HIGH);
    digitalWrite(ledB3, HIGH);
    digitalWrite(ledC1, HIGH);
    digitalWrite(ledD3, HIGH);

    for (int asds = 0; asds <= (ads * 1000); asds++) {
      parking1();
      if (digitalRead(ldr4) == 0 && pos == 1) {
        delay(300);
        if (digitalRead(ldr4) == 0) {
          pos = 0;
        }
      }
      delay(1);
    }

    digitalWrite(ledC1, LOW);
    digitalWrite(ledC2, HIGH);
    for (int asds = 0; asds <= (ads * 200); asds++) {
      parking1();
      if (digitalRead(ldr4) == 0 && pos == 1) {
        delay(300);
        if (digitalRead(ldr4) == 0) {
          pos = 0;
        }
      }
      delay(1);
    }
    digitalWrite(ledC2, LOW);
    if (pos == 0) {
      digitalWrite(Zled1, HIGH);
      digitalWrite(Zled2, LOW);
      noTone(Zbuzzer);
      myservo2.write(180);
      myservo3.write(180);
      break;
    }

    // Road D

    digitalWrite(ledD3, LOW);

    digitalWrite(ledA3, HIGH);
    digitalWrite(ledB3, HIGH);
    digitalWrite(ledC3, HIGH);
    digitalWrite(ledD1, HIGH);
    for (int asds = 0; asds <= (ads * 1000); asds++) {
      parking1();
      if (digitalRead(ldr4) == 0 && pos == 1) {
        delay(300);
        if (digitalRead(ldr4) == 0) {
          pos = 0;
        }
      }
      delay(1);
    }

    digitalWrite(ledD1, LOW);
    digitalWrite(ledD2, HIGH);
    for (int asds = 0; asds <= (ads * 200); asds++) {
      parking1();
      if (digitalRead(ldr4) == 0 && pos == 1) {
        delay(300);
        if (digitalRead(ldr4) == 0) {
          pos = 0;
        }
      }
      delay(1);
    }
    digitalWrite(ledD2, LOW);
    if (pos == 0) {
      digitalWrite(Zled1, HIGH);
      digitalWrite(Zled2, LOW);
      noTone(Zbuzzer);
      myservo2.write(180);
      myservo3.write(180);
      break;
    }
  }
  roadBopen();
}
