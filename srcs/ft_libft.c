#include "../getinfo.h"

void	ft_libft(t_windows *win)
{
	int		row, col, height, width, startx, starty, option;

	getmaxyx(stdscr, row, col);
	height = row * 0.5;
	width = col;
	starty = row * 0.5;
	startx = 0;
	win->libft = newwin(height, width, starty, startx);	// Create the window

//	box(win->libft, 0, 0);
	getmaxyx(win->libft, row, col);	// Reinsial the row and col with the new window(libft)
	// Articles part...
	wattron(win->libft, A_BOLD);
	wattron(win->libft, COLOR_PAIR(2));
	mvwprintw(win->libft, 2, 2, "Articles:");
	mvwprintw(win->libft, 4, 4, "[1] - Notion: Libraries expalination"); 
	mvwprintw(win->libft, 6, 4, "[2] - Github: Simple man for functions");
	mvwprintw(win->libft, 8, 4, "[3] - Videos: Explain shared and static libs");
	wattron(win->libft, COLOR_PAIR(2));

	// Solutions part...
	mvwprintw(win->libft, 2, col / 2, "Solutions:");
	wattron(win->libft, COLOR_PAIR(2));
	mvwprintw(win->libft, 4, (col / 2) + 2, "[4] - Libft Rewrite");
	mvwprintw(win->libft, 6, (col / 2) + 2, "[5] - 1337 | libft | Static library in C");
	mvwprintw(win->libft, 8, (col / 2) + 2, "[6] - Github repo solution");
	wattron(win->libft, COLOR_PAIR(2));

	mvwprintw(win->libft,row - 1, col - 12, "[0] - BACK");
	wattroff(win->libft, A_BOLD);
	while ((option = wgetch(win->libft)) != '0')
	{
		if(option == '1')
		{
			// Split the link since its long, compiler will concatenate them
			ft_open_link("https://www.notion.so/Libraries-24fc45f3babf809f8e06"
					"ceabdfb329ef?source=copy_link");
			ft_opening_message(win->libft);
		}
		else if (option == '2')
		{
			ft_open_link("https://github.com/lucAsC87/libftquickman");
			ft_opening_message(win->libft);
		}
		else if (option == '3')
		{	
			ft_open_link("https://youtu.be/JbHmin2Wtmc");
			ft_opening_message(win->libft);
		}
		else if (option == '4')
		{	
			ft_open_link("https://www.asidesigned.com/project-libft.html");
			ft_opening_message(win->libft);
		}
		else if (option == '5')
		{
			ft_open_link("https://medium.com/@ahmed.ezzouine/"
					"1337-libft-static-library-in-c-0b292982eb81");
			ft_opening_message(win->libft);
		}
		else if (option == '6')
		{	
			ft_open_link("https://github.com/MarkosComK/42-Libft");
			ft_opening_message(win->libft);
		}
	}
	werase(win->libft);
	wrefresh(win->libft);
	delwin(win->libft);
	touchwin(win->projects);
	wrefresh(win->projects);
	return ;
}
