#include "../getinfo.h"

// Print the programs available at 42program and the resource for them (often links)
void	ft_42program(t_windows *win)
{
	int	row, col, height, width, starty, startx, option;

	getmaxyx(stdscr, row, col);	// Get the stadard screen sizes
	height = row * 0.5;	// Calcule the ration of half stdscr
	width = col;
	starty = row * 0.5;
	startx = 0;
	win->projects = newwin(height, width, starty, startx);	// Inisial the new window
//	box(win->projects, 0, 0);	// The box border on the window

	getmaxyx(win->projects, row, col);	// Reinisialize the row and col with new window
	wattron(win->projects, COLOR_PAIR(2) | A_BOLD);
	// Projects title	
	mvwprintw(win->projects, 2, 2, "[1] - Libft");
	mvwprintw(win->projects, 4, 2, "[2] - get next line");
	mvwprintw(win->projects, 6, 2, "[3] - printf");
	mvwprintw(win->projects, 8, 2, "[4] - Born2beRoot");
	mvwprintw(win->projects, 10, 2, "[5] - FDF");
	mvwprintw(win->projects, row - 1, col - 12, "[0] - BACK");

	wattroff(win->projects, COLOR_PAIR(2) | A_BOLD);
	wrefresh(win->projects);

	while ((option = wgetch(win->projects)) != '0')
	{
		if (option == '1')
			ft_libft(win);
	//	else if (option == '2')
	//		get_next_line();
	//	else if (option == '3')
	//		printf();
		else if (option == '4')
			ft_born2beroot(win);
	//	else if (option == '5')
	//		fdf();

	}
	// Clean the window and runder the stdscr
	werase(win->projects);
	wrefresh(win->projects);
	delwin(win->projects);
	touchwin(stdscr);
	wrefresh(stdscr);
	return ;
}
