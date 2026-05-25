#include <iostream>
#include <string>

class Counter {
private:
    int count;

public:
    Counter(int initialValue) : count(initialValue) {}
    
    Counter() : count(1) {}
    
    void increment() {
        count++;
    }
    
    void decrement() {
        count--;
    }
    
    int getValue() const {
        return count;
    }
};

int main() {
    Counter counter;
    std::string answer;
    int initialValue;
    
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> answer;
    
    if (answer == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initialValue;
        counter = Counter(initialValue);
    }
    
    char command;
    
    while (true) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;
        
        switch (command) {
            case '+':
                counter.increment();
                break;
            case '-':
                counter.decrement();
                break;
            case '=':
                std::cout << counter.getValue() << std::endl;
                break;
            case 'x':
                std::cout << "До свидания!" << std::endl;
                return 0;
            default:
                std::cout << "Неверная команда! Используйте '+', '-', '=' или 'x'." << std::endl;
                break;
        }
    }
    
    return 0;
}
