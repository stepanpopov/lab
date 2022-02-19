#include "planet.h"
#include <cstring>


Planet::Planet(int l_name) {
    name = new char[l_name + 1];
}

Planet::~Planet() {
    delete[] name;
}

char *Planet::GetName() {
    return name;
}

long Planet::GetDiameter() {
    return diameter;
}

int Planet::GetLifetime() {
    return lifetime;
}

int Planet::GetKSatellites() {
    return kSatellites;
}

void Planet::SetName(char *tempName) {
    int n = strlen(tempName);
    strncpy(pName, tempName, n);
    pName[n] = '\0';
}

void Planet::SetDiameter(int tempD) {
    diameter = tempD;
}

void Planet::SetLifetime(float tempL) {
    lifetime = tempL;
}

void Planet::SetKSatellites(float tempKS) {
    kSatellites = tempKS;
}

bool operator<(Planet &pl) {
    return (this->diameter < pl.diameter);
}

bool operator==(Planet &pl) {
    return (this->diameter == pl.diameter);
}

ofstream &operator<<(ofstream &out, Planet &pl) {
    out << ' ' << pl.name << ' ' << pl.diameter << ' ' << pl.lifetime << ' ' << pl.kSatellites << '\n';
    return out;
}

ifstream &operator>>(ifstream &in, Planet &pl) {
    in >> pl.name >> pl.diameter >> pl.lifetime >> pl.kSatellites << '\n';
    return out;
}






