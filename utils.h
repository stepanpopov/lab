#ifndef LAB_UTILS_H
#define LAB_UTILS_H

#include <string>
#include <vector>

#define FILENAME "file.txt"

struct country_t {
    std::string capital;
    int men;
    std::string continent;
};

void safe_inp(int &num);

void safe_inp(std::string &s);

void vec_sort(std::vector<country_t> &countries);

void add(std::vector<country_t> &countries);

void remove(std::vector <country_t> &countries);

void print(std::vector<country_t> &countries);

void change(std::vector<country_t> &countries);

void save_to_file(std::vector<country_t> &countries, std::string file_name);

void read_from_file(std::vector <country_t> &countries, std::string file_name);

#endif //LAB_UTILS_H
