#include <iostream>
#include "train_manager.h"

using namespace std;


int main () {
    train_manager trains("");

    // print(countries);

    int state = -1;
    while (state != 5) {
        cout << "[1] Добавить поезд в базу" << endl;
        cout << "[2] Редактировать поезд в базе" << endl;
        cout << "[3] Удалить поезд из базы" << endl;
        cout << "[4] Сохранить базу данных в файл" << endl;
        cout << "[5] Выход" << endl;
        cout << endl;

        safe_inp(state);

        switch(state) {
            case 1:
                add(countries);
                vec_sort(countries);
                print(countries);
                break;
            case 2:
                print(countries);
                change(countries);
                print(countries);
                break;
            case 3:
                print(countries);
                remove(countries);
                print(countries);
                break;
            case 4:
                save_to_file(countries, FILENAME);
                break;
            case 5:
                cout << "Выход" << endl;
                break;
            default:
                cout << "Такого пункта в меню нет" << endl;
                break;
        }
    }


    return 0;
}