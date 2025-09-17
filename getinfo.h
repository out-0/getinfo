#ifndef GET_INFO_H
# define GET_INFO_H

#include <ncurses.h>
#include <stdlib.h> // For system()
#include <string.h> // For strlen()
// Combine the windows in one struct for simple access
typedef struct s_windows
{
	WINDOW	*projects;
	WINDOW	*libft;
	
}	t_windows;

void	ft_42program(t_windows *win);
void	ft_libft(t_windows *win);
void	ft_opening_message(WINDOW *previous_window);	// Print link opening message

void	ft_open_link(char *url);

#endif
