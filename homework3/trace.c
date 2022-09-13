#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    printf("Address of argc: %x\n", &argc);
    printf("Content of argc: %d\n", &argc);
    printf("Address of argv: %x\n", &argv);
    printf("Content of argv: %p\n", &argv);

    int num1, num2 = 10;
    char c1 = 'A';
    char c2 = 'B';
    float score1 = 20.5;
    char ca[3] = "Hi";

    printf("Address of num1: %x\n", &num1);
    printf("Content of num1: %d\n", &num1);
    printf("Address of num2: %x\n", &num2);
    printf("Content of num2: %d\n", &num2);
    printf("Address of c1: %x\n", &c1);
    printf("Content of c1: %c\n", &c1);
    printf("Address of c2: %x\n", &c2);
    printf("Content of c2: %c\n", &c2);
    printf("Address of score1: %x\n", &score1);
    printf("Content of scpre1: %f\n", &score1);
    printf("Address of ca: %p\n", &ca);
    printf("Content of ca[0]: %c\n", &ca[0]);
    printf("Content of ca[1]: %c\n", &ca[1]);
    printf("Content of ca[2]: %c\n", &ca[2]);

    dummy(num2, c1, ca, score1);

    return 0;
}

void dummy(int x, char y, char* z, float w)
{
    x++;
    y++;
    w = w + 2.1;

    /* pause here */
}