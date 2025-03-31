#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

const int led = 18;
const int botao = 23;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
    pinMode(led, OUTPUT);
    pinMode(botao, INPUT_PULLUP);

    lcd.init();
    lcd.backlight();
    lcd.print("Jogo de Reflexo");
    delay(2000);
    lcd.clear();
}

void loop() {
    lcd.setCursor(0, 0);
    lcd.print("Prepare-se...");
    int tempoEspera = random(1000, 6000);
    unsigned long inicioEspera = millis();

    while (millis() - inicioEspera < tempoEspera) {
        if (digitalRead(botao) == LOW) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Muito Cedo!");
            delay(2000);
            lcd.clear();
            return;
        }
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("APERTA AI!");
    digitalWrite(led, HIGH);

    unsigned long tempoInicio = millis();
    while (digitalRead(botao) == HIGH) {
    }
    unsigned long tempoReacao = millis() - tempoInicio;

    digitalWrite(led, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Tempo: ");
    lcd.setCursor(7, 0);
    lcd.print(tempoReacao);
    lcd.print(" ms");
    if (tempoReacao <= 149){
        lcd.setCursor(0,1);
        lcd.print("Radiante o minino");
    }
    if (tempoReacao >= 150 && tempoReacao <= 199){
        lcd.setCursor(0,1);
        lcd.print("Imortal");
    }if(tempoReacao >= 200 && tempoReacao <= 249){
        lcd.setCursor(0,1);
        lcd.print("ELOZAP");
    }if (tempoReacao >= 250 && tempoReacao <= 299){
        lcd.setCursor(0,1);
        lcd.print("Diamante");
    }if (tempoReacao >= 300 && tempoReacao <= 349){
        lcd.setCursor(0,1);
        lcd.print("Pratina");
    }if (tempoReacao >= 350 && tempoReacao <= 399){
        lcd.setCursor(0,1);
        lcd.print("Gold");
    }if (tempoReacao >= 400 && tempoReacao <= 449){
        lcd.setCursor(0,1);
        lcd.print("Prata");
    }if (tempoReacao >= 450 && tempoReacao <= 499){
        lcd.setCursor(0,1);
        lcd.print("Bronze");
    }if (tempoReacao >= 500){
        lcd.setCursor(0,1);
        lcd.print("Ferro");
    }
    delay(5000);
    lcd.clear();
}
