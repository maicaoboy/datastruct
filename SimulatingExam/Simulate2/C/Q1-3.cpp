//
// Created by maicaoboy on 2023/12/14.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void Q1() {
    FILE* f = fopen("D:\\score.dat", "r");
    if(f == NULL) {
        printf("file not exist");
        return;
    }
    char name[20] = "";
    float score = 0.0f;
    char names[3][20];
    float scores[3] = {0.0};
    float ave = 0.0f;
    int count = 0;
    while((fscanf(f, "%s\t%f\n", name, &score)) != EOF) {
        ave += score;
        int index = -1;
        if(count < 3) {
            index = count;
        }else {
            for (int i = 1; i < count; ++i){
                if(score < scores[i]) {
                    index = i;
                }
            }
        }
        scores[index] = score;
        strcpy(names[index], name);
        count++;
    }

    ave /= count;
    printf("average:%f\n", ave);
    for (int i = 0; i < count && i < 3; ++i){
        printf("%s\t%f\n", names[i], scores[i]);
    }

}


int isSame(int num) {
    int square = num * num;
    while(num > 0) {
        if(num % 10 != square % 10) {
            return 0;
        }
        num /= 10;
        square /= 10;
    }
    return 1;
}

void Q2() {
    for (int i = 0; i <= 1000; ++i) {
        if(isSame(i)) {
            printf("%d ", i);
        }
    }
}



int isAlpha(char *a) {
    if(*a >= 'a' && *a <= 'z' || *a >= 'A' && *a <= 'Z') {
        return 1;
    }
    return 0;
}

void swapAll(char *slow, char *fast) {
    while(slow < fast) {
        char a = *slow;
        *slow = *fast;
        *fast = a;
    }
}

void Q3(char *str) {
    char *slow = str, *fast = str;
    while(*fast != '\0') {
        while(!isAlpha(slow) &&  *slow != '\0') {
            slow++;
        }
        fast = slow;
        while(isAlpha(fast) && *fast != '\0') {
            fast++;
        }
        swapAll(slow, fast - 1);
        slow = fast;
    }
    swapAll(slow, fast - 1);

    printf("%s", str);
}


int main() {

}