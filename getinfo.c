#include "getinfo.h"
#include <ncurses.h>
#include <string.h>

int	main(void)
{
	int	row, col;
	int	index, option;
	const char	*title[] = {
	"  ____ _____ _____   ___ _   _ _____ ___  ",
	" / ___| ____|_   _| |_ _| \\ | |  ___/ _ \\ ",
	"| |  _|  _|   | |    | ||  \\| | |_ | | | |",
	"| |_| | |___  | |    | || |\\  |  _|| |_| |",
	" \\____|_____| |_|   |___|_| \\_|_|   \\___/ ",
	NULL
	};

	initscr();	// Start the curses mode
	noecho();	// Disblay the input characters
	cbreak();	// Disable key buffering and keep key signals
	start_color();	// Enable the color
	index = 0;

	use_default_colors();	// Set the background to default.
	init_pair(1, COLOR_YELLOW, -1); // Inisial forground and let the default background
	init_pair(2, COLOR_CYAN, -1);

	getmaxyx(stdscr, row, col);
	row = 1;

	// enable the attribute
	attron(COLOR_PAIR(1) | A_BOLD);
	// Print the ascii art title
	while (title[index] != NULL)
	{
		mvprintw(row + index, (col - strlen(title[index])) / 2, "%s", title[index]);
		index++;
	}
	attroff(COLOR_PAIR(1) | A_BOLD);
	
	getmaxyx(stdscr, row, col);
	attron(A_BOLD | COLOR_PAIR(2));
	// Sections
	mvprintw(row - 10, 2, "[1] - 42Program");
	mvprintw(row - 8, 2, "[2] - Web Development");
	mvprintw(row - 6, 2, "[3] - Grphical Programming");
	attroff(A_BOLD | COLOR_PAIR(2));
	
	option = getch();
	if (option == '1')
	{
		ft_print_projects(row, col);
	}

	refresh();
	getch();	
	endwin();

	return (0);
}
