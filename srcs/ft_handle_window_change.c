#include "../getinfo.h"

void	ft_handle_window_change(int signal)
{
	endwin();
	refresh();
	clear();
	ft_draw_menu();
}
