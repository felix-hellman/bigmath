#include <stdio.h>
#include <stdlib.h>
#define index_size 100000

int * newBigNum()
{
	int * tmp = (int*) calloc(index_size,sizeof(int));
	return tmp;
}
void freeBigNum(int * bigNumber)
{
	free(bigNumber);
}
void swap(int a[index_size], int b[index_size])
{
	int * tmp = (int*) calloc(index_size,sizeof(int));
	int i;
	for(i = 0; i < index_size; i++) tmp[i] = a[i];
	for(i = 0; i < index_size; i++) a[i] = b[i];
	for(i = 0; i < index_size; i++) b[i] = tmp[i];

	free(tmp);
}
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
void big_add(int a[index_size],int b[index_size])
{
	int i;
	for(i = index_size-1; i > 0; i--)
	{
		if(i != 0 && (a[i] + b[i]) >= 10) a[i-1]++;
		a[i] = (a[i] + b[i])%10;
	}
}
void init_number(int big_number[index_size])
{
	int i;
	for(i = 0; i < index_size; i++) big_number[i] = 0;
}
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
int bigDiv(int * a, int *b)
{
	int count = 0,i = 0;
	int * tmp;
	tmp = (int *) calloc(index_size,sizeof(int));
	for(i = 0; i < index_size; i++) tmp[i] = a[i];
	while(compare_number(tmp,b) > 0)
	{
		big_sub(tmp,b);
		count++;
	}
	free(tmp);
	return count;
}
void bigMod(int * a, int *b)
{
	while(compare_number(a,b) > 0)
	{
		big_sub(a,b);
	}
}
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

void input_number(char input[index_size],int *big_num)
{
	int i = 0,k = 0,index = 0;
	while(input[k] != '\0')k++;
	for(i = (index_size - k); i < index_size; i++)big_num[i] = input[index++] - 0x30;
}
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
void bigFactorial(int * a, int c)
{
	int i;
	input_number("1", a);
	for(i = 2; i <= c; i++) mult(a,i);
}
void bigPow(int *a, int b, int c)
{
	char str[10];
	int i;
	sprintf(str,"%d",b);
	init_number(a);
	input_number(str,a);
	for(i = 1; i < c; i++) mult(a,b);
}
