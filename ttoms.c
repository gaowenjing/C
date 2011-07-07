#include 	<stdlib.h>
#include	<stdio.h>
#include 	"char.h"

/*convert time format to millionseconds*/
double ttoms(char *t)
{
	sw a = split_word(t,-1);
	double t_ms = atof(a.left_word);
	switch (*a.right_word)
	{
		case 'i':
			return t_ms;
		case 'h':
			return t_ms*3600000;
		case 'm':
			return t_ms*60000;
		case 's':
			return t_ms*1000;
		case '0' ... '9':
			return atof(t)*1000;
	}
	return 0;
}

/*convert time format to microsecond*/
double ttous(char *t)
{
	sw a = split_word(t,-1);
	double t_ms = atof(a.left_word);
	switch (*a.right_word)
	{
		case 'u':
			return t_ms;
		case 'i':
			return t_ms*1000;
		case 'h':
			return t_ms*3600000000;
		case 'm':
			return t_ms*60000000;
		case 's':
			return t_ms*1000000;
		case '0' ... '9':
			return atof(t)*1000000;
	}
	return 0;
}
