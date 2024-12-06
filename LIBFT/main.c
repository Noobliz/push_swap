#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
