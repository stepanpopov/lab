#ifndef LAB2_1_MAN_H
#define LAB2_1_MAN_H

// #define l_name  20
#include <fstream>

class Planet {
public:
    Man(int l_name = 30);

    char * GetName();
    long GetDiameter();
    int GetLifetime();
    int GetKSatellites();

    void SetName(char * tempN);
    void SetDiameter(int tempD);
    void SetLifetime(float tempL);
    void SetKSatellites(float tempKS);

    bool operator <(Planet &pl);
    bool operator ==(Planet &pl);

    friend ofstream& operator<<(ofstream& out, Planet &pl);
    friend ifstream& operator>>(ifstream& in, Planet &pl);

    ~Man();

private:
    char *name;
    long diameter;
    int lifetime;
    int kSatellites;
};


#endif //LAB2_1_MAN_H
