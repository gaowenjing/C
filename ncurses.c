#include 	<ncurses.h>
#include 	<stdlib.h>


void help(){
	printw ("no help here.\n");
}

void something( char k ){
	printw ("You just press %c key.\n", k);
}

int main(int argc, const char *argv[])
{
	/*initialize functions*/
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_CYAN);
	cbreak();
	noecho();
	keypad(stdscr, true);
	
	printw("Yello.\n");
	/*do we need this function?*/
//	refresh();
	int k;
	int exval = 1;
	int bold_flag = 0;
	int x, y;
	int row, col;
	while (exval)
	{
		k = getch();
		switch (k)
		{
			case 'q': endwin(); 
				  exval = 0;
				  break;
			case 'h': help();
				  break;
			case 'r': refresh();
				  break;
//			case 'p': 
//				  system("ping o.cn");
//				  break;
			case 'b':
				  if (bold_flag == 0)
				  {
					  attron(A_BOLD);
					  bold_flag = 1;
				  }
				  else
				  {
					  attroff(A_BOLD);
					  bold_flag = 0;
				  }
				  break;
			case 'c':
				  clear();
				  break;
			default: something(k);
		}
		getmaxyx(stdscr, row, col);
		getyx(stdscr, y, x);
		if ( y == row-1 ) {
			printw ( "It's the end of the scr\n", y, x );
			getch();
			clear();
		}
	}
	return 0;
}

