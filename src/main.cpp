#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

const int led = 18;
const int button = 23;


LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
    pinMode(led, OUTPUT);
    pinMode(button, INPUT_PULLUP);

    lcd.init();
    lcd.backlight();
    lcd.print("Jogo de Reflexo");
    delay(2000);
    lcd.clear();
}

void loop() {
    lcd.setCursor(0, 0);
    lcd.print("Prepare-se...");
    delay(random(1000, 6000));

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pressione!");
    digitalWrite(led, HIGH);

    unsigned long startTime = millis();
    while (digitalRead(button) == HIGH) {
    }
    unsigned long reactionTime = millis() - startTime;

    digitalWrite(led, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tempo: ");
    lcd.setCursor(7, 0);
    lcd.print(reactionTime);
    lcd.print(" ms");
    delay(5000);
    lcd.clear();
}
