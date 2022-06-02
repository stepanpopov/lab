#include "train_manager.h"
#include <fstream>

#include <iostream>

train_manager::train_manager(std::string filename) : db_filename(filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cout << "Файл не найден. Сформируйте каталог." << std::endl;   // !!!!
    } else {
        while (in) {
            int h, m;
            int num;
            std::string station;

            in >> num >> h >> m >> station;
            if (station == "") break;
            db[num] = {{h, m}, station};
        }
        in.close();
    }
}

void train_manager::save_to_db() const {
    std::ofstream out(db_filename);
    if (!out) {
        std::cout << "Файл не найден. Сформируйте каталог." << std::endl;
    }
    for (const auto &it : db) {
        out << it.first << " " << it.second.time.h << " " << it.second.time.m << " " << it.second.station << std::endl;
    }
    out.close();
}

void train_manager::add_train(int num, train_pair pair) {
    db[num] = pair;
}

void train_manager::delete_train(int num) {
    db.erase(num);
}

std::vector<std::pair<int, train_pair>> train_manager::get_by_station(std::string station) const {

    std::vector<std::pair<int, train_pair>> trains;

    for (const auto &it : db) {
        if (it.second.station == station) {
            trains.push_back({it.first, {{it.second.time.h, it.second.time.m}, it.second.station}} );
        }
    }
    return trains;
}

train_pair train_manager::get_by_num(int num) {    // ?????
    return db[num];
}

std::ostream &operator<<(std::ostream &out, const train_manager &t) {
    for (const auto &it : t.db) {
        out << it.first << " " << it.second.time.h << ":" << it.second.time.m << " " << it.second.station << std::endl;
    }
    return out;
}


std::istream &operator>>(std::istream &in, train_manager &t) {
    int h, m;
    int num;
    std::string station;

    in >> num >> h >> m >> station;
    t.db[num] = {{h, m}, station};
    return in;
}