#include <iostream>
#include <stdexcept>
#include "utils/utils.h"

using namespace std;

static const char numbers[] = "0123456789";
static const char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char symbols[] = "!@#$%^&*()_-+=}{[]|\"':;?/>.<,~";

string generateRandomPassword(int length, bool useSymbols, bool useNumbers) {
    int numbers_len = sizeof(numbers) - 2;
    int letters_len = sizeof(letters) - 2;
    int symbols_len = sizeof(symbols) - 2;

    string password;

    for (int i = 0; i < length; ++i) {
        long option = randomNumber(0, 2);
        switch (option) {
            case 0:
                if (useNumbers) {
                    password += numbers[randomNumber(0, numbers_len)];
                } else {
                    password += letters[randomNumber(0, letters_len)];
                }
                break;
            case 1:
                password += letters[randomNumber(0, letters_len)];
                break;
            case 2:
                if (useSymbols) {
                    password += symbols[randomNumber(0, symbols_len)];
                } else {
                    password += letters[randomNumber(0, letters_len)];
                }
                break;
            default:
                throw invalid_argument("Cannot handle case " + to_string(option));
        }
    }
    return password;
}

bool readBool(char input) {
    return input == 'y';
}

void generateAndWrite(bool useSymbols, bool useNumbers, int length) {
    string password = generateRandomPassword(length, useSymbols, useNumbers);

    cout << "Your password: " << password << endl;

    char generateAnother;
    cout << "Do you want to generate another password? (y/n) ";
    cin >> generateAnother;
    if (readBool(generateAnother)) {
        cout << endl << endl;
        generateAndWrite(useSymbols, useNumbers, length);
    }
}

int main() {
    char useSymbols;
    char useNumbers;
    int length;

    cout << "Use symbols (y/n): ";
    cin >> useSymbols;
    cout << endl;

    cout << "Use numbers (y/n): ";
    cin >> useNumbers;
    cout << endl;

    cout << "Enter the length of password: ";
    cin >> length;
    cout << endl;

    generateAndWrite(readBool(useSymbols), readBool(useNumbers), length);

    return 0;
}


