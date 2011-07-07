#include <gtk/gtk.h>
int main(int argc, char *argv[])
{
	GtkBuilder *builder;
	GtkWidget *window , *button;
	gtk_init (&argc,&argv);
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	builder = gtk_builder_new ();
	gtk_widget_show (window);
	g_print("hi");
	gtk_main();
	return 0;
}
