#ifndef BIGMATH_H
#define BIGMATH_H
#define index_size 100000

int * newBigNum();
void freeBigNum(int *bigNumber);
void swap(int *a, int *b);
int  compare_number(int * big_number_1, int * big_number_2);
void big_add(int a[index_size], int b[index_size]);
void init_number(int big_number[index_size]);
void big_sub(int a[index_size], int b[index_size]);
void bigDiv(int * a, int * b);
void bigMod(int * a, int * b);
void mult(int a[index_size], int c);
void input_number(char input[index_size],int *big_num);
void print_number(int big_number[index_size]);
void bigFactorial(int * a, int c);
void bigPow(int *a , int b,int c);

#endif
