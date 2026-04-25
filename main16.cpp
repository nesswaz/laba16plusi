#include <iostream>
#include "h16.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <limits>
#ifdef _WIN64
#include <windows.h>
#endif

int main() {
    using namespace std;
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif
    int choice;
    TreeOriginal Tree1;
    do {
        cout << "\n1. Заполнение с клавиатуры" << endl;
        cout << "2. Заполнение на рандом" << endl;
        cout << "3. Заполнение из файла" << endl;
        cout << "4. Показать дерево" << endl;
        cout << "5. TreeWork7" << endl;
        cout << "6. TreeWork16" << endl;
        cout << "7. TreeWork17" << endl;
        cout << "0. Выход" << endl;
        choice = Check::getNumb("Выберите: ");
        // cout << "Выберите: ";
        // cin >> choice;
        switch (choice) {
            case 1: {
                Tree1.InputFromKeyboard();
                break;
            }
            case 2: {
                Tree1.InputFromRandom(5);
                break;
            }
            case 3: {
                Tree1.InputFromFile("b.txt");
                break;
            }
            case 4: {
                Tree1.print();
                break;
            }
            case 5: {
                TreeWork7(Tree1);
                break;
            }
            case 6: {
                TreeWork16(Tree1);
                break;
            }
            case 7: {
                TreeWork17(Tree1);
                break;
            }
            case 0: {
                cout << "Выход из программы\n";
                break;
            }
            default:
                cout << "Введено неверное значение\n";
        }
    } 
    while (choice != 0);
    return 0;
}