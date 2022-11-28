#ifndef KEYPAD_HPP
#define KEYPAD_HPP

#include "Libraries.h"


const byte rowsCount = 4;
const byte columsCount = 4;

char keys[rowsCount][columsCount] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[rowsCount] = {13,12,14,27};
byte columnPins[columsCount] = {26,25,33,32};

Keypad teclado = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);


#endif