#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

void push(StrackNode** root, char data){
    StackNode* strackNode = malloc(sizeof(StackNode));
    strackNode->data = data;
    strackNode->next = *root;
    *root = strackNode;
}

char pop(StrackNode** root){
    if(isEmpty(*root)){
        return CHAR_MIN;
    }
    StrackNode* tmp = *root;
    *root = tmp->next;
    char tmpData = tmp->data;
    free(tmp);
    return tmpData;
}

char peek(StrackNode* root){
    if(isEmpty(root)){
        return CHAR_MIN;
    }
    return root->data;
}

int isEmpty(StrackNode* root){
    return root == NULL;
}

void display(StackNode* root){
    StackNode* tmp = root;
    while(tmp != NULL){
        printf("%c -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}