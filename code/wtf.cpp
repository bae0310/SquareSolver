#include "wtf.h"

int func1(int a) {
    printf("hello from func1 %d\n", a);
    return a + 1;
}

int func2(int a) {
    printf("%d\n", a);
    return a + 2;
}
