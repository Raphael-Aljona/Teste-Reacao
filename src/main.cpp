#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

const int led = 18;
const int butao = 23;

void setup(){
    pinMode (led, OUTPUT);
    pinMode (butao, INPUT_PULLUP);

    lcd.init();
    lcd.backlight();
    Serial.begin(9600);
    lcd.setCursor(0, 0);
    lcd.print("Aperte o botao");
    lcd.print("para começar");
}

void loop(){
    bool estadoAtual = digitalRead(butao);
    static bool estadoAnterior = 0;
    unsigned long tempo = millis();
    unsigned long tempoEspera = random(1000,5000);
    int count;
    Serial.println(estadoAtual);
    Serial.println(estadoAnterior);

    if (estadoAtual && !estadoAnterior){
        count ++;
        Serial.println(count);
    }

    if (count >= 1){
        tempo = tempoEspera;
        Serial.println("foi");
        if(tempoEspera == tempoEspera){
            digitalWrite(led, HIGH);
            tempo = 0;
            Serial.print("tempo de espera = tempo");
        }
    }

    estadoAnterior = estadoAtual;

    delay(1000);
}