#include "getinfo.h"

int	main(void)
{
	t_windows	win;
       	int		option;

	initscr();               // Start curses mode
	noecho();                // Disable input echo
	cbreak();                // Disable line buffering
	start_color();           // Enable colors
	use_default_colors();    // Use default terminal background
	curs_set(0);
	init_pair(1, COLOR_YELLOW, -1);
	init_pair(2, COLOR_CYAN, -1);

	signal(SIGWINCH, ft_handle_window_change); // Handle resize

	ft_draw_menu(); // Initial draw

	// Main loop
	while ((option = getch()) != '0')
	{
		if (option == '1')
			ft_42program(&win);
		// Add other options as needed
	}
	
	endwin(); // End curses mode
	return 0;
}

// Draw the main menu to the standard screen
void	ft_draw_menu(void)
{
	int		row, col, index = 0;
	const char	*title[] = {
		"  ____ _____ _____   ___ _   _ _____ ___  ",
		" / ___| ____|_   _| |_ _| \\ | |  ___/ _ \\ ",
		"| |  _|  _|   | |    | ||  \\| | |_ | | | |",
		"| |_| | |___  | |    | || |\\  |  _|| |_| |",
		" \\____|_____| |_|   |___|_| \\_|_|   \\___/ ",
		NULL
	};

	getmaxyx(stdscr, row, col);
	// Check if the rows and cols is soo small
	if (row < MIN_ROWS || col < MIN_COLS)
	{
		mvprintw(row * 0.5, (col - 28) * 0.5, "Please resize your terminal!");
		refresh();
		return ;
	}
	row = row * 0.2;

	attron(COLOR_PAIR(1) | A_BOLD);
	while (title[index] != NULL)
	{
		mvprintw(row + index, (col - strlen(title[index])) / 2, "%s", title[index]);
		index++;
	}
	attroff(COLOR_PAIR(1) | A_BOLD);

	getmaxyx(stdscr, row, col);
	attron(A_BOLD | COLOR_PAIR(2));
	mvprintw((row * 0.5) + 4, 2, "[1] - 42Program");
	mvprintw((row * 0.5) + 6, 2, "[2] - Web Development");
	mvprintw((row * 0.5) + 8, 2, "[3] - Graphical Programming");
	mvprintw(row - 2, col - 12, "[0] - EXIT");
	attroff(A_BOLD | COLOR_PAIR(2));

	refresh();
}
