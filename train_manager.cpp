#include "train_manager.h"

#include <ifstream>
#include <ofstream>
// #include <vector>

train_manager::train_manager(std::string filename) {

    std::ifstream in(filename);
    if (!in) {
        // cout << "Файл не найден. Сформируйте каталог." << endl;   !!!!
    } else {
        while (in) {
            int num;
            int time;
            std::string station;

            in >> num >> time >> station;
            if (station == "") break;
            db[num] = {time, station};
        }
        in.close();
    }
}

void train_manager::save_to_db(std::string filename) const {
    std::ofstream out(filename);

    for (const auto &it : db) {
        out << it.first << " " << it.second.time << " " << it.second.station << std::endl;
    }

    out.close();
    // cout << "Каталог успешно сохранен" << endl << endl;  !!!!
}

void train_manager::add_train(int num, train_pair pair) {
    db[num] = pair;
}

void train_manager::delete_train(int num) {
    db.erase(num);
}

std::vector<std::pair> train_manager::get_by_station(std::string station) const {
    std::vector<std::pair> trains;

    for (const auto &it : db) {
        if (it.second.station == station) {
            trains.push_back(it);
        }
    }
    return trains;
}

train_pair train_manager::get_by_num(int num) const {
    return db[num];
}

std::ostream &operator<<(std::ostream &out, const train_manager &t) {
    for (const auto &it : t.db) {
        out << it.first << " " << it.second.time << " " << it.second.station << std::endl;
    }
}


std::istream &operator>>(std::istream &in, train_manager &t) {

}