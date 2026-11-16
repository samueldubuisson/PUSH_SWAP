#include "push_swap.h"

void    free_parse(char ***parse)
{
    int i;
    int j;

    i = 0;
    while (parse[i])
    {
        j = 0;
        while (parse[i][j])
        {
            free(parse[i][j]);
            j++;
        }
        free(parse[i]);
        i++;
    }
    free(parse);
}
char	***ft_parse_arguments(int argc, char *argv[])
{
	char	***parse;
	int	i;

	parse = ft_calloc(argc + 1, sizeof(char **));
	if (!parse)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		parse[i] = ft_split(argv[i], ' ');
		if (!parse[i])
		{
			free_parse(parse);
			return (NULL);
		}
		i++;
	}
	return (parse);
}
