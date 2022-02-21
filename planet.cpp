#include "planet.h"
#include <cstring>


Planet::Planet(int l_name) {
    name = new char[l_name + 1];
}

Planet::Planet(const Planet &pl) : diameter(pl.diameter),
                                   lifetime(pl.lifetime),
                                   kSatellites(pl.kSatellites) {
    name = new char[strlen(pl.name) + 1];
    this->SetName(pl.name);
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
    strncpy(name, tempName, n);
    name[n] = '\0';
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

Planet &Planet::operator=(const Planet &pl) {
    diameter = pl.diameter;
    lifetime = pl.lifetime;
    kSatellites = pl.kSatellites;

    if (!name) delete name;
    name = new char[strlen(pl.name) + 1];
    this->SetName(pl.name);

    return *this;
}

bool Planet::operator<(Planet &pl) {
    return (this->diameter < pl.diameter);
}

bool Planet::operator==(Planet &pl) {
    return (this->diameter == pl.diameter);
}

std::ostream &operator<<(std::ostream &out, Planet &pl) {
    out << pl.name << ' ' << pl.diameter << ' ' << pl.lifetime << ' ' << pl.kSatellites << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, Planet &pl) {
    in >> pl.name >> pl.diameter >> pl.lifetime >> pl.kSatellites;
    return in;
}






