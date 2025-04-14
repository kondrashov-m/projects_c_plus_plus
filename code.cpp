#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cassert>

using namespace std;

// ==================== Лабораторная работа 1 (Ввод-вывод, циклы, условия) ====================
void lab1_task1() {
    cout << "Лабораторная работа 1. Задание 1" << endl;
    int a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;
    cout << "Сумма: " << a + b << endl;
    cout << "Разность: " << a - b << endl;
    cout << "Произведение: " << a * b << endl;
    if (b != 0) {
        cout << "Частное: " << (double)a / b << endl;
    } else {
        cout << "Деление на ноль!" << endl;
    }
}

void lab1_task2() {
    cout << "\nЛабораторная работа 1. Задание 2" << endl;
    double x, y;
    cout << "Введите координаты точки (x y): ";
    cin >> x >> y;
    
    if (x == 0 && y == 0) {
        cout << "Точка в начале координат" << endl;
    } else if (x == 0) {
        cout << "Точка на оси Y" << endl;
    } else if (y == 0) {
        cout << "Точка на оси X" << endl;
    } else {
        int quadrant = (x > 0) ? (y > 0 ? 1 : 4) : (y > 0 ? 2 : 3);
        cout << "Точка в квадранте " << quadrant << endl;
    }
}

// ==================== Лабораторная работа 2 (Массивы, строки) ====================
void lab2_task1() {
    cout << "\nЛабораторная работа 2. Задание 1" << endl;
    const int size = 10;
    int arr[size];
    
    cout << "Введите " << size << " чисел: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    
    cout << "Сумма элементов: " << sum << endl;
    cout << "Среднее значение: " << (double)sum / size << endl;
}

void lab2_task2() {
    cout << "\nЛабораторная работа 2. Задание 2" << endl;
    string str;
    cout << "Введите строку: ";
    cin.ignore();
    getline(cin, str);
    
    int vowels = 0, consonants = 0;
    for (char c : str) {
        if (isalpha(c)) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    cout << "Гласных: " << vowels << ", согласных: " << consonants << endl;
}

// ==================== Лабораторная работа 3 (Функции, рекурсия) ====================
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void lab3_task1() {
    cout << "\nЛабораторная работа 3. Задание 1" << endl;
    int num;
    cout << "Введите число: ";
    cin >> num;
    
    cout << "Факториал: " << factorial(num) << endl;
    cout << "Число Фибоначчи: " << fibonacci(num) << endl;
}

// ==================== Лабораторная работа 4 (Классы и объекты) ====================
class Book {
private:
    string title;
    string author;
    int year;
public:
    Book(string t, string a, int y) : title(t), author(a), year(y) {}
    
    void display() {
        cout << "Книга: " << title << ", Автор: " << author << ", Год: " << year << endl;
    }
    
    bool isOld() {
        return year < 1950;
    }
};

void lab4_task1() {
    cout << "\nЛабораторная работа 4. Задание 1" << endl;
    Book book("Война и мир", "Лев Толстой", 1869);
    book.display();
    cout << (book.isOld() ? "Старая книга" : "Не очень старая книга") << endl;
}

// ==================== Лабораторная работа 5 (Наследование и полиморфизм) ====================
class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() override {
        return width * height;
    }
};

void lab5_task1() {
    cout << "\nЛабораторная работа 5. Задание 1" << endl;
    Shape* shapes[2];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);
    
    for (int i = 0; i < 2; ++i) {
        cout << "Площадь фигуры " << i+1 << ": " << shapes[i]->area() << endl;
        delete shapes[i];
    }
}

// ==================== Лабораторная работа 6 (Шаблоны и STL) ====================
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

void lab6_task1() {
    cout << "\nЛабораторная работа 6. Задание 1" << endl;
    cout << "Максимум из 5 и 10: " << getMax(5, 10) << endl;
    cout << "Максимум из 3.14 и 2.71: " << getMax(3.14, 2.71) << endl;
}

void lab6_task2() {
    cout << "\nЛабораторная работа 6. Задание 2" << endl;
    vector<int> numbers = {5, 2, 8, 1, 9};
    sort(numbers.begin(), numbers.end());
    
    cout << "Отсортированный вектор: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

// ==================== Главная функция ====================
int main() {
    setlocale(LC_ALL, "Russian");
    
    // Вызов всех лабораторных работ
    lab1_task1();
    lab1_task2();
    
    lab2_task1();
    lab2_task2();
    
    lab3_task1();
    
    lab4_task1();
    
    lab5_task1();
    
    lab6_task1();
    lab6_task2();
    
    return 0;
}