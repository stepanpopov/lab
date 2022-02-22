#include "article.h"
#include <cstring>


Article::Article(int l_name) {
    name = new char[l_name + 1];
}

Article::Article(const Article &ar) : page(ar.page),
                                      words(ar.words) {
    name = new char[strlen(ar.name) + 1];
    this->SetName(ar.name);
}

Article::~Article() {
    delete[] name;
}

char *Article::GetName() {
    return name;
}

long Article::GetPage() {
    return page;
}

int Article::GetWords() {
    return words;
}

void Article::SetName(char *tempName) {
    int n = strlen(tempName);
    strncpy(name, tempName, n);
    name[n] = '\0';
}

void Article::SetPage(int tempP) {
    page = tempP;
}

void Article::SetWords(int tempW) {
    words = tempW;
}

Article &Article::operator=(const Article &ar) {
    page = ar.page;
    words = ar.words;

    if (!name) delete name;
    name = new char[strlen(ar.name) + 1];
    this->SetName(ar.name);

    return *this;
}

bool Article::operator<(Article &ar) {
    return (this->words < ar.words);
}

bool Article::operator==(Article &ar) {
    return (this->words == ar.words);
}

std::ostream &operator<<(std::ostream &out, Article &ar) {
    out << ar.name << ' ' << ar.words << ' ' << ar.page << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, Article &ar) {
    in >> ar.name >> ar.words >> ar.page;
    return in;
}






