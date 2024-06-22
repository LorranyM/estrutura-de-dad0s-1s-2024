typedef struct StrackNode{
    char data;
    struct StrackNode* next;
} StrackNode;

void push(StrackNode** root, char data);
char pop(StrackNode** root);
char peek(StrackNode* root);
int isEmpty(StrackNode* root);
void display(StackNode* root);