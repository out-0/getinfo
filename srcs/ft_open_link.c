#include "../getinfo.h"

// Open a link from terminal
void	ft_open_link(char *url)
{
	char	command[250];

	// Fill the (command) buffer with the customize command
	snprintf(command, sizeof(command), "xdg-open \"%s\" > /dev/null 2>&1 &", url);
	system(command); // Pass the command to terminal and excute it
}
