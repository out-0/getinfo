#include "../getinfo.h"

// Print the programs available at 42program and the resource for them (often links)
void	ft_42program(t_windows *win)
{
	int	row, col, option;

	getmaxyx(stdscr, row, col);	// Get the stadard screen sizes
	win->projects = newwin(row / 2, col, row / 2, 0);	// Inisial the new window
//	box(projects, 0, 0);	// The box border on the window
	getmaxyx(win->projects, row, col);	// Reinisialize the currect window rows and columns

	wattron(win->projects, COLOR_PAIR(2) | A_BOLD);
	
	mvwprintw(win->projects, 3, 2, "[1] - Libft");
	mvwprintw(win->projects, 4, 2, "[2] - get next line");
	mvwprintw(win->projects, 5, 2, "[3] - printf");
	mvwprintw(win->projects, 6, 2, "[4] - Born2beRoot");
	mvwprintw(win->projects, 7, 2, "[5] - FDF");
	mvwprintw(win->projects, row - 2, col - 12, "[0] - BACK");

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
	//	else if (option == '4')
	//		born2beroot();
	//	else if (option == '5')
	//		fdf();

	}
	werase(win->projects);
	wrefresh(win->projects);
	delwin(win->projects);
	touchwin(stdscr);
	wrefresh(stdscr);
	return ;
}
