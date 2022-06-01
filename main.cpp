#include <iostream>
#include "train_manager.h"
#include <string>

using namespace std;

static string FILENAME = "";

int main () {
    train_manager trains(FILENAME);

    // print(countries);

    int state = -1;
    while (state != 8) {
        cout << "[1] Добавить поезд в базу" << endl;
        cout << "[2] Редактировать поезд в базе" << endl;
        cout << "[3] Удалить поезд из базы" << endl;
        cout << "[4] Сохранить базу данных в файл" << endl;
        cout << "[5] Вывод сведений по всем поездам" << endl;
        cout << "[6] Вывод сведений по поезду с запрошенным номером" << endl;
        cout << "[7] Вывод сведений по тем поездам, которые следуют до запрошенной станции" << endl;
        cout << "[8] Выход" << endl;
        cout << endl;

        safe_inp(state);

        switch(state) {
            case 1:
                // string
                train.add()
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
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                cout << "Выход" << endl;
                break;
            default:
                cout << "Такого пункта в меню нет" << endl;
                break;
        }
    }


    return 0;
}