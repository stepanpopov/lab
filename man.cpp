#include "man.h"

#include <cstring>


Man::Man(int l_name) {
    pName = new char[l_name + 1];
}

char *Man::GetName() {
    return pName;
}

int Man::GetBirthYear() {
    return birth_year;
}

float Man::GetPay() {
    return pay;
}

void Man::SetName(char * tempName) {
    int n = strlen(tempName);
    strncpy(pName, tempName, n);
    pName[n] = '\0';
}

void Man::SetBirthYear(int tempBirth) {
    birth_year = tempBirth;
}

void Man::SetPay(float tempPay) {
    pay = tempPay;
}

Man& Man::operator=(const Man& man) {
    birth_year = man.birth_year;
    pay = man.pay;

    if (!pName) delete pName;
    pName = new char[strlen(man.pName) + 1];
    this->SetName(man.pName);

    return *this;
}

Man::~Man() {
    delete[] pName;
}





