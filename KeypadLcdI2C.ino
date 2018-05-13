
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const byte LINHAS = 4;
const byte COLUNAS = 4;

const char TECLAS[LINHAS][COLUNAS] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
};

byte pinosLinhas[LINHAS] = {4, 5, 6, 7};
byte pinosColunas[COLUNAS] = {8, 9, 10, 11};

Keypad teclado = Keypad(makeKeymap(TECLAS), pinosLinhas, pinosColunas, LINHAS, COLUNAS);

void setup() {
    lcd.begin();
    lcd.backlight();
}

void loop() {

    lcd.setCursor(0, 0);
    lcd.print("PRESSIONE UMA TECLA");

    char teclaPressionada = teclado.getKey();

    if (teclaPressionada) {

        lcd.clear();
        lcd.setCursor(1, 1);
        lcd.print("TECLA PRESSIONADA");

        lcd.setCursor(10, 2);
        lcd.print(teclaPressionada);

        delay(500);

        lcd.clear();
    }
}


