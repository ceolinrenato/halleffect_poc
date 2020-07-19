#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

#define LCD_COLS 16
#define LCD_ROWS 2
#define FUEL_IN_PIN 5
#define FUEL_OUT_PIN 18

LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS);

volatile int fuelInCounter = 0;
volatile int fuelOutCounter = 0;

portMUX_TYPE muxIn = portMUX_INITIALIZER_UNLOCKED;
portMUX_TYPE muxOut = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR handleFuelIn() {
  portENTER_CRITICAL_ISR(&muxIn);
  fuelInCounter++;
  portEXIT_CRITICAL_ISR(&muxIn);
}

void IRAM_ATTR handleFuelOut() {
  portENTER_CRITICAL_ISR(&muxOut);
  fuelOutCounter++;
  portEXIT_CRITICAL_ISR(&muxOut);
}

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Total Consumed");
  lcd.setCursor(14, 1);
  lcd.print("L");
  lcd.setCursor(0,1);
  pinMode(FUEL_IN_PIN, INPUT);
  pinMode(FUEL_OUT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(FUEL_IN_PIN), handleFuelIn, RISING);
  attachInterrupt(digitalPinToInterrupt(FUEL_OUT_PIN), handleFuelOut, RISING);
}

void loop(){
  float totalLitersConsumed = ((float) fuelInCounter - (float) fuelOutCounter) / 1000;
  lcd.setCursor(0,1);
  lcd.print("              ");
  lcd.setCursor(0,1);
  lcd.printf("%.3f", totalLitersConsumed);
  delay(1000);
}
