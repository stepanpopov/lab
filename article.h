#ifndef LAB2_1_MAN_H
#define LAB2_1_MAN_H

#include <iostream>

class Article {
public:
    Article(int l_name = 30);

    Article(const Article &pl);

    char *GetName();

    long GetDiameter();

    int GetLifetime();

    int GetKSatellites();

    void SetName(char *tempN);

    void SetDiameter(int tempD);

    void SetLifetime(float tempL);

    void SetKSatellites(float tempKS);

    Article &operator=(const Article &pl);

    bool operator<(Article &pl);

    bool operator==(Article &pl);

    friend std::ostream &operator<<(std::ostream &out, Article &pl);

    friend std::istream &operator>>(std::istream &in, Article &pl);

    ~Article();

private:
    char *name;
    int page;

};


#endif //LAB2_1_MAN_H
