#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	char *ch = "你好吗？今天天气怎样？";
	char *gbk = "�Ҳ�abc";
	printf ( "%lu\n", strlen(ch) );
	printf ( "%lu\n", strlen(gbk) );
	int i;
	for (i = 0; i < strlen(gbk); i++) {
		printf ( "%.x ", gbk[i]&0x000000ff );
	}
	return 0;
}

