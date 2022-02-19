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

Man::~Man() {
    delete[] pName;
}





