#include <iostream>
using namespace std;

int main() {
    float firstNumber, secondNumber;
    char operatorSymbol;

    while (true) { 
        cout << "Enter First Operand, operator and Second Operand (or 'q' to quit): ";
        cin >> firstNumber >> operatorSymbol >> secondNumber;

        if (operatorSymbol == 'Q' || operatorSymbol == 'q') {
            break; 
        }

        switch (operatorSymbol) {
            case '+':
                cout << firstNumber << " + " << secondNumber << " = " << firstNumber + secondNumber << std::endl;
                break;
            case '-':
                cout << firstNumber << " - " << secondNumber << " = " << firstNumber - secondNumber << std::endl;
                break;
            case '*':
                cout << firstNumber << " * " << secondNumber << " = " << firstNumber * secondNumber << std::endl;
                break;
            case '/':
                if (secondNumber == 0) {
                    cout << "Error: Division by zero!" << std::endl;
                } else {
                    cout << firstNumber << " / " << secondNumber << " = " << firstNumber / secondNumber << std::endl;
                }
                break;
            case '%':
                cout << firstNumber << " % " << secondNumber << " = " << int(firstNumber) % int(secondNumber) << std::endl;
                break;
            default:
                cout << "Invalid operator!" << std::endl;
        }
    }

    return 0;
}
