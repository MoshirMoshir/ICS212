#include <stdio.h>

void dummy(int, char, char *, float);

int main(int argc, char* argv[])
{
    int num1, num2 = 12;
    char c1 = 'C';
    char c2 = 'D';
    float score1 = 10.5;
    char ca[3] = "Hi";

    printf("\nInitilized varibles:\n");
    printf("%p = argc\n", &argc);
    printf("argc: %d\n", argc);
    printf("%p = argv[]\n", &argv);
    printf("argv[]: %p\n", argv);
    printf("%p = num1\n", &num1);
    printf("num1: %d\n", num1);
    printf("%p = num2\n", &num2);
    printf("num2: %d\n", num2);
    printf("%p = c1\n", &c1);
    printf("c1: %c\n", c1);
    printf("%p = c2\n", &c2);
    printf("c2: %c\n", c2);
    printf("%p = score1\n", &score1);
    printf("score1: %f\n", score1);
    printf("%p = ca[0]\n", &ca[0]);
    printf("ca[0]: %c\n", ca[0]);
    printf("%p = ca[1]\n", &ca[1]);
    printf("ca[1]: %c\n", ca[1]);
    printf("%p = ca[2]\n", &ca[2]);
    printf("ca[2]: %c\n", ca[2]);
    
    dummy(num2, c1, ca, score1);
    
    printf("\nAfter dummy(num2, c1, ca, score1):\n");
    printf("%p = argc\n", &argc);
    printf("argc: %d\n", argc);
    printf("%p = argv[]\n", &argv);
    printf("argv[]: %p\n", argv);
    printf("%p = num1\n", &num1);
    printf("num1: %d\n", num1);
    printf("%p = num2\n", &num2);
    printf("num2: %d\n", num2);
    printf("%p = c1\n", &c1);
    printf("c1: %c\n", c1);
    printf("%p = c2\n", &c2);
    printf("c2: %c\n", c2);
    printf("%p = score1\n", &score1);
    printf("score1: %f\n", score1);
    printf("%p = ca[0]\n", &ca[0]);
    printf("ca[0]: %c\n", ca[0]);
    printf("%p = ca[1]\n", &ca[1]);
    printf("ca[1]: %c\n", ca[1]);
    printf("%p = ca[2]\n", &ca[2]);
    printf("ca[2]: %c\n", ca[2]);

    return 0;
}

void dummy(int x, char y, char* z, float w)
{
    printf("\nInitilized in dummy:\n");
    printf("%p = x\n", &x);
    printf("x: %d\n", x);
    printf("%p = y\n", &y);
    printf("y: %c\n", y);
    printf("%p = z\n", &z);
    printf("z: %p\n", z);
    printf("%p = w\n", &w);
    printf("w: %f\n", w);

    x++;
    y++;
    w = w + 2.1;
    
    printf("\nAfter functions in dummy:\n");
    printf("%p = x\n", &x);
    printf("x: %d\n", x);
    printf("%p = y\n", &y);
    printf("y: %c\n", y);
    printf("%p = z\n", &z);
    printf("z: %p\n", z);
    printf("%p = w\n", &w);
    printf("w: %f\n", w);

    /* pause here */
}