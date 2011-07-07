#include 	<stdlib.h>
#include	<stdio.h>
#include 	"char.h"

//convert time format to million seconds
unsigned int ttoms(char *t)
{
	sw a = split_word(t,-1);
	int t_ms = atoi(a.left_word);
	switch (*a.right_word)
	{
		case 'h':
			return t_ms*3600000;
		case 'm':
			return t_ms*60000;
		case 's':
			return t_ms*1000;
		case '0' ... '9':
			return atoi(t);
	}
	return 0;
}
