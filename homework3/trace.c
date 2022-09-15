    #include <stdio.h>

    void dummy(int, char, char *, float);

    int main(int argc, char* argv[])
    {
        printf("Addresses\tName\tType\tScope\tValue\n");
        printf("%p\targc\tint\tMain\t%d\n", (void*) &argc, argc);
        printf("%p\targv[]\tchar*\tMain\t%p\n", (void*) &argv, argv);


        int num1, num2 = 10;
        char c1 = 'A';
        char c2 = 'B';
        float score1 = 20.5;
        char ca[3] = "Hi";

        printf("%p\tnum1\tint\tMain\t%d\n", (void*) &num1, num1);
        printf("%p\tnum2\tint\tMain\t%d\n", (void*) &num2, num2);
        printf("%p\tc1\tchar\tMain\t%c\n", (void*) &c1, c1);
        printf("%p\tc2\tchar\tMain\t%c\n", (void*) &c2, c2);
        printf("%p\tscore1\tfloat\tMain\t%f\n", (void*) &score1, score1);
        printf("%p\tca[0]\tchar\tMain\t%c\n", (void*) &ca[0], ca[0]);
        printf("%p\tca[1]\tchar\tMain\t%c\n", (void*) &ca[1], ca[1]);
        printf("%p\tca[2]\tchar\tMain\t%c\n", (void*) &ca[2], ca[2]);

        dummy(num2, c1, ca, score1);

        return 0;
    }

    void dummy(int x, char y, char* z, float w)
    {
        printf("%p\tx\tint\tdummy\t%d\n", (void*) &x, x);
        printf("%p\ty\tchar\tdummy\t%c\n", (void*) &y, y);
        printf("%p\tz\tchar*\tdummy\t%p\n", (void*) &z, z);
        printf("%p\tw\tfloat\tdummy\t%f\n", (void*) &w, w);

        x++;
        printf("%p\tx\tint\tdummy\t%d\n", (void*) &x, x);
        y++;
        printf("%p\ty\tchar\tdummy\t%c\n", (void*) &y, y);
        w = w + 2.1;
        printf("%p\tw\tfloat\tdummy\t%f\n", (void*) &w, w);
        /* pause here */
    }