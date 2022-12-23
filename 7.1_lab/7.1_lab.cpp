#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    string lineOfLetters;
    cout << "Введите строку на английском из более чем 4 символов : ";
    getline(cin, lineOfLetters); 

    if (lineOfLetters.length() < 4) cout << "Cтрока менее 4 символов.";
    else cout << lineOfLetters.substr(1, 3) << endl;

    int findSymbol = lineOfLetters.find("a"); 

    if (findSymbol >= 0)
        cout << "Индекс символа а - " << findSymbol  << endl;
    else {
        cout << "Символа 'a' не найдено" << endl;
    }
}
