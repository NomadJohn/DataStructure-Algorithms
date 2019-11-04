#include "iostream"
#include "stdlib.h"
#include "string.h"

#define INCREMENT 20
#define MAX_SIZE 20
using namespace std;
typedef struct Stu {
    char sno[8];
    char name[20];
    int sex;
    char tel[12];
    char QQ[11];
} ElemType;

struct SeqList {
    ElemType *data;
    int length;
    int size;
};

SeqList InitSeqList();

// �������˳���
void TraverseList(SeqList list);

// pos�±�֮ǰ����
void InsertStu(SeqList &list, int pos, Stu stu);

// ��pos�±�ɾ��
void DeleteStu(SeqList &list, int pos);

// ��ѧ������
void SearchStu(SeqList list, const char sno[]);

int main() {
    SeqList list = InitSeqList();
    Stu table1[] = {
            {"2013001", "��ɺ", 0, "13800001919", "34578"},
            {"2013002", "��˼", 0, "1391012978",  "8796532"}
    };
    Stu table2[] = {
            {"2013003", "����", 0, "13789450012", "6514124"},
            {"2013004", "��ǿ", 1, "13634567856", "654378"},
            {"2013005", "����", 1, "13534408976", "5679"},
            {"2013006", "����", 1, "13386543211", "986354"}
    };
//   β������
    InsertStu(list, 0, table1[0]);
    InsertStu(list, 1, table1[1]);
//   �����2
    for (int i = 0; i < 4; ++i) {
        InsertStu(list, list.length, table2[i]);
    }
//    ���
    printf("��������\n");
    TraverseList(list);
//    ɾ��
    printf("ɾ����\n");
    DeleteStu(list, 2);
    TraverseList(list);
//    ����
    printf("�������\n");
    SearchStu(list, "2013001");
    return 0;
}


SeqList InitSeqList() {
    SeqList list;
    list.data = (Stu *) malloc(sizeof(Stu) * MAX_SIZE);
    list.size = MAX_SIZE;
    list.length = 0;
    return list;
}

void TraverseList(SeqList list) {
    for (int i = 0; i < list.length; ++i) {
        Stu stu = list.data[i];
        printf("%7s %6s %4s %11s %10s\n",
               stu.sno, stu.name,
               stu.sex ? "��" : "Ů",
               stu.tel, stu.QQ);
    }
}

void InsertStu(SeqList &list, int pos, Stu stu) {

    if (list.size <= list.length) { // �ռ䲻�������·���
        Stu *temp = (Stu *) realloc(list.data, (list.size + INCREMENT) * sizeof(Stu));
        if (!temp) {
            cout << "�޷������ڴ�" << endl;
            return;
        }
        list.data = temp;
    }
//    0 <= pos <= list.length + 1
    if (0 <= pos && pos <= list.length + 1) {
//        �������
        for (int i = list.length - 1; i >= pos; --i) {
            list.data[i + 1] = list.data[i];
        }
//        ����
        list.data[pos] = stu;
        ++list.length;
    }
}

void SearchStu(SeqList list, const char *sno) {
    for (int i = 0; i < list.length; ++i) {
        if (strcmp(sno, list.data[i].sno) == 0) {
            Stu stu = list.data[i];
            printf("%7s %6s %4s %11s %10s\n",
                   stu.sno, stu.name,
                   stu.sex ? "��" : "Ů",
                   stu.tel, stu.QQ);
        }
    }
}

void DeleteStu(SeqList &list, int pos) {
    if (0 <= pos && pos < list.length) {
        for (int i = pos; i < list.length - 1; ++i) {
            list.data[i] = list.data[i + 1];
        }
        --list.length;
    }
}
