#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <limits>


struct Node {
    int key; //информационное поле (ключ)
    Node *left, *right; //указатели на сыновей
};
class TreeOriginal {
private:
    Node* root;
    void AddToTree(Node*& Tree, int data) {
        if (!Tree) {
            Tree = new Node; 
            Tree->key = data;
            Tree->left = nullptr;
            Tree->right = nullptr;
            return;
        }
        if (data < Tree->key) 
            AddToTree(Tree->left, data);
        else 
            AddToTree(Tree->right, data);
    }

    // void PrintTree1(Node* Tree) { //печать дерева скобочками
    //     if (Tree!=nullptr) {
    //         std::cout<<Tree->key;
    //         std::cout<<"(";
    //         PrintTree1(Tree->left);
    //         std::cout<<")";
    //         std::cout<<"(";
    //         PrintTree1(Tree->right);
    //         std::cout<<")";
    //     }
    //     else std::cout<<"null";
    // }
    void PrintTree1(Node* Tree, int h) { //печать дерева боком
        int i;
        if (Tree!=nullptr) {
            PrintTree1(Tree->right, h + 1); //спуск в правое поддерево и определение количества //уровней h, чтобы определить, сколько групп пробелов необходимо поставить перед значением
            for (i=1; i<=h; i++) { //вывод h групп пробелов
                std::cout<<"  "; //2 or 4
            }
                std::cout<<Tree->key<<std::endl; //вывод ключа
                std::cout<<std::endl;
                PrintTree1(Tree->left, h + 1); //спуск в левое поддерево
        }
    }

    void ClearTree(Node*& node) {
        if (node) {
            ClearTree(node->left);
            ClearTree(node->right);
            delete node;
            node = nullptr;
        }
    }
    void SortedLKP(Node* Tree) { //2 задача (16) 
        if (!Tree) return; //пустое дерево – окончание рекурсии
        SortedLKP(Tree->left); //обход левого поддерева
        std::cout<< Tree->key << " "; //вывод информации о корне
        SortedLKP(Tree->right); //обход правого поддерева
    }
public:
    TreeOriginal() : root(nullptr) {}
    void add(int data) {
        AddToTree(root, data);
    }
    void print() {
        PrintTree1(root, 0);
        std::cout << std::endl;
    }
    void clear() {
        ClearTree(root);
    }
    int findMin() { //1 задача (7)
        if (root == nullptr) {
            std::cout << "Ошибка, заполните дерево" << std::endl;
            return 0;
        }
        Node* p1 = root;
        while (p1->left != nullptr) {
            p1 = p1->left;
        }
        return p1->key; 
    }
    bool isEmpty() {
        return root == nullptr;
    }
    void InputFromRandom(int n);
    void InputFromFile(const char* filename);
    void InputFromKeyboard();
    Node* getRoot() {return root;} //возвращает указатель р1

    void printSorted() { 
        SortedLKP(root); 
        std::cout << std::endl;
    }

    int findMin2() { //задача 3 (17)
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) { 
            return 0;
        }
        Node* parent = nullptr; //ставим указатель родитель на пустое значение
        Node* p1 = root; //ставим указатель р1 на корень
        while (p1->left != nullptr) { //идем до самого маленького (влево) пока они есть
            parent = p1; //ставим на корень указатель родитель
            p1 = p1->left; //ставим р1 на самый маленький элемент (влево)
        }
        if (p1->right != nullptr) { //если есть правая ветка
            p1 = p1->right; //присваиваем указатель р1 на правую ветку
            while (p1->left != nullptr) { //проверяем есть ли возможность идти левее
                p1 = p1->left; //если есть указатель р1 ставим влево
            }
            return p1->key; 
        }
        return parent->key;
    }
};

class Check {
public:
    static bool isDEmpty(TreeOriginal &tree) {
            if (tree.isEmpty()) {
                std::cout << "Ошибка, дерево пусто" << std::endl;
                return false;
            }
            return true;
        }
    static int getNumb(std::string str) {
        int value;
        while (true) {
            std::cout << str;
            if (std::cin >> value) return value;
            std::cout << "Ошибка, введите число" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
};
void TreeWork7(TreeOriginal &tree);
void TreeWork16(TreeOriginal &tree);
void TreeWork17(TreeOriginal &tree);
