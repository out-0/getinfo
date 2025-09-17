#include "../getinfo.h"

// Print a message of opening a link in your browser
void	ft_opening_message(WINDOW *previous_window)
{
	WINDOW	*popup;
	char	*message;
	int	row, col, height, width, starty, startx;

	message = "Opening link in your browser. Press any key to continue...";

	getmaxyx(stdscr, row, col);	// Get the sizes of the previous screen
	height = row * 0.5;
	width = col;
	starty = row * 0.5;
	startx = 0;
	popup = newwin(height, width, starty, startx);	// Create the window
//	box(popup, 0, 0);
	wattron(popup, A_BOLD);
	mvwprintw(popup, height / 2, (col - strlen(message)) / 2, "%s", message);	// Print message
	wattroff(popup, A_BOLD);
	wrefresh(popup);
	
	wgetch(popup);
	// Clean the currect window and free its pointer.
	werase(popup);
	wrefresh(popup);
	delwin(popup);
	// Render the previous window
	touchwin(previous_window);
	wrefresh(previous_window);	

	return ;
}
