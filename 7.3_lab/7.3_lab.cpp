#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    float radius;
    cout << "Введите радиус окружности = ";
    cin >> radius;

    float circumferenceLenght = 2 * M_PI * radius;
    cout << endl << "Длина окружности = " << circumferenceLenght << endl;

    circumferenceLenght = trunc(circumferenceLenght * 1000 + 0.5) / 1000;
    cout << "Длина окружности = " << circumferenceLenght << endl;

    cin.clear();
    while (cin.get() != '\n');
    string str;
    fstream file;

    while (true) {
        cout << "Введите произвольую строку : ";
        getline(cin, str);

        if (str == "exit") break; 
        else if (str == "read") { 
            cout << "--- файл --- myfile.txt --- начало ---" << endl;
            file.open("myfile.txt", ios::in);
            while (getline(file, str)) {
                cout << str << endl;
            }
            file.close();
            cout << "--- файл --- myfile.txt --- конец ---" << endl;
        }
        else if (str == "erase") { 
            file.open("myfile.txt", ios::out);
            file.close();
            cout << "--- файл --- myfile.txt --- очищен ---" << endl;
        }
        else {
            file.open("myfile.txt", ios::app); 
            file << str << endl;
            file.close();
        }
    }
}