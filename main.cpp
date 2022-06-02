#include <iostream>
#include "train_manager.h"
#include "utils.h"

using namespace std;

static string FILENAME = "db.txt";

int main () {
    train_manager trains(FILENAME);

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
                add(trains);
                break;
            case 2:
                change(trains);
                break;
            case 3:
                remove(trains);
                break;
            case 4:
                trains.save_to_db();
                break;
            case 5:
                cout << trains << endl;
                break;
            case 6:
                print_by_num(trains);
                break;
            case 7:
                print_by_station(trains);
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