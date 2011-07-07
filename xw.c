#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<string.h>
#include 	<X11/Xlib.h>

/*list all windows' ID and name*/
int main(int argc, const char *argv[])
{
	Display *dpy = XOpenDisplay(NULL);
	if (dpy == NULL)
		return -1;
	Window w = DefaultRootWindow(dpy);
	Window root_w, parent_w, *children_w;
	unsigned int nchildren;
	XQueryTree(dpy, w, &root_w, &parent_w, &children_w, &nchildren);
	int i;
	char *win_name;
	for (i=0; i<nchildren; i++){
		XFetchName(dpy, children_w[i], &win_name);
		printf ( "Window ID :%lu Name: %s \n", children_w[i], win_name );
		XFree(win_name);
	}
	return 0;
}

