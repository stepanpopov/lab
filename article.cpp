#include "article.h"
#include <cstring>


Article::Article(int l_name) {
    name = new char[l_name + 1];
}

Article::Article(const Article &pl) : diameter(pl.diameter),
                                   lifetime(pl.lifetime),
                                   kSatellites(pl.kSatellites) {
    name = new char[strlen(pl.name) + 1];
    this->SetName(pl.name);
}

Article::~Article() {
    delete[] name;
}

char *Article::GetName() {
    return name;
}

long Article::GetDiameter() {
    return diameter;
}

int Article::GetLifetime() {
    return lifetime;
}

int Article::GetKSatellites() {
    return kSatellites;
}

void Article::SetName(char *tempName) {
    int n = strlen(tempName);
    strncpy(name, tempName, n);
    name[n] = '\0';
}

void Article::SetDiameter(int tempD) {
    diameter = tempD;
}

void Article::SetLifetime(float tempL) {
    lifetime = tempL;
}

void Article::SetKSatellites(float tempKS) {
    kSatellites = tempKS;
}

Article &Article::operator=(const Article &pl) {
    diameter = pl.diameter;
    lifetime = pl.lifetime;
    kSatellites = pl.kSatellites;

    if (!name) delete name;
    name = new char[strlen(pl.name) + 1];
    this->SetName(pl.name);

    return *this;
}

bool Article::operator<(Article &pl) {
    return (this->diameter < pl.diameter);
}

bool Article::operator==(Article &pl) {
    return (this->diameter == pl.diameter);
}

std::ostream &operator<<(std::ostream &out, Article &pl) {
    out << pl.name << ' ' << pl.diameter << ' ' << pl.lifetime << ' ' << pl.kSatellites << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, Article &pl) {
    in >> pl.name >> pl.diameter >> pl.lifetime >> pl.kSatellites;
    return in;
}






