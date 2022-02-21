#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "planet.h"

using namespace std;

#define l_name 100

int read_dbase(char *filename, Planet *arr, int &n);

void print_dbase(Planet *arr, int n);

int write_dbase(char *filename, Planet *arr, int n);


int add(Planet *arr, int &n);

int edit(Planet *arr, int n);

int remove(Planet *arr, int &n);

void sort_db(Planet *arr, int n);

// int find(Planet *arr, int n, char *name);

// int find(Planet *arr, int n, int birth_year);

// int find(Planet *arr, int n, float pay);

int menu();

int main() {
    const int N = 100;
    Planet arr[N];
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
                edit(arr, n);
                break;
            case 4:
                write_dbase(filename, arr, n);
                break;
            case 5:
                print_dbase(arr, n);
                break;
            case 6:
                sort_db(arr, n);
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
    cout << "l - добавление планеты\t    4 - вывод базы в файл" << endl;
    cout << "2 - удаление планеты\t    5 - вывод базы на экран" << endl;
    cout << "3 - корректировка сведений  6 - сортировка" << endl;
    cout << "7 - выход" << endl;

    cout << "Для выбора операции введите цифру от 1 до 7" << endl;
    int resp;
    cin >> resp;
    cin.clear();
    cin.ignore(10, '\n');
    return resp;
}

// Чтение базы из файла
int read_dbase(char *filename, Planet *arr, int &n) {
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
    long diameter;
    int lifetime;
    int kSatellites;
    for (int i = 0; i < n; i++) {
        fin >> name >> diameter >> lifetime >> kSatellites;
        arr[i].SetName(name);
        arr[i].SetDiameter(diameter);
        arr[i].SetLifetime(lifetime);
        arr[i].SetKSatellites(kSatellites);
    }

    fin.close();
    return 0;
}

// Вывод базы в файл
int write_dbase(char *filename, Planet *arr, int n) {
    ofstream fout(filename, ios::out);
    if (!fout) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++)
        // fout << arr[i].GetName() << ' ' << arr[i].GetDiameter() << ' ' << arr[i].GetLifetime() <<
        //     ' ' << arr[i].GetKSatellites()<< endl;
        fout << arr[i];

    fout.close();
    return 0;
}

// Вывод базы на экран
void print_dbase(Planet *arr, int n) {
    cout << endl << " База Данных " << endl;
    for (int i = 0; i < n; i++)
        // cout << i + 1 << ' ' << arr[i].GetName() << ' ' << arr[i].GetDiameter() << ' ' << arr[i].GetLifetime() <<
        //                     ' ' << arr[i].GetKSatellites()<< endl;
        cout << i + 1 << ' ' << arr[i];
    cout << endl;
}

/* // Поиск сотрудника в списке по фамилии
int find(Planet *arr, int n, char *name)   // возвращает индес элемента с данными о
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
int find(Planet *arr, int n, int birth_year) {
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
int find(Planet *arr, int n, float pay) {
    int ind = -1;
    for (int i = 0; i < n; i++)
        if (arr[i].GetPay() > pay) {
            ind = i;
            cout << arr[i].GetName() << setw(20 - strlen(arr[i].GetName()) + 6)
                 << arr[i].GetBirthYear() << setw(10) << arr[i].GetPay() << endl;
        }
    return ind;
} */

int add(Planet *arr, int &n) {
    cout << "Введите название планеты" << endl;
    char name[l_name];
    cin >> name;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите ее диаметр" << endl;
    long diameter;
    cin >> diameter;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите продолжительность жизни" << endl;
    int lifetime;
    cin >> lifetime;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите количество спутников" << endl;
    int kSatellites;
    cin >> kSatellites;
    if (cin.fail()) {
        return 1;
    }

    /* Planet Planet(strlen(name));
     Planet.SetPay(pay);
     Planet.SetBirthYear(year);
     Planet.SetName(name);

     arr[n] = Planet;
     */

    arr[n].SetName(name);
    arr[n].SetDiameter(diameter);
    arr[n].SetLifetime(lifetime);
    arr[n].SetKSatellites(kSatellites);

    n++;
    return 0;
}

int edit(Planet *arr, int n) {
    cout << "Какой номер вы хотите изменить?" << endl;
    int tN;
    cin >> tN;
    if (tN < 1 || tN > n) {
        cout << "Неправильный номер" << endl;
        return 1;
    }
    tN--;

    cout << "Введите название планеты" << endl;
    char name[l_name];
    cin >> name;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите ее диаметр" << endl;
    long diameter;
    cin >> diameter;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите продолжительность жизни" << endl;
    int lifetime;
    cin >> lifetime;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите количество спутников" << endl;
    int kSatellites;
    cin >> kSatellites;
    if (cin.fail()) {
        return 1;
    }

    arr[tN].SetName(name);
    arr[tN].SetDiameter(diameter);
    arr[tN].SetLifetime(lifetime);
    arr[tN].SetKSatellites(kSatellites);
    return 0;
}

int remove(Planet *arr, int &n) {
    cout << "Какой номер вы хотите удалить?" << endl;
    int tN;
    cin >> tN;
    if (tN < 0 || tN > n) {
        cout << "Неправильный номер" << endl;
        return 1;
    }
    tN--;

    for (int i = tN; i < n - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    n--;
    return 0;
}

void sort_db(Planet *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                Planet t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}






