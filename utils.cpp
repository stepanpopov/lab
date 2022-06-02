#include "utils.h"

#include <iostream>
#include <vector>

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

void add(train_manager &trains) {
    cout << "Введите номер поезда: ";
    int num;
    safe_inp(num);

    cout << "Введите станцию назначения: ";
    string station;
    safe_inp(station);

    int h, m;
    while (1) {
        cout << "Введите время отправления (h, m): ";
        safe_inp(h);
        safe_inp(m);
        if (h < 0 || h >= 24 || m < 0 || m >= 60) {
            cout << "Неправильный ввод" << endl;
        } else break;
    }
    cout << endl;

    trains.add_train(num, {{h, m}, station});
}

void change(train_manager &trains) {
    cout << "Введие номер поезда, информацию о котором хотите изменить: ";
    int num;
    train_num_input(num, trains);

    add(trains);
}

void remove(train_manager &trains) {
    cout << "Введие номер поезда, информацию о котором хотите удалить: ";
    int num;
    train_num_input(num, trains);

    trains.delete_train(num);
}

void print_by_num(train_manager &trains) {
    cout << "Введие номер поезда, информацию о котором хотите получить: ";
    int num;
    train_num_input(num, trains);

    train_pair p = trains.get_by_num(num);
    cout << num << " " << p.time.h << ":" << p.time.m << " " << p.station << endl << endl;
}

void print_by_station(train_manager &trains) {
    cout << "Введите станцию назначения, о которой хотите получить информацию: ";
    string station;
    safe_inp(station);

    vector <pair<int, train_pair>> vec = trains.get_by_station(station);
    if (vec.size() == 0) {
        cout << "Поезда до этой станции не ходят" << endl;
    } else {
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i].first << " " << vec[i].second.time.h << ":" << vec[i].second.time.m << " " <<
                 vec[i].second.station << endl;
        }
    }
    cout << endl;
}


void train_num_input(int &num, train_manager &trains) {
    while (1) {
        safe_inp(num);
        if (trains.get_by_num(num).station == "") {
            cout << "Такого поезда в базе нет" << endl;
        } else {
            break;
        }
    }
}