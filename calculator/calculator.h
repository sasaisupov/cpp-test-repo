#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>

using Number = double;

// Возвращает true, если удалось прочитать число
// и сохранить его в Number.
bool ReadNumber(Number& result);

// Возвращает true, если работа завершилась штатно 
// командой q. Если из-за ошибки, возвращает false.
bool RunCalculatorCycle();

#endif // CALCULATOR_H