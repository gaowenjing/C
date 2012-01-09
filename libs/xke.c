#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<X11/keysym.h>
#include 	<X11/Xlib.h>

#define s2c(keysym) XKeysymToKeycode(dpy, keysym)
#define c2s(keycode) XKeycodeToKeysym(dpy, keycode, 0)

/*Use X api to exit a program in (x)terminal using hotkey*/

int xke(void)
{
	Display *dpy = XOpenDisplay(NULL);
	if (dpy == NULL)
		return -1;
	/*Get the focused window id */
	Window focused_window;
	int focus_state;
	/*focus state: RevertToParent, RevertToPointerRoot, RevertToNone */
	XGetInputFocus(dpy, &focused_window, &focus_state);
	/*Get focused window info */
//      char *window_name;
//      Status x = XFetchName(dpy, focused_window, &window_name);
//      XFree(window_name);
	/*Grab Esc key, Use Async to grab key right away */
	XGrabKey(dpy, s2c(XK_Escape), AnyModifier, focused_window, 1,
		 GrabModeAsync, GrabModeAsync);
	KeySym i;
	/*Grab 'a' to 'z' key */
	for (i = XK_a; i <= XK_z; i++)
		XGrabKey(dpy, s2c(i), AnyModifier, focused_window, 1,
			 GrabModeAsync, GrabModeAsync);
	XEvent event;
	int exit_key = 1;	/* exit event key */
	while (exit_key) {
		/*receive event */
		XNextEvent(dpy, &event);
		exit_key = 0;	/* press AnyKey to exit */
	}
	/*Release grabbed key */
	XUngrabKey(dpy, AnyKey, AnyModifier, focused_window);
	XCloseDisplay(dpy);
	return 0;
}
