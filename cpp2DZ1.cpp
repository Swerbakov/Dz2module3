#include <iostream>

class Calculator {
private:
    double num1;
    double num2;

public:
    // Конструктор по умолчанию
    Calculator() : num1(0), num2(0) {}
    
    // Арифметические методы
    double add() {
        return num1 + num2;
    }
    
    double multiply() {
        return num1 * num2;
    }
    
    double subtract_1_2() {
        return num1 - num2;
    }
    
    double subtract_2_1() {
        return num2 - num1;
    }
    
    double divide_1_2() {
        if (num2 != 0) {
            return num1 / num2;
        }
        return 0; // Возвращаем 0 в случае ошибки (хотя по условию set_num2 не позволит установить 0)
    }
    
    double divide_2_1() {
        if (num1 != 0) {
            return num2 / num1;
        }
        return 0; // Возвращаем 0 в случае ошибки
    }
    
    // Методы для установки значений с проверкой
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        return false;
    }
    
    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        return false;
    }
    
    // Геттеры для получения значений (опционально)
    double get_num1() {
        return num1;
    }
    
    double get_num2() {
        return num2;
    }
};

int main() {
    Calculator calc;
    double input1, input2;
    
    while (true) {
        // Ввод первого числа
        std::cout << "Введите num1: ";
        std::cin >> input1;
        
        // Пытаемся установить num1
        while (!calc.set_num1(input1)) {
            std::cout << "Неверный ввод!" << std::endl;
            std::cout << "Введите num1: ";
            std::cin >> input1;
        }
        
        // Ввод второго числа
        std::cout << "Введите num2: ";
        std::cin >> input2;
        
        // Пытаемся установить num2
        while (!calc.set_num2(input2)) {
            std::cout << "Неверный ввод!" << std::endl;
            std::cout << "Введите num2: ";
            std::cin >> input2;
        }
        
        // Выводим результаты всех операций
        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }
    
    return 0;
}
