#include <iostream>
#include <iomanip>
#include"dbmsLib.h"

#define PRODUCTS_FILE "Products.txt"
#define ORDER_DETAILS_FILE "OrderDetails.txt"


using namespace std;

int menu() {
    cout << "================= МАКЕТ СУБД ===================\n";
    cout << "\t1 - Чтение таблицы из файла\n";
    cout << "\t2 - Печать таблицы\n";
    cout << "\t3 - Запись таблицы в файл\n";
    cout << "\t4 - Подсчет дохода компаний\n";
    cout << "\t5 - Выход\n";

    int choice;
    cout << "Выберите действие\n";
    cin >> choice;
    while (cin.fail()) {
        cout << "Ошибка ввода. Повторите ввод\n";
        cin.clear();
        cin.ignore(10, '\n');
        cin >> choice;
    }
    return choice;
}

//=================================================
int main() {
    // system("chcp 1251>nul");
    // int StudentID = 0, index = -1, size = 0;

    // char buff[20];

    // vector<int> v;
    // void *adress;
    // dbmsLib::Row row;
    // string name;
    dbmsLib::DBTableTxt products(PRODUCTS_FILE);
    dbmsLib::DBTableTxt orders(ORDER_DETAILS_FILE);

    while (true) {
        // row.clear();
        switch (menu()) {
            case 1:
                products.ReadDBTable(PRODUCTS_FILE);
                orders.ReadDBTable(ORDER_DETAILS_FILE);
            case 2:
                products.PrintTable(80);
                orders.PrintTable(80);
                break;
            case 3:
                products.WriteDBTable(PRODUCTS_FILE);
                orders.WriteDBTable(ORDER_DETAILS_FILE);
                break;
            case 4:

                break;
            case 5:
                return 0;
                break;
           case 6://Перевести студента в другую группу
                cout << "Введите StudentID: ";
                cin >> StudentID;
                v = stud.IndexOfRecord(&StudentID, (string) "StudentID");
                cout << endl << v[0] << ' ' << v.size() << endl;
                row = stud.GetRow(v[0]);

                cout << "Введите новый шифр группы: ";
                cin >> name;

                adress = dbmsLib::GetValue((char *) name.c_str(), (string) "Group", stud.GetHeader());
                row[(string) "Group"] = adress;

                stud.AddRow(row, v[0]);
                stud.PrintTable(80);
                break;
            /*case 6: //Распечатать фамилию студента, StudentID которого равен 3
                StudentID = 3;
                v = stud.IndexOfRecord(&StudentID, (string) "StudentID");
                row = stud.GetRow(v[0]);
                cout << stud.valueToString(row, (string) "Name") << endl;
                break;
            case 7: //Увеличить на 1 количество экземпляров всех книг в библиотеке
                size = book.GetSize();
                for (int i = 0; i < size; i++) {
                    row = book.GetRow(i);
                    name = book.valueToString(row, (string) "Quantity");
                    index = atoi(name.c_str());
                    cout << atoi(name.c_str()) << endl;
                    index++;
                    _itoa_s(index, buff, 20, 10);
                    name = buff;
                    adress = dbmsLib::GetValue(name, (string) "Quantity", book.GetHeader());
                    row[(string) "Quantity"] = adress;
                    book.AddRow(row, i);
                }
                break;
            case 8:
                break;
            case 10:
                return 0;//завершение работы */
            default:
                cout << "Недопустимое действие. Повторите выбор\n";
                break;
        }
    }
    return 0;
}