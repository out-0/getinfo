#ifndef GET_INFO_H
# define GET_INFO_H

#include <ncurses.h>
#include <stdlib.h> // For system()
#include <string.h> // For strlen()
#include <signal.h> // For read signals recived from OS

// Combine the windows in one struct for simple access
typedef struct s_windows
{
	WINDOW	*projects;
	WINDOW	*libft;
	
}	t_windows;

void	ft_draw_menu(void);
void	ft_42program(t_windows *win);
void	ft_libft(t_windows *win);
void	ft_porn2beroot(t_windows *win);

void	ft_handle_window_change(int signal);	// Handle resizing
void	ft_opening_message(WINDOW *previous_window);	// Print link opening message
void	ft_open_link(char *url);	// Opne a link in the browser

#endif
