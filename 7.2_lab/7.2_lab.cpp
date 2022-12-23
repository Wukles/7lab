#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    string myName;
    cout << "Введите ваше имя : ";
    cin >> myName;

    regex nameReg("^([A-ZА-ЯЁ])[a-zа-яё]{1,31}$");
    if (regex_match(myName, nameReg)) cout << "Корректный ввод";
    else cout << "Не корректный ввод ";
    cout << endl;

    string emailstring = "гонки журнал жена bracokacimmu-2482@mail.com формироваться знать посвятить нос место входной должность больной рабочий couprizenuffu-4968@mail.com пост вызывать выскочить прозвучать гордиться trorattougebu-5768@mail.com генеральный пожарный предоставлять независимый ";

    regex emailReg("[a-z0-9_][a-z0-9_\.-]*[a-z0-9_]@([a-z0-9]+[a-z0-9_-]*[a-z0-9]\.)+[a-z0-9]{2,5}", regex_constants::icase);
    smatch match;

    cout << "Строка до обработки :" << endl << emailstring << endl;
    while (regex_search(emailstring, match, emailReg)) {
        cout << "Aдрес - " << match.str(0) << endl;
        emailstring.erase(emailstring.find(match.str(0)), match.str(0).length());
    }
    cout << "Строка без адресов" << endl << emailstring << endl;
}