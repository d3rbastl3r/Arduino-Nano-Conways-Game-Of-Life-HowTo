#include <Arduino.h>

#include "RgbLedMatrixCtrl.cpp"

RgbLedMatrixCtrl rgbLedMatrixCtrl;

void setup() {}

void loop() {
    rgbLedMatrixCtrl.draw();
}