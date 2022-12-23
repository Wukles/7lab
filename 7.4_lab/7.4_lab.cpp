#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Settings {

private:
    //map<string, string> myMap; 
    static map<string, string> myMap; 

public:

    Settings(string key, string value)
    {
        myMap[key] = value;
    }

    ~Settings() {}

    //void add(string key, string value) { 
    static void add(string key, string value) { 
        myMap.insert(pair<string, string>(key, value));
    }

    //string get(string key) { 
    static string get(string key) { 
        //return myMap[key];
        map<string, string>::iterator i;
        i = myMap.find(key);
        return i->second;
    }

    //void print() { 
    static void print() { 
        cout << endl;
        for (auto i = myMap.begin(); i != myMap.end(); i++)
            cout << i->first << " >> " << i->second << endl;
        cout << endl;
    }
};

map<string, string> Settings::myMap;

void vecInConsol(vector<float> vfloat) { 
    cout  << endl;
    for (float n : vfloat) cout << n << " ";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "");

    vector<float> vec;

    vec = { 75.9f, 4.6, 1.2f, 39.7, 51.16f };

    vecInConsol(vec);

    vec.insert(vec.begin() + 3, 38.125);

    vecInConsol(vec);

    vec.erase(vec.end() - 1);

    vecInConsol(vec);

    /* 
    Settings mySet("menu", "меню");
    mySet.add("one", "первый");
    mySet.add("two", "второй");
    mySet.add("three", "третий");
    mySet.print();
    cout << "Значение, соотвествующее 'three' - " << mySet.get("three") << endl;
    */

    Settings staticMySet("menu", "меню");
    staticMySet.add("one", "первый");
    staticMySet.add("two", "второй");
    staticMySet.add("three", "третий");
    staticMySet.print();
    cout << "Значение, соотвествующее 'three' - " << staticMySet.get("three") << endl;
}