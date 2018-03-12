#include <iostream>
#include <limits>
#include <regex>

using namespace std;

string intToEnglish(long int input, int iter = 0, bool gf = false, bool tf = false);
long int pow(int lhs, int rhs);

int main() {

    while (true) {

        cout << "Enter an integer: " << flush;

        int input = 0;

        if (!(cin >> input)) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max());
            cout << "ERROR: Invalid input!" << endl;
            continue;

        }

        cout << "Your number is: " << intToEnglish(input) << endl;

        while (true) {

            cout << "Would you like to keep going? (Y/n): " << flush;

            string choice;

            cin >> choice;

            regex yes("[Yy]");
            regex no("[Nn]");

            if (regex_match(choice, yes)) {

                break;

            } else if (regex_match(choice, no)) {

                return 0;

            } else {

                cout << "ERROR: Invalid input!" << endl;

            }

        }

    }

}

string intToEnglish(const long int input, const int iter, bool gf, bool tf) {

    if (iter == 0 && input == 0) {
        return "zero";
    }
    if (iter == 10) {
        return "";
    }

    int digit = input / (1000000000 / (int) pow(10, iter));

    if (digit != 0) {
        gf = true;
    }

    if (digit == 1) {
        tf = true;
    }
    
    string place;
    string group;
    
    bool alt = false;
    bool teen = false;
    
    switch (iter) {
        case 0:
            if (digit != 0) {
                group = "billion ";
            }
            break;
        case 1:
            if (digit != 0) {
                place = "hundred ";
            }
            break;
        case 2:
            alt = true;
            break;
        case 3:
            if (gf) {
                group = "million ";
                gf = false;
            }
            teen = tf;
            break;
        case 4:
            if (digit != 0) {
                place = "hundred ";
            }
            tf = false;
            break;
        case 5:
            alt = true;
            break;
        case 6:
            if (gf) {
                group = "thousand ";
                gf = false;
            }
            teen = tf;
            break;
        case 7:
            if (digit != 0) {
                place = "hundred ";
            }
            tf = false;
            break;
        case 8:
            alt = true;
            break;
        case 9:
            teen = tf;
        default:
            break;
    }

    
    switch (digit) {
        case 0:
            return group + intToEnglish(input % (1000000000 / (int) pow(10, iter)), iter + 1, gf, tf);
        case 1:
            return (teen ? "eleven " : (alt ? "" : "one ")) + place + group + intToEnglish(input % (1000000000 / pow(10, iter)), iter + 1, gf, tf);
        case 2:
            return (teen ? "twelve " : (alt ? "twenty " : "two ")) + place + group + intToEnglish(input % (1000000000 / pow(10, iter)), iter + 1, gf, tf);
        case 3:
            return (teen ? "thirteen " : (alt ? "thirty " : "three ")) + place + group + intToEnglish(input % (1000000000 / pow(10, iter)), iter + 1, gf, tf);
        case 4:
            return (teen ? "fourteen " : (alt ? "forty " : "four ")) + place + group + intToEnglish(input % (1000000000 / pow(10, iter)), iter + 1, gf, tf);
        case 5:
            return (teen ? "fifteen " : (alt ? "fifty " : "five ")) + place + group + intToEnglish(input % (1000000000 / pow(10, iter)), iter + 1, gf, tf);
        case 6:
            return (teen ? "sixteen " : (alt ? "sixty " : "six ")) + place + group + intToEnglish(input % (1000000000 / pow(10, iter)), iter + 1, gf, tf);
        case 7:
            return (teen ? "seventeen " : (alt ? "seventy " : "seven ")) + place + group + intToEnglish(input % (1000000000 / pow(10, iter)), iter + 1, gf, tf);
        case 8:
            return (teen ? "eighteen " : (alt ? "eighty " : "eight ")) + place + group + intToEnglish(input % (1000000000 / pow(10, iter)), iter + 1, gf, tf);
        case 9:
            return (teen ? "nineteen " : (alt ? "ninety " : "nine ")) + place + group + intToEnglish(input % (1000000000 / pow(10, iter)), iter + 1, gf, tf);
        default:
            return "ERROR: Invalid input!";
    }

}

long int pow(int lhs, int rhs) {

    if (rhs == 0) {
        return 1;
    }

    return lhs * pow(lhs, rhs - 1);

}