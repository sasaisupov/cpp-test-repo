#include "calculator.h"
#include <cmath>
#include <string>

bool ReadNumber(Number& result) {
    std::string input;
    std::cin >> input;
    
    try {
        result = std::stod(input);
        return true;
    } catch (const std::exception&) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
}

bool RunCalculatorCycle() {
    Number currentValue = 0.0;
    Number memory = 0.0;
    bool memoryInitialized = false;
    
    std::string command;
    
    // Читаем начальное число
    if (!ReadNumber(currentValue)) {
        return false;
    }
    
    while (std::cin >> command) {
        if (command == "+") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            currentValue += operand;
        }
        else if (command == "-") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            currentValue -= operand;
        }
        else if (command == "*") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            currentValue *= operand;
        }
        else if (command == "/") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            currentValue /= operand;
        }
        else if (command == "**") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            currentValue = std::pow(currentValue, operand);
        }
        else if (command == "=") {
            std::cout << currentValue << std::endl;
        }
        else if (command == ":") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            currentValue = operand;
        }
        else if (command == "c") {
            currentValue = 0.0;
        }
        else if (command == "s") {
            memory = currentValue;
            memoryInitialized = true;
        }
        else if (command == "l") {
            if (!memoryInitialized) {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
            currentValue = memory;
        }
        else if (command == "q") {
            return true;
        }
        else {
            std::cerr << "Error: Unknown token " << command << std::endl;
            return false;
        }
    }
    
    return false;
}