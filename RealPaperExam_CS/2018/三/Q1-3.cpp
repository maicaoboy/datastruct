//
// Created by maicaoboy on 2023/12/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* 有一个 3*3 的二维整型数组，数组中的数由键盘录入，
 * 请将数组中所有的奇数输田到奇数行，将偶数输出到偶数行，每行 3 个数。(数组中可能存在奇数数与偶数数不相等的情况)
*/
#define N1  3
void Q1() {
    int *m = (int *) malloc(sizeof(int) * N1 * N1);      //使用行优先存储二维数组;
    int i = 0, j = N1 * N1 - 1;
    while(i <= j) {         //将奇数存储到前部,偶数存储到后部
        int num;
        scanf("%d", &num);
        if(num % 2 == 0) {
            m[j--] = num;
        }else {
            m[i++] = num;
        }
    }
    int index_j = 0;
    int index_o = j + 1;
    int count = 0;
    for (int index = 0; count < N1 * N1; index++){
        if(index % 2 == 1 && index_j < i) {
            printf("%d", m[index_j++]);
            count++;
        }else if(index % 2 == 0 && index_o < N1 * N1) {
            printf("%d", m[index_o++]);
            count++;
        }
        printf("\n");
    }
}


void Q2() {
    char s[3001];
    for(int i = 0; i < 3001; i++) {
        scanf("%c", &s[i]);
        if(s[i] == '#') {
            s[i] = '\0';
            break;
        }
    }
    int max = 0;
    int min = 3001;
    char* minIndex= NULL;
    char *maxIndex = NULL;
    int curLength = 0;
    char *a = s;
    while(*a != '\0') {
        if(*a == ' ') {
            if(curLength > max) {
                max = curLength;
                maxIndex = a - max + 1;
                *a = '\0';
            }
            if(curLength < min && curLength != 0) {
                min = curLength;
                minIndex = a - min + 1;
                *a = '\0';
            }
            curLength = 0;
        }else {
            curLength++;
        }
        a++;
    }
    printf("最短:%s", minIndex);
    printf("最长:%s", maxIndex);
}


/**
* (1)输入该单位所有员工的工资信息;
* (2) 请计算输出该单位员工工资的中位数:(将员工工资进行升序排列，中位数是中间位置的员工工资，若 n 为偶数，其中间两位的平均数为中位数)。
*/
typedef struct Salary{
    char id[10];//员工编号
    char name[20];//员工姓名
    float wage;//员工工资
    struct Salary *next;
}LinkNode, *LinkList;

LinkNode *getNode(const char id[10], const char name[20], float wage) {
    LinkNode *node = (LinkNode*) malloc(sizeof (LinkNode));
    strcpy(node->id, id);
    strcpy(node->name, name);
    node->wage = wage;
    node->next = NULL;
}

void input(LinkList &L) {
    L = getNode("\0", "\0", -1);
    int n = 0;
    scanf("请输入员工总数:");
    scanf("%d", &n);
    printf("请分别输入%d个员工的id,姓名和工资,以空格间隔");
    for (int i = 0; i < n; ++i) {
        char id[10];
        char name[20];
        float wage;
        scanf("%s %s %f", id, name, wage);
        LinkNode *node = getNode(id, name, wage);
        node->next = L->next;
        L->next = node;
    }
}



void middle(LinkList L) {
    int count = 0;
    LinkNode *p = L;
    while(p->next != NULL) {
        count++;
        p = p->next;
    }
    for(LinkNode *ptr1 = L; ptr1 != NULL; ptr1 = ptr1->next) {
        for(LinkNode *ptr2 = L; ptr2 != NULL && ptr2->next != NULL && ptr2->next->next != NULL; ptr2 = ptr2->next) {
            if(ptr2->next->wage > ptr2->next->next->wage) {//若发生交换,则交换ptr2后买你的两个节点
                LinkNode *node = ptr2->next;
                ptr2->next = node->next;
                node->next = node->next->next;
                ptr2->next->next = node;
            }
        }
    }
    float ave = 0;
    LinkNode *node = L;
    for(int i = 0; i < count / 2; i++) {
        node = node->next;
    }
    if(count % 2 == 0) {
        ave = (node->wage + node->next->wage) / 2;
    }else {
        ave = node->next->wage;
    }
    printf("%f", ave);
}



int main() {
    //Q1();
    Q2();
}


















