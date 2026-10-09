#include <stdio.h>
#include <stddef.h>

typedef struct {
    char c;
    int i;
    double d;
    short s;
} Unoptimized_t;

typedef struct {
    double d;
    int i;
    short s;
    char c;
} Optimized_t;

typedef struct __attribute__((packed)){
    char c;
    int i;
    double d;
    short s;
} Pack_t;

int main()
{
    Unoptimized_t unoptimized_t;
    printf("size of unoptimized struct = %zu\n", sizeof(unoptimized_t));
    printf("c: %zu\n", offsetof(Unoptimized_t, c));
    printf("i: %zu\n", offsetof(Unoptimized_t, i));
    printf("d: %zu\n", offsetof(Unoptimized_t, d));
    printf("s: %zu\n", offsetof(Unoptimized_t, s));

    Optimized_t optimized;
    printf("size of optimized struct = %zu\n", sizeof(optimized));
    printf("c: %zu\n", offsetof(Optimized_t, c));
    printf("i: %zu\n", offsetof(Optimized_t, i));
    printf("d: %zu\n", offsetof(Optimized_t, d));
    printf("s: %zu\n", offsetof(Optimized_t, s));

    Pack_t pack;
    printf("size of packed struct = %zu\n", sizeof(pack));
    printf("c: %zu\n", offsetof(Pack_t, c));
    printf("i: %zu\n", offsetof(Pack_t, i));
    printf("d: %zu\n", offsetof(Pack_t, d));
    printf("s: %zu\n", offsetof(Pack_t, s));

    pack.i = 20;
    printf("before: %d\n", pack.i);
    int *p = &pack.i;
    *p = 30;
    printf("after: %d\n", pack.i);
    return 0;
}