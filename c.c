#include <syslog.h>
int main (int argc,char **argv){
	openlog("gwjlog",LOG_PID,0);
	syslog(LOG_DEBUG,"%s",argv[1]);
	closelog();
	return 0;
}
