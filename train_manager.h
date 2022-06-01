#ifndef LAB_TRAIN_MANAGER_H
#define LAB_TRAIN_MANAGER_H

#include <map>
#include <istream>
#include <ostream>
#include <string>
#include <pair>
#include <vector>

struct train_pair {
    int time;
    string station;
};

class train_manager {
public:
    train_manager(std::string filename);

    void save_to_db(std::string filename) const;

    void add_train(int num, train_pair pair);

    void delete_train(int num);

    std::vector<std::pair> get_by_station(std::string station) const;

    train_pair get_by_num(int num) const;

    friend
    std::ostream &operator<<(std::ostream &out, const train_manager &t);

    friend
    std::istream &operator>>(std::istream &in, train_manager &t);

private:
    std::map<int, train_pair> db;
};

std::ostream &operator<<(std::ostream &out, const train_manager &t);

#endif //LAB_TRAIN_MANAGER_H
