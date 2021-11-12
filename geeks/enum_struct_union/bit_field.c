#include <stdio.h>



struct byte {
// char a:5;
// char b:8;
    char a;
    char b;
};

struct byteb {
// char a:5;
// char :0;
// char b:8;
    char a;
    char b;
    char c;
};

struct byte2 {
// short a:5;
// short b:8;
    short a;
    short b;
};

struct byte2b {
// short a:5;
// short :0;
// short b:8;
    short a;
    short b;
    short c;
};

struct byte4 {
// int a:5;
// int b:8;
    int a;
    int b;
};

struct byte4b {
// int a: 5;
// int :0;
// int b:8;
    int a;
    int b;
    int c;
};

struct byte8 {
// long long a:5;
// long long b:8;
    long a;
    long b;
};

struct byte8b {
// long long a:5;
// long long :0;
// long long b:8;
    long a;
    long b;
    long c;
};

int main(void)

{
    printf("%lu\n", sizeof(struct byte));
    printf("%lu\n", sizeof(struct byteb));
    printf("%lu\n", sizeof(struct byte2));
    printf("%lu\n", sizeof(struct byte2b));
    printf("%lu\n", sizeof(struct byte4));
    printf("%lu\n", sizeof(struct byte4b));
    printf("%lu\n", sizeof(struct byte8));
    printf("%lu\n", sizeof(struct byte8b));
}