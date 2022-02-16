#ifndef LAB2_1_MAN_H
#define LAB2_1_MAN_H

// #define l_name  20

class Man {
public:
    Man(int l_name = 30);

    char * GetName();
    int GetBirthYear();
    float GetPay();

    void SetName(char * tempName);
    void SetBirthYear(int tempBirth);
    void SetPay(float tempPay);

    ~Man();

private:
    char *pName;
    int birth_year;
    float pay;
};


#endif //LAB2_1_MAN_H
