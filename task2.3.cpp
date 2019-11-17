#include<stdio.h>
#include<stdlib.h>

# define MAXQSIZE 100
# define OK 1
# define ERROR 0
typedef struct SqQueue {
    char *base;
    int front;
    int rear;
} SqQueue;

int InitQueue(SqQueue *Q) {
    Q->base = (char *) malloc(MAXQSIZE * sizeof(char));
    if (!Q->base) {
        printf("�޷������ڴ�\n");
        return ERROR;
    }
    Q->front = Q->rear = 0;
    return OK;
}

int EnQueue(SqQueue *Q, char e) {
    if ((Q->rear + 1) % MAXQSIZE != Q->front) {
        Q->base[Q->rear] = e;
        Q->rear = (Q->rear + 1) % MAXQSIZE;
        return OK;
    } else {
        return ERROR;
    }
}

int IsEmpty(SqQueue *Q) {
    return Q->front == Q->rear;
}

int DeQueue(SqQueue *Q, char &e) {
    if (!IsEmpty(Q)) {
        e = Q->base[Q->front];
        Q->front = (Q->front + 1) % MAXQSIZE;
        return OK;
    } else return ERROR;
}

void Traverse(SqQueue *Q) {
    if (Q->front != Q->rear) {
        int i = Q->front;
        while (i % MAXQSIZE != Q->rear) {
            printf("%c", Q->base[i]);
            i++;
        }
    } else {
        printf("�ն���\n");
    }
}

int main() {
    char e;
    SqQueue Q;
    InitQueue(&Q);
    printf("�����ַ�����#Ϊ������:");
    while ((e = getchar()) != '#') {
        EnQueue(&Q, e);
    }
    printf("\n��������\n");
    Traverse(&Q);
    printf("\n���ӣ�\n");
    while (!IsEmpty(&Q)) {
        DeQueue(&Q, e);
        printf("%c ����ʣ�ࣺ", e);
        Traverse(&Q);
        printf("\n");
    }
    return 0;
}
