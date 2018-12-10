#include <stdlib.h>
#include <stdio.h>


void		*ft_leo(size_t leo);
int			ft_strlen(char *str);

int main(void)
{
	void		*pendejada = NULL;

	pendejada = ft_leo(150);
	printf("vaina = |%p|\n", pendejada);
	printf("value of strlen = |%d|\n", ft_strlen("pendejada"));
	return (0);
}
