#include "utils.h"

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

void safe_inp(int &num) {
    string s;
    while (1) {
        cin >> s;
        bool flag = 1;
        for (int i = 0; i < s.size(); i++) {
            if (!isdigit(s[i])) {
                flag = 0;
                cout << "Неправильный ввод" << endl;
                break;
            }
        }
        if (flag) break;
    }
    num = stoi(s);
}

void safe_inp(string &s) {
    while (1) {
        cin >> s;

        bool flag = 1;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                flag = 0;
                cout << "Неправильный ввод" << endl;
                break;
            }
        }
        if (flag) break;
    }
}

void add(vector<country_t> &countries) {
    cout << "Введите столицу: ";
    string capital;
    safe_inp(capital);

    cout << "Введите численность населения: ";
    int men;
    safe_inp(men);

    cout << "Введите континент: ";
    string continent;
    safe_inp(continent);
    cout << endl;

    country_t temp;
    temp.continent = continent;
    temp.men = men;
    temp.capital = capital;
    countries.push_back(temp);
}

void print(vector<country_t> &countries) {
    cout << "Текущий каталог:" << endl;
    int k = 1;
    for (country_t i: countries) {
        cout << k << endl;
        cout << "Столица: " << i.capital << endl;
        cout << "Численность населения: " << i.men << endl;
        cout << "Континент: " << i.continent << endl << endl;
        k++;
    }
    cout << endl;
}

void change(std::vector<country_t> &countries) {  // !!!
    cout << "Введие номер структуры, которую хотите изменить: ";
    int num_country;
    while (1) {          // !!!
        safe_inp(num_country);
        if (num_country > countries.size() || num_country <= 0) {
            cout << "Неправильный ввод" << endl;
        } else {
            break;
        }
    }

    cout << "Вы хотите изменить ее полностью? (y/n) ";
    char ans;
    cin >> ans;             // !!!
    if (ans == 'y') {
        cout << "Введите столицу: ";
        string capital;
        safe_inp(capital);

        cout << "Введите численность населения: ";
        int men;
        safe_inp(men);

        cout << "Введите континент: ";
        string continent;
        safe_inp(continent);

        countries[num_country - 1].continent = continent;
        countries[num_country - 1].men = men;
        countries[num_country - 1].capital = capital;
    } else if (ans == 'n') {
        cout << "Что вы хотите изменить? (столица, численность, континент) ";
        string change;
        while (1) {
            safe_inp(change);
            if (change == "столица" || change == "численность" || change == "континент") {
                break;
            } else {
                cout << "Неправильный ввод" << endl;
            }
        }
        cout << endl;

        cout << "Введите выбранное поле: ";

        if (change == "столица") {
            string capital;
            safe_inp(capital);

            countries[num_country - 1].capital = capital;
        } else if (change == "численность населения") {
            int men;
            safe_inp(men);

            countries[num_country - 1].men = men;
        } else if (change == "континент") {
            string continent;
            safe_inp(continent);

            countries[num_country - 1].continent = continent;
        }
    }
    cout << endl;
}

void remove(std::vector<country_t> &countries) {
    if(countries.size() == 0) {
        cout << "Каталог пуст" << endl;
        return;
    }

    cout << "Введие номер структуры, которую хотите удалить: ";
    int num_country;
    while (1) {              // !!!
        safe_inp(num_country);

        if (num_country > countries.size() || num_country <= 0) {
            cout << "Неправильный ввод" << endl;
        } else {
            break;
        }
    }

    countries.erase(countries.begin() + num_country - 1);
}

void vec_sort(std::vector<country_t> &countries) {
    sort(countries.begin(), countries.end(),
         [](const country_t &a, const country_t &b) -> bool {
             return (a.capital < b.capital);
         });
}

void save_to_file(std::vector<country_t> &countries, std::string file_name) {

    ofstream out(file_name);
    for (int i = 0; i < countries.size(); i++) {
        out << countries[i].capital << " "
            << countries[i].men << " "
            << countries[i].continent << endl;
    }
    out.close();
    cout << "Каталог успешно сохранен" << endl << endl;
}

void read_from_file(std::vector<country_t> &countries, std::string file_name) {
    ifstream in(file_name);

    if (!in) {
        cout << "Файл не найден. Сформируйте каталог." << endl;
        return;
    }

    while (in) {
        country_t temp;
        in >> temp.capital >> temp.men >> temp.continent;
        if (temp.continent == "") break;
        countries.push_back(temp);
    }
    in.close();
}