#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "article.h"

using namespace std;

#define l_name 100

int read_dbase(char *filename, Article *arr, int &n);

void print_dbase(Article *arr, int n);

int write_dbase(char *filename, Article *arr, int n);


int add(Article *arr, int &n);

int edit(Article *arr, int n);

int remove(Article *arr, int &n);

void sort_db(Article *arr, int n);

int menu();

int main() {
    const int N = 100;
    Article arr[N];
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
    cout << "l - добавление статьи\t    4 - вывод базы в файл" << endl;
    cout << "2 - удаление статьи\t    5 - вывод базы на экран" << endl;
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
int read_dbase(char *filename, Article *arr, int &n) {
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
    int words;
    int page;
    for (int i = 0; i < n; i++) {
        fin >> name >> words >> page;
        arr[i].SetName(name);
        arr[i].SetWords(words);
        arr[i].SetPage(page);
    }

    fin.close();
    return 0;
}

// Вывод базы в файл
int write_dbase(char *filename, Article *arr, int n) {
    ofstream fout(filename, ios::out);
    if (!fout) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i];

    fout.close();
    return 0;
}

// Вывод базы на экран
void print_dbase(Article *arr, int n) {
    cout << endl << " База Данных " << endl;
    for (int i = 0; i < n; i++)
        cout << i + 1 << ' ' << arr[i];
    cout << endl;
}

int add(Article *arr, int &n) {
    cout << "Введите название планеты" << endl;
    char name[l_name];
    cin >> name;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите ее количество слов в статье" << endl;
    int words;
    cin >> words;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите страницу журнала" << endl;
    int page;
    cin >> page;
    if (cin.fail()) {
        return 1;
    }

    arr[n].SetName(name);
    arr[n].SetWords(words);
    arr[n].SetPage(page);

    n++;
    return 0;
}

int edit(Article *arr, int n) {
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

    cout << "Введите ее количество слов в статье" << endl;
    int words;
    cin >> words;
    if (cin.fail()) {
        return 1;
    }

    cout << "Введите страницу журнала" << endl;
    int page;
    cin >> page;
    if (cin.fail()) {
        return 1;
    }

    arr[tN].SetName(name);
    arr[tN].SetWords(words);
    arr[tN].SetPage(page);
    return 0;
}

int remove(Article *arr, int &n) {
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

void sort_db(Article *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                Article t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}






