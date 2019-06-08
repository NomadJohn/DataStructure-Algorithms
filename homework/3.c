#include<stdio.h>
#include<malloc.h>
#include<string.h>
// 1. 反转输出字符串
void Revstr(char *str)
{
    if(str[1]) Revstr(str+1);
    printf("%c", *str);
}

// 2. 编写函数fun(int m, int *k, int xx[])，
//    其功能是：将所有大于1小于整数m的非素数存入xx所指数组中，非素数的个数通过k返回。
int isNotPri(int n)
{
    int i = 2;
    for(; i < n; i++)
        if(n%i == 0) return 1;
    return 0;
}
int fun2(int m, int *k, int xx[])
{
    int num;
    for(num = 2, *k = 0; num < m; ++num)
    {
        if(isNotPri(num)) 
        {
            xx[*k] = num;
            *k += 1;
        }
    }
}
// 3、请编写程序，利用malloc函数开辟动态存储单元，
//   顺序存放输入的10个字符串，然后求10个字符串的最大值。
void fun3()
{
    char *arr[10]; // 此处是指针数组，每个元素存一个地址。
    // char (*arr)[10]; 此为指针数组，相当于指向了一个字符串
    char *max;
    if(max = arr[0] = (char *)malloc(100)) {
        scanf("%s", arr[0]);
    }
    for(int i = 1; i < 10; i++) 
    {
        if(arr[i] = (char *)malloc(100))
        {
            scanf("%s", arr[i]);
            if(strcmp(arr[i], max) > 0) max = arr[i];
        }
    }
    printf("max: %s", max);
}
/*
12、（10分）编写函数fun(char *s, int *t)，
其功能是：统计形参s所指字符串中数字字符出现的次数，
并存放在形参t所指的变量中，最后在主函数中输出。
例如，形参s所指的字符串为：abcdef35adgh3kjsdf7。
输出结果为：4。
 */
// 记住，指针是无符号长整型，大小由系统内存空间范围决定。
void fun12(const char *s, int *t)
{
    
    for(*t = 0; *s; ++s)
    {
        if(*s <= '9' && *s >= '0') (*t)++;
    }
}
int main()
{
    int t;
    fun12("as213cx565323sd213", &t);
    printf("count number: %d\n", t);
    return 0;
}