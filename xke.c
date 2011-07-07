#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<X11/keysym.h>
#include 	<X11/Xlib.h>

#define s2c(keysym) XKeysymToKeycode(dpy, keysym)
#define c2s(keycode) XKeycodeToKeysym(dpy, keycode, 0)


int xke(void)
{
	Display *dpy = XOpenDisplay(NULL);
	if (dpy == NULL)
		return -1;
	/*Query all exist window ID*/
//	Window w = DefaultRootWindow(dpy);
//	Window root_return, parent_return, *children_return;
//	unsigned int nchildren_return;
//	XQueryTree(dpy, w, &root_return, &parent_return, &children_return, &nchildren_return);
//	int i;
//	for (i=0; i<nchildren_return; i++)
//		printf ( "%lu\n", children_return[i] );
	Window focused_window;
	int focus_state;
	XGetInputFocus(dpy, &focused_window, &focus_state);
//	printf ( "focus_state=%i\n", focus_state );
	char *window_name;
	Status x = XFetchName(dpy, focused_window, &window_name);
	printf ( "%i\n", x );
	printf ( "%p\n", &window_name );
	XFree(window_name);
	XGrabKey(dpy, s2c(XK_Escape), AnyModifier, focused_window, 1, GrabModeAsync, GrabModeAsync);
	KeySym i;
	for (i=XK_a; i<=XK_z; i++)
		XGrabKey(dpy, s2c(i), AnyModifier, focused_window, 1, GrabModeAsync, GrabModeAsync);
	XEvent event;
	int exit_key=1;
	while (exit_key){
		XNextEvent(dpy, &event);
		exit_key=0;
//		if (event.xkey.keycode==s2c(XK_Escape))
//			exit_key=0;
//		if (event.xkey.keycode==s2c(XK_q))
//			printf ( "q%i pressed.\n", s2c(XK_q) );
//		switch (c2s(event.xkey.keycode)){
//			case XK_Escape: 
//				exit_key=0;
//				break;
//			case XK_x:
//				exit_key=0;
//				break;
//		}
//		printf ( "%u\n", event.xkey.keycode );
	}
	XUngrabKey(dpy, AnyKey, AnyModifier, focused_window);
//	printf ( "Exiting...\n" );
	XCloseDisplay(dpy);
	return 0;
}

