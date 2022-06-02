#ifndef LAB_TRAIN_MANAGER_H
#define LAB_TRAIN_MANAGER_H

#include <map>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

struct train_pair {
    struct {
        int h;
        int m;
    } time;
    std::string station;
};

class train_manager {
public:
    train_manager(std::string filename);

    ~train_manager() {
        save_to_db();
    }

    void save_to_db() const;

    void add_train(int num, train_pair pair);

    void delete_train(int num);

    std::vector<std::pair<int, train_pair>> get_by_station(std::string station) const;

    train_pair get_by_num(int num);

    friend
    std::ostream &operator<<(std::ostream &out, const train_manager &t);

    friend
    std::istream &operator>>(std::istream &in, train_manager &t);

private:
    std::map<int, train_pair> db;
    std::string db_filename;
};

std::ostream &operator<<(std::ostream &out, const train_manager &t);
std::istream &operator>>(std::istream &in, train_manager &t);

#endif //LAB_TRAIN_MANAGER_H
