#ifndef LAB2_1_MAN_H
#define LAB2_1_MAN_H

// #define l_name  20
// #include <fstream>
#include <iostream>

class Planet {
public:
    Planet(int l_name = 30);

    Planet(const Planet &pl);

    char *GetName();

    long GetDiameter();

    int GetLifetime();

    int GetKSatellites();

    void SetName(char *tempN);

    void SetDiameter(int tempD);

    void SetLifetime(float tempL);

    void SetKSatellites(float tempKS);

    Planet &operator=(const Planet &pl);

    bool operator<(Planet &pl);

    bool operator==(Planet &pl);

    friend std::ostream &operator<<(std::ostream &out, Planet &pl);

    friend std::istream &operator>>(std::istream &in, Planet &pl);

    ~Planet();

private:
    char *name;
    long diameter;
    int lifetime;
    int kSatellites;
};


#endif //LAB2_1_MAN_H
