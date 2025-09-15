#include "../getinfo.h"

// Print the programs available at 42program and the resource for them (often links)
void	ft_42program()
{
	WINDOW	*projects;
	int	row, col, option;

	getmaxyx(stdscr, row, col);	// Get the stadard screen sizes
	projects = newwin(row - 9, col, row - 12, 0);	// Inisial the new window
//	box(projects, 0, 0);	// The box border on the window
	getmaxyx(projects, row, col);	// Reinisialize the currect window rows and columns

	wattron(projects, COLOR_PAIR(2) | A_BOLD);
	
	mvwprintw(projects, 1, 2, "[1] - Libft");
	mvwprintw(projects, 2, 2, "[2] - get next line");
	mvwprintw(projects, 3, 2, "[3] - printf");
        mvwprintw(projects, row - 2, col - 12, "[0] - BACK");

	wattroff(projects, COLOR_PAIR(2) | A_BOLD);
	wrefresh(projects);

	option = wgetch(projects);
	if (option == '0')
	{
		werase(projects);
		wrefresh(projects);
		delwin(projects);
		touchwin(stdscr);
		wrefresh(stdscr);
		return ;
	}
}
