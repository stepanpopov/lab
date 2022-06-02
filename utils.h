#ifndef LAB_UTILS_H
#define LAB_UTILS_H

#include <string>
#include "train_manager.h"


void safe_inp(int &num);

void safe_inp(std::string &s);

void add(train_manager &trains);

void remove(train_manager &trains);

void change(train_manager &trains);

void print_by_num(train_manager &trains);

void print_by_station(train_manager &trains);


void train_num_input(int &num, train_manager &trains);


#endif //LAB_UTILS_H
