//
// Created by maicaoboy on 2023/11/23.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


struct Node {
    char english[11];
    char chinese[11];
    Node *next;
};

void method(struct Node *node, char *english, char *chinese) {
    struct Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->english, english);
    strcpy(newNode->chinese, chinese);

    struct Node *pre = node;
    struct Node *cur = node->next;

    FILE *file = fopen("./word.txt", "w");
    if(file == NULL) return;

    while(cur && strcmp(cur->english, english)) {
        fprintf(file, "%s %s ", cur->english, cur->chinese);
        pre = cur;
        cur = cur->next;
    }
    newNode->next = pre->next;
    pre->next = newNode;

    while(cur) {
        fprintf(file, "%s %s ", cur->english, cur->chinese);
        cur = cur->next;
    }
}


int main() {
    char* strings[] = {
            "String 0",
            "String 1",
            "String 2",
            "String 3",
            "String 4",
            "String 8",
            "String 10",
            "String 15",
            "String 17",
            "String 19"
    };


    int length = 10;
    Node * head = (Node*) malloc(sizeof (Node));
    head->next = NULL;
    for (int i = 0; i < length; ++i) {
        Node * node = (Node*) malloc(sizeof (Node));
        strcpy(node->english, strings[i]);
        node->next = head->next;
        head->next = node;
    }

    method(head, "String 7", "哈哈");


}

