#ifndef LAB2_1_ARTICLE_H
#define LAB2_1_ARTICLE_H

#include <iostream>

class Article {
public:
    Article(int l_name = 30);

    Article(const Article &ar);

    char *GetName();

    long GetPage();

    int GetWords();

    void SetName(char *tempN);

    void SetPage(int tempP);

    void SetWords(int tempW);

    Article &operator=(const Article &ar);

    bool operator<(Article &ar);

    bool operator==(Article &ar);

    friend std::ostream &operator<<(std::ostream &out, Article &ar);

    friend std::istream &operator>>(std::istream &in, Article &ar);

    ~Article();

private:
    char *name;
    int words;
    int page;
};


#endif // LAB2_1_ARTICLE_H
