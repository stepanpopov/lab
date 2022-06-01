#ifndef LAB_TRAIN_MANAGER_H
#define LAB_TRAIN_MANAGER_H

#include <map>
#include <istream>
#include <ostream>

struct train_pair {
    int time;
    int station;
};

class train_manager {
public:
    train_manager(char *filename);


    friend
    std::ostream &operator<<(std::ostream &out, const term &t);

    friend
    std::istream &operator>>(std::istream &in, term &t);

}


private:
    std::map<int, train_pair> db;

#endif //LAB_TRAIN_MANAGER_H
