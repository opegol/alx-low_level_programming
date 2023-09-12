#include <stdlib.h>
#include "main.h"
#include <stdio.h>

int slen(char *s)
{
	int len = 0;

	while (*s++)
		len++;

	return (len);
}

int to_digit(char s)
{
	char n = s - '0';
	
	if (n < 0 || n > 9)
	{
		printf("Error\n");
		exit(98);
	}
	return (n);
}

char *new_array(char *s1, char *s2, int pos)
{
	char *s;
	int len_tot;
	int i, k = 0;
	int len1 = slen(s1), len2 = slen(s2);


	len_tot = len1 + len2;
	s = malloc(sizeof(char) * (len_tot + 1));
	if (s == NULL || (pos > len2))
		exit(98);
	s[len_tot] = '\0';

	for (i = 0; i < (len2 - pos) ; i++)
		s[i] = '0';

	for (i = (len2 - pos); i < (len_tot - pos); i++, k++)
		s[i] = s1[k];

	for (i = (len_tot - pos); i <= (len_tot - 1) ; i++)
		s[i] = '0';
	return(s);
}

char **digit_mul(char *s1, char *s2, int len_tot)
{
	int i, j, c, x, y, len_arr, k = 0;
	int len2 = slen(s2);
	/*char *mult_arr;*/
	char **mul;
	
	mul = malloc(sizeof(char) * len2 * (len_tot + 1));

	for (i = 0; i < len2; i++)
	{
		mul[i] = new_array(s1, s2, i);
		/*mul[i] = mult_arr;*/
		/*printf("i: %s\n", mul[i]);*/
	/*	free(mult_arr);*/
		len_arr = slen(mul[i]);
	/*	printf("len_arr: %i\n", len_arr);*/
	/*	for (j = (len2 - 1); j >= 0; j--)
		{*/
		j = len2 - 1 - i;

	/*	printf("j: %i, s2[j]: %c\n", j, s2[j]);*/
		c = 0;
		mul[i][len_arr] = '\0';
		for (k = len_arr - 1; k >= 0; k--)
		{
			y = (to_digit(mul[i][k]) * to_digit(s2[j]));
			/*printf("y: %i\n", y);*/
			x = y % 10;
			mul[i][k] = (x + c) + '0';
			c = y / 10;
			/*printf("mul[i][k]: %c\n", mul[i][k]);*/
		}
		 

	/*	}*/

		/*printf("mul(%i): %s\n", i, mul[i]);*/
	}

	return (mul);
}

char *sum_prods(char **s, int arr_len, int len2)
{
	int i, j, add, y, c = 0;
	char *sum;
	char k;

	sum = malloc(sizeof(char) * (arr_len + 1));

	
	for (j = arr_len - 1; j >= 0; j--)
	{
		/*printf("J: %i\n", j);*/

		add = 0;
		for (i = 0; i < len2; i++)
		{
			k = (s[i][j] - '0');

			/*printf("s[%i][%i]: %i\n", i, j, k);*/
			add += k;
			/*printf("add: %i\n", add);*/

		}
	/*	printf("addl: %i\n", add);*/

		y = (add + c) % 10;
		/*
		cc = 0; m = 10;
		if (d >= 10)
		{ 
		  	while (d >= 10)
			{
				d /= m;
				m *= 10;
				cc++;
			}
			sum[j] = d + '0';
			c = (add / m) + cc;
		}
		else
		{
		if (j == 0 && (y + '0' == 0))
		{
			sum[j] = '';
			break;
		}*/
		sum[j] = y + '0';
		c = (add + c) / 10;
		
	}
	sum[arr_len] = '\0';
	
	if (sum[0] == (0 + '0'))
		sum = (sum + 1);

	return (sum + s./101-mul 235234693269436436223446526546334576437634765378653875874687649698659586695898579 28658034365084365083426083109679137608216408631430814308651084650816406134060831608310853086103769013709675067130586570832760732096730978014607369739567864508634086304807450973045703428580934825098342095832409850394285098342509834209583425345267413639235755891879970464524226159074760914989935413350556875770807019893069201247121855122836389417022552166316010013074258781583143870461182707893577849408672040555089482160343085482612348145322689883025225988799452329290281169927532160590651993511788518550547570284574715925006962738262888617840435389140329668772644708i);
}

int main(int argc, char *argv[])
{
	int len_tot, len1, len2;
	char **prod;
	char *sum;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	
	/*printf("%i\n", slen(argv[1]));*/
	/*printf("%i\n", to_digit(argv[1][0]) * 2);*/
	/*printf("string: %s\n", new_array(argv[1], argv[2], 2));*/
	len1 = slen(argv[1]);
	len2 = slen(argv[2]);
	len_tot = len1 + len2;
	prod = digit_mul(argv[1], argv[2], len_tot);
	/*for (i = 0; i < len2; i++)
	{
		printf("prod[%i]: ", i);
		printf("%s\n", prod[i]);
	}*/
	sum = sum_prods(prod, len_tot, len2);

	printf("%s\n", sum);

	free(prod);
	free(sum);

	return (0);
}
