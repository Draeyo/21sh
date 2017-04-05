#include "shell.h"

int		ft_chdir_error(char *path)
{
	struct stat	buf;

	if (access(path, F_OK) == -1)
		return (ft_error("cd", "No such file or directory", path));
	lstat(path, &buf);
	if (!S_ISDIR(buf.st_mode))
		return (ft_error("cd", "Not a directory", path));
	if (access(path, X_OK | R_OK) == -1)
		return (ft_error("cd", "Permission denied", path));
	return (-42);
}

void	ft_array_strdel(char **array)
{
	while (array && *array)
	{
		ft_strdel(array);
		array++;
	}
}

void	ft_fill_array(void **array, void *a1, void *a2, void *a3)
{
	array[0] = NULL;
	if (a1)
	{
		array[0] = a1;
		array[1] = NULL;
	}
	if (a1 && a2)
	{
		array[1] = a2;
		array[2] = NULL;
	}
	if (a1 && a2 && a3)
	{
		array[2] = a3;
		array[3] = NULL;
	}
}

void	ft_replace_word(char **s1, char *s2, char **s3, int i)
{
	while (s2 && *s2)
	{
		**s1 = *s2;
		*s1 += 1;
		s2 += 1;
	}
	*s3 += i - 1;
}