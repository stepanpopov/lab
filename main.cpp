/*В текстовом файле хранится база отдела кадров предприятия. На предприятии не более 100 сотрудников.
Каждая строка файла содержит запись об одном сотруднике. Первая запись в файле –
фактическое число сотрудников. Формат записи:
	фамилия (не более 20 позиций),
	год рождения (4 позиции),
	оклад (не более 8 позиций).
Написать программу, которая позволяла бы выводить на экран сведения о сотрудниках,
добавлять и удалять сотрудников из БД, корректировать данные о сотрудниках.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "man.h"

using namespace std;

#define l_name 100

int read_dbase(char *filename, Man *arr, int &n);

void print_dbase(Man *arr, int n);

int write_dbase(char *filename, Man *arr, int n);


int add(Man *arr, int &n);

int edit(Man *arr, int n);

int remove(Man *arr, int &n);

int find(Man *arr, int n, char *name);

int find(Man *arr, int n, int birth_year);

int find(Man *arr, int n, float pay);

int menu();

int menu_f();

void find_man(Man *arr, int n);


int main() {
    const int N = 100;
    Man arr[N];
    char *filename = "dbase.txt";
    int n;
    //чтение БД в ОП
    if (read_dbase(filename, arr, n)) {
        cout << "Ошибка чтения БД" << endl;
        return 1;
    }
    print_dbase(arr, n);
    while (true) {
        switch (menu()) {
            case 1:
                add(arr, n);
                break;
            case 2:
                remove(arr, n);
                break;
            case 3:
                find_man(arr, n);
                break;
            case 4:
                edit(arr, n);
                break;
            case 5:
                print_dbase(arr, n);
                break;
            case 6:
                write_dbase(filename, arr, n);
                break;
            case 7:
                return 0;
            default:
                cout << " Недопустимый номер операции" << endl;
                break;
        }
    }
    return 0;
}


int menu() {
    cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
    cout << "l - добавление сотрудника\t 4 - корректировка сведений" << endl;
    cout << "2 - удаление coтpyдникa\t\t 5 - вывод базы на экран" << endl;
    cout << "3 - поиск сотрудника\t\t 6 - вывод базы в файл" << endl;
    cout << "\t\t\t\t 7 - выход" << endl;
    cout << "Для выбора операции введите цифру от 1 до 7" << endl;
    int resp;
    cin >> resp;
    cin.clear();
    cin.ignore(10, '\n');
    return resp;
}

int menu_f() {
    cout << "\n----------------- ПОИСК -----------------\n";
    cout << "1 - поиск по фамилии	 2 - по году рождения\n"
         << "3 - по окладу		 4 - конец поиска\n ";
    cout << "Для выбора операции введите число от 1 до 4\n";
    int resp;
    cin >> resp;
    cin.clear();
    cin.ignore(10, '\n');
    return resp;
}

// Поиск
void find_man(Man *arr, int n) {
    char buf[l_name];
    int birth_year;
    float pay;

    while (true) {
        switch (menu_f()) {
            case 1:
                cout << "Введите фамилию сотрудника\n";
                cin >> buf;
                if (find(arr, n, buf) < 0)
                    cout << "Сотрудника с фамилией " << buf << " в списке нет\n";
                break;
            case 2:
                cout << "Введите год рождения" << endl;
                cin >> birth_year;
                if (find(arr, n, birth_year) < 0)
                    cout << "В списке нет сотрудников, родившихся до "
                         << birth_year << " года\n";
                break;
            case 3:
                cout << "Введите оклад" << endl;
                cin >> pay;
                if (find(arr, n, pay) < 0)
                    cout << "В списке нет сотрудников с окладом, большим "
                         << pay << " руб.\n";
                break;
            case 4:
                return;
            default:
                cout << "Неверный ввод\n";
        }

    }
}

// Чтение базы из файла
int read_dbase(char *filename, Man *arr, int &n) {
    ifstream fin(filename, ios::in);
    if (!fin) {
        cout << "Heт файла " << filename << endl;
        return 1;
    }
    fin >> n;
    if (n > 100) {
        cout << "Переполнение БД. n= " << n << endl;
        return 1;
    }

    char name[l_name];
    int birth_year;
    float pay;
    for (int i = 0; i < n; i++) {
        fin >> name >> birth_year >> pay;
        arr[i].SetName(name);
        arr[i].SetBirthYear(birth_year);
        arr[i].SetPay(pay);
    }

    fin.close();
    return 0;
}

// Вывод базы в файл
int write_dbase(char *filename, Man *arr, int n) {
    ofstream fout(filename, ios::out);
    if (!fout) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }
    fout << n;
    for (int i = 0; i < n; i++)
        fout << arr[i].GetName() << ' ' << arr[i].GetBirthYear() << ' ' << arr[i].GetPay() << endl;

    fout.close();
    return 0;
}

// Вывод базы на экран
void print_dbase(Man *arr, int n) {
    cout << " База Данных " << endl;
    for (int i = 0; i < n; i++)
        cout << setw(3) << i + 1 << ". " << arr[i].GetName() << setw(20 - strlen(arr[i].GetName()) + 6)
             << arr[i].GetBirthYear() << setw(10) << arr[i].GetPay() << endl;
}

// Поиск сотрудника в списке по фамилии
int find(Man *arr, int n, char *name)   // возвращает индес элемента с данными о
                                        // сотруднике в БД,реализованной в виде массива
{
    int ind = -1;
    for (int i = 0; i < n; i++)
        if (!strcmp(arr[i].GetName(), name)) {
            cout << arr[i].GetName() << setw(20 - strlen(arr[i].GetName()) + 6)
                 << arr[i].GetBirthYear() << setw(10) << arr[i].GetPay() << endl;
            ind = i;
        }
    return ind;
}

// Поиск и вывод более старших по возрасту сотрудников
int find(Man *arr, int n, int birth_year) {
    int ind = -1;
    for (int i = 0; i < n; i++)
        if (arr[i].GetBirthYear() < birth_year) {
            ind = i;
            cout << arr[i].GetName() << setw(20 - strlen(arr[i].GetName()) + 6)
                 << arr[i].GetBirthYear() << setw(10) << arr[i].GetPay() << endl;
        }
    return ind;
}

// Поиск и вывод сотрудников с окладом, большим чем "pay"
int find(Man *arr, int n, float pay) {
    int ind = -1;
    for (int i = 0; i < n; i++)
        if (arr[i].GetPay() > pay) {
            ind = i;
            cout << arr[i].GetName() << setw(20 - strlen(arr[i].GetName()) + 6)
                 << arr[i].GetBirthYear() << setw(10) << arr[i].GetPay() << endl;
        }
    return ind;
}

int add(Man *arr, int &n) {
    cout << "Введите фамилию сотрудника" << endl;
    char name[l_name];
    cin >> name;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите год его рождения" << endl;
    int year;
    cin >> year;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите его заработную плату" << endl;
    float pay;
    cin >> pay;
    if (cin.fail()) {
        return 1;
    }

   /* Man man(strlen(name));
    man.SetPay(pay);
    man.SetBirthYear(year);
    man.SetName(name);

    arr[n] = man;
    */

    arr[n].SetPay(pay);
    arr[n].SetBirthYear(year);
    arr[n].SetName(name);

    n++;
    return 0;
}

int edit(Man *arr, int n) {
    cout << "Какой номер вы хотите изменить?" << endl;
    int tN;
    cin >> tN;
    if (tN < 0 || tN >= n) {
        cout << "Неправильный номер" << endl;
        return 1;
    }
    tN++;

    cout << "Введите фамилию сотрудника" << endl;
    char name[l_name];
    cin >> name;

    if (cin.fail()) {
        return 1;
    }

    cout << "Введите год его рождения" << endl;
    int year;
    cin >> year;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите его заработную плату" << endl;
    float pay;
    cin >> pay;
    if (cin.fail()) {
        return 1;
    }

    arr[tN].SetName(name);
    arr[tN].SetBirthYear(year);
    arr[tN].SetPay(pay);
    return 0;
}

int remove(Man *arr, int &n) {
    cout << "Какой номер вы хотите удалить?" << endl;
    int tN;
    cin >> tN;
    if (tN < 0 || tN >= n) {
        cout << "Неправильный номер" << endl;
        return 1;
    }
    tN++;

    for (int i = tN; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    n--;
    return 0;
}




