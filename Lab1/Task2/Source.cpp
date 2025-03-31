#define PR(x) printf("x=%u, *x=%d, &x=%u\n",x,*x,&x)
#include <stdio.h>
void main(void) {
    // INT
    int mas_int[] = { 100, 200, 300 };
    int* ptr1_int = mas_int, * ptr2_int = &mas_int[2];

    printf("\n--- INT ---\n");
    PR(ptr1_int, "%d");
    ptr1_int++;
    PR(ptr1_int, "%d");
    PR(ptr2_int, "%d");
    ++ptr2_int;
    printf("ptr2 - ptr1 = %td\n", ptr2_int - ptr1_int);

    // CHAR
    char mas_char[] = { 'A', 'B', 'C' };
    char* ptr1_char = mas_char, * ptr2_char = &mas_char[2];

    printf("\n--- CHAR ---\n");
    PR(ptr1_char, "%c");
    ptr1_char++;
    PR(ptr1_char, "%c");
    PR(ptr2_char, "%c");
    ++ptr2_char;
    printf("ptr2 - ptr1 = %td\n", ptr2_char - ptr1_char);

    // FLOAT
    float mas_float[] = { 1.1, 2.2, 3.3 };
    float* ptr1_float = mas_float, * ptr2_float = &mas_float[2];

    printf("\n--- FLOAT ---\n");
    PR(ptr1_float, "%.2f");
    ptr1_float++;
    PR(ptr1_float, "%.2f");
    PR(ptr2_float, "%.2f");
    ++ptr2_float;
    printf("ptr2 - ptr1 = %td\n", ptr2_float - ptr1_float);

    // DOUBLE
    double mas_double[] = { 1.11, 2.22, 3.33 };
    double* ptr1_double = mas_double, * ptr2_double = &mas_double[2];

    printf("\n--- DOUBLE ---\n");
    PR(ptr1_double, "%.2lf");
    ptr1_double++;
    PR(ptr1_double, "%.2lf");
    PR(ptr2_double, "%.2lf");
    ++ptr2_double;
    printf("ptr2 - ptr1 = %td\n", ptr2_double - ptr1_double);

    // SHORT
    short mas_short[] = { 10, 20, 30 };
    short* ptr1_short = mas_short, * ptr2_short = &mas_short[2];

    printf("\n--- SHORT ---\n");
    PR(ptr1_short, "%d");
    ptr1_short++;
    PR(ptr1_short, "%d");
    PR(ptr2_short, "%d");
    ++ptr2_short;
    printf("ptr2 - ptr1 = %td\n", ptr2_short - ptr1_short);

    // LONG
    long mas_long[] = { 1000, 2000, 3000 };
    long* ptr1_long = mas_long, * ptr2_long = &mas_long[2];

    printf("\n--- LONG ---\n");
    PR(ptr1_long, "%ld");
    ptr1_long++;
    PR(ptr1_long, "%ld");
    PR(ptr2_long, "%ld");
    ++ptr2_long;
    printf("ptr2 - ptr1 = %td\n", ptr2_long - ptr1_long);

}