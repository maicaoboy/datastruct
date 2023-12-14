//
// Created by maicaoboy on 2023/12/10.
//
#include "stdli.h"
#include "stdlib.h"

int Q1_total(int n) {
    if(n == 1) {
        return 1;
    }
    return Q1_total(n - 1) + n + 1;
}

void Q1() {
    int n;
    scanf("%d", &n);
    int total = Q1_total(n);
    printf("%d", total);
}







struct Data{
    int year;
    int month;
    int day;
};

int dayCount(struct Data data) {
    int count = 0;
    switch (data.month) {
        case 11:
            count += 30;
        case 10:
            count += 31;
        case 9:
            count += 30;
        case 8:
            count += 31;
        case 7:
            count += 31;
        case 6:
            count += 30;
        case 5:
            count += 31;
        case 4:
            count += 30;
        case 3:
            count += 31;
        case 2:
            count += 28;
        case 1:
            count += 31;
    }
    if((data.year % 4 == 0 && data.year % 100 != 0) || data.year % 400 == 0) {
        if(data.month > 2) {
            count++;
        }
    }
    count += data.day;
    return count;
}


void Q2() {
    struct Data data;
    scanf("%d %d %d", &data.year, &data.month, &data.day);
    int day = dayCount(data);
    printf("%d",day);
}


void Q3_solve(char *str_cpy, char *str, int k) {
    for (int i = 0; i < k, *str != '\0'; ++i){
        str++;
    }
    while(*str != '\0') {
        *str_cpy++ = *str++;
    }
    *str_cpy = *str;
}




void Q3() {
    char str[1025];
    char str_cpy[1025];
    gets(str);
    int k;
    scanf("%d", k);
    Q3_solve(str_cpy, str, k);
    printf("%s", str_cpy);
}









