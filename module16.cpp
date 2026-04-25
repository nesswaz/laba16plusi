#include "h16.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <limits>

// void TreeOriginal::InputFromKeyboard() { 
//     clear();
//     int n, element;
//     std::cout << "Введите количество элементов: ";
//     std::cin >> n;
//     std::cout << "Введите " << n << " элементов: ";
//     for (int i = 0; i < n; i++) {
//         std::cin >> element;
//         add(element); 
//     }
//     std::cout << "Заполнение выполнено успешно";
// }

void TreeOriginal::InputFromKeyboard() {
    clear();
    int n = Check::getNumb("Введите количество элементов: ");
    for (int i = 0; i < n; i++) {
        int element = Check::getNumb("Введите элемент " + std::to_string(i+1) + ": ");
        add(element); 
    }
    std::cout << "Заполнение успешно\n";
}

void TreeOriginal::InputFromFile(char const* filename) {
    clear();
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла\n";
        return;
    }
    int element;
    while (file >> element) {
        add(element);
    }
    file.close();
    std::cout << "Данные успешно считаны из файла\n";
}

void TreeOriginal::InputFromRandom(int n) {
    clear();
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < n; i++) {
        add(std::rand() % 100); 
    }
    std::cout << "Заполнение выполнено успешно";
}

void TreeWork7(TreeOriginal &tree) {
//     if (tree.isEmpty()) {
//         std::cout << "Ошибка, дерево пустое" << std::endl;
//         return;
//     }
    if (!Check::isDEmpty(tree)) return; 
    std::cout << "Текущее дерево: " << std::endl;
    tree.print();
    int mini = tree.findMin();
    std::cout << "Минимальное значение: " << mini << std::endl;
}

void TreeWork16(TreeOriginal &tree) {
    // if (tree.isEmpty()) {
    //     std::cout << "Ошибка, дерево пустое" << std::endl;
    //     return;
    // }
    if (!Check::isDEmpty(tree)) return; 
    std::cout << "Указатель p1 (на корень): " << tree.getRoot() << std::endl;
    std::cout << "Отсортированный набор: ";
    tree.printSorted();
}



void TreeWork17(TreeOriginal &tree) {
    // if (tree.isEmpty()) {
    //     std::cout << "Ошибка, дерево пустое" << std::endl;
    //     return;
    // }
    if (!Check::isDEmpty(tree)) return; 
    std::cout << "Текущее дерево:" << std::endl;
    tree.print();
    int Min2 = tree.findMin2();
    std::cout << "Второе минимальное значение: " << Min2 << std::endl;
}


