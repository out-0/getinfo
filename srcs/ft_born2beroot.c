#include "../getinfo.h"

void	ft_born2beroot(t_windows *win)
{
        int	row, col, height, width, startx, starty, option;

	getmaxyx(stdscr, row, col);
	height = row * 0.5;
	width = col;
	starty = row * 0.5;
	startx = 0;
	win->born2beroot = newwin(height, width, starty, startx);	// Create the window

	getmaxyx(win->born2beroot, row, col);	// Reinisialize the sizes with new window
	wattron(win->born2beroot, A_BOLD | COLOR_PAIR(2));	// Set attribute
	mvwprintw(win->born2beroot, 2, 2, "[1] - Virtual Machine");
	mvwprintw(win->born2beroot, 4, 2, "[2] - Operatin System");
	mvwprintw(win->born2beroot, 6, 2, "[3] - Graphical Interface");
	mvwprintw(win->born2beroot, 8, 2, "[4] - SELinux & AppArmor");
	mvwprintw(win->born2beroot, 10, 2, "[5] - apt | aptitude");
	mvwprintw(win->born2beroot, 2, col / 2, "[5] - Partitions|Ecryption|LVM");
	mvwprintw(win->born2beroot, 4, col / 2, "[6] - SSH | Firewall");
	mvwprintw(win->born2beroot, 6, col / 2, "[7] - Groups");
	mvwprintw(win->born2beroot, 8, col / 2, "[8] - Password policy");
	mvwprintw(win->born2beroot, 10, col / 2, "[9] - Project Guide");

	mvwprintw(win->born2beroot, row - 1, col - 12, "[0] - Back");
	wattroff(win->born2beroot, A_BOLD | COLOR_PAIR(2));

	wrefresh(win->born2beroot);	// Refresh to set the content
//	ft_open_link("https://www.brandonrohrer.com/ssh_at_home");
//	ft_open_link("https://opensource.com/article/20/9/ssh");
//	ft_open_link("https://linuxhaxor.net/code/sshd-config-file-complete-guide-for-linux.html");
	while ((option = wgetch(win->born2beroot)) != '0')
	{
		if (option == '8')
		{
			ft_open_link("https://ostechnix.com/how-to-set-password-policies-in-linux/");
			ft_opening_message(win->born2beroot);
		}
		if (option == '9')
		{
			ft_open_link("https://web.archive.org/web/20220508112038/https://www.codequoi"
				".com/en/born2beroot-02-configuring-a-debian-virtual-server/");
			ft_open_link("https://github.com/achrafelkhnissi/Born2beroot?tab=readme-ov-file");
			ft_opening_message(win->born2beroot);
		}
	}
	werase(win->born2beroot);
	wrefresh(win->born2beroot);
	delwin(win->born2beroot);;

	touchwin(win->projects);
	wrefresh(win->projects);
}
