#include <stdio.h>
#include <stdlib.h>
#define index_size 100000

    /** \brief Init new big number
      *  \return returns a pointer to new number
      */
int * newBigNum()
{
	int * tmp = (int*) calloc(index_size,sizeof(int));
	return tmp;
}
    /** \brief free Big number
      *
      */
void freeBigNum(int * bigNumber)
{
	free(bigNumber);
}
    /** \brief swaps the values of two big numbers
      *  \param a , the first big number.
      *  \param b , the second big number.
      */
void swap(int a[index_size], int b[index_size])
{
	int * tmp = (int*) calloc(index_size,sizeof(int));
	int i;
	for(i = 0; i < index_size; i++) tmp[i] = a[i];
	for(i = 0; i < index_size; i++) a[i] = b[i];
	for(i = 0; i < index_size; i++) b[i] = tmp[i];

	free(tmp);
}
    /** \brief compares two big numbers
      * \param big_number_1, first big number
      * \param big_number_2, second big number
      * \return returns 1 if bigger, 0 if equal or -1 if smaller
      */
int compare_number(int big_number_1[index_size],int big_number_2[index_size])
{
	int i = 0;
	i = 0;
	while(big_number_1[i] == big_number_2[i] && i < index_size) i++;
	if(i == index_size) return 0;
	if(big_number_1[i] > big_number_2[i]) return 1;
	if(big_number_2[i] > big_number_1[i]) return -1;
	return -2;
}
    /** \brief adds the value of b to a
      *  \param a, first term. The sum will end up here
      *  \param b, second term.
      */
void big_add(int a[index_size],int b[index_size])
{
	int i;
	for(i = index_size-1; i > 0; i--)
	{
		if(i != 0 && (a[i] + b[i]) >= 10) a[i-1]++;
		a[i] = (a[i] + b[i])%10;
	}
}
    /** \brief takes a big number and sets it to zero
      */
void init_number(int big_number[index_size])
{
	int i;
	for(i = 0; i < index_size; i++) big_number[i] = 0;
}
    /**
      * \brief subtracts the value of b from a
      * \param a, the first term the difference will end up here
      * \param b, the second term.
      */
void big_sub(int a[index_size], int b[index_size])
{
	int i = 0, k = 0, c = 0, is_negative = 0;

	is_negative = compare_number(a,b);
	if(is_negative == -1) swap(a,b);

	for(i = index_size-1; i > 0; i--)
	{
		if(a[i] - b[i] < 0)
		{
			a[i] = a[i] - b[i] + 10;
			k = i-1;
			c = 0;
			while(!c)
			{
				if (a[k] == 0) a[k] = 9;
				else
				{
					a[k] = a[k] - 1;
					c = 1;
				}
				k--;
			}
		}
		else a[i] = a[i] - b[i];

	}
	k = 0;

	if(is_negative == -1)
	{
		while(a[k] == 0) k++;
		printf("Test %d \n",a[k]);
		a[k] = a[k] * -1;
	}
	if(is_negative == 0)	init_number(a);
}

    /** \brief Takes numbers from string and puts into big number
      * \param input, the text string to take input from
      * \param big_num, the target, where the number will be put
      */
void input_number(char input[index_size],int *big_num)
{
	int i = 0,k = 0,index = 0;
	while(input[k] != '\0')k++;
	for(i = (index_size - k); i < index_size; i++)big_num[i] = input[index++] - 0x30;
}
    /** \brief Takes two big numbers and subtracts b over a repeatedly
      * \param a, numerator, Quotient will be put here
      * \param b, denominator
      */
void bigDiv(int * a, int *b)
{
	int count = 1,i = 0,k = 0, index = 0;
	int * tmp;
	char * input = calloc(index_size,sizeof(int));
	tmp = (int *) calloc(index_size,sizeof(int));
	for(i = 0; i < index_size; i++) tmp[i] = a[i];
	while(compare_number(tmp,b) > 0)
	{
		big_sub(tmp,b);
		count++;
	}
    sprintf(input,"%d",count);
    init_number(a);
    input_number(input,a);
    free(input);
	free(tmp);
}
    /** \brief Takes two big numbers and subtracts b over a repeatedly
      *  \param a, numerator, Remainder will be put here
      *  \param b, denominator
      */
void bigMod(int * a, int *b)
{
	while(compare_number(a,b) > 0 || compare_number(a,b) == 0)
	{
		big_sub(a,b);
	}
}
    /** \brief Takes one big number and multiplies it c amount of times
      * \param a, factor, big number product will be put here
      * \param b, factor
      */
void mult(int a[index_size],int c)
{
	int temp[index_size];
	int i;

	for(i = 0; i < index_size; i++)
	{
		temp[i] = a[i];
		a[i] = 0;
	}
	for(i = 0; i < c; i++)big_add(a,temp);
}

/** \brief Takes a big number and prints it. Tries to remove all zeroes.
  */
void print_number(int big_number[index_size])
{
	int i, check = 0;
	for(i = 0; i < index_size; i ++)
	{
		if(big_number[i] != 0) check = 1;
		if(check) printf("%d",big_number[i]);
	}
	printf("\n");
}
    /** \brief puts c! factorial in big number a
      */
void bigFactorial(int * a, int c)
{
	int i;
	input_number("1", a);
	for(i = 2; i <= c; i++) mult(a,i);
}
    /** \brief takes b to the power of c and puts it in big number a
      * \param a, target the product will be put here
      * \param b, first factor
      * \param c, second factor
      */
void bigPow(int *a, int b, int c)
{
	char str[10];
	int i;
	sprintf(str,"%d",b);
	init_number(a);
	input_number(str,a);
	for(i = 1; i < c; i++) mult(a,b);
}
