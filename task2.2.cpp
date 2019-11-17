#include "iostream"
#include "stdlib.h"
#include "string.h"

//typedef char LinkStackType;
//������ջ�Ľڵ�ṹ
typedef struct LinkStackNode {
    char data[20];
    LinkStackNode *next;
} *LinkStack;

void InitLinkStack(LinkStack &stack) {
    stack = NULL;
}

LinkStack CreateNode(const char *data) {
    LinkStack newNode = (LinkStack) malloc(sizeof(LinkStackNode));
    if (newNode) {
        strcpy(newNode->data, data);
        newNode->next = NULL;
    }
    return newNode;
}

// ͷ����ջ
void Push(LinkStack &stack, const char *data) {
    LinkStack newNode = CreateNode(data);
    newNode->next = stack;
    stack = newNode;
}
// ͷɾ��ջ

void Pop(LinkStack &stack, char *rt) {
    strcpy(rt, stack->data);
    LinkStack tempStack = stack;
    stack = stack->next;
    free(tempStack);
}

void GetTop(LinkStack &stack, char *rt) {
    if(stack) {
        strcpy(rt, stack->data);
    } else {
        strcpy(rt, "");
    }
}

int IsEmpty(LinkStack stack) {
    return stack == NULL;
}
int IsFull(LinkStack stack) {
//    ������������
}
int main() {
    LinkStack stack;
    InitLinkStack(stack);
    Push(stack, "China");
    Push(stack, "Japan");
    Push(stack, "Frawnce");
    Push(stack, "India");
    Push(stack, "Australia");
    char rt[20];
    while(!IsEmpty(stack)) {
        Pop(stack, rt);
        printf("������%s ", rt);
        GetTop(stack, rt);
        printf("ջ����%s ", rt);
        printf("ջ״̬��%s\n", IsEmpty(stack) ? "��": "�ǿ�");
    }
    return 0;

}