#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define GREEN "\033[1;32m"
#define NO_COLOR "\033[0m"


void		ft_bzero(void *s, size_t n);
char		*ft_strcat(char *, char *);
int			ft_strlen(char *str);

void	bzero_check()
{
	int		bsize = 100;
	char	buf[bsize];

	ft_bzero(&buf, bsize);
	for(int i = 0; i < bsize; ++i)
	{
		assert(buf[i] == 0);
	}
	printf("%s |OK| ft_bzero%s\n", GREEN, NO_COLOR);
}

void	strcat_check()
{
	char	s1[] = "Hello \0yikes dude";
	char	*s2 = "World";
	char	*s3 = "Hello World";

	ft_strcat(s1, s2);
	assert(!strcmp(s1, s3));
	printf("%s |OK| ft_strcat%s\n", GREEN, NO_COLOR);
}

void	strlen_check()
{
	//printf("%d\n", ft_strlen("Hello World"));
	assert(ft_strlen("Hello World") == 11);
	printf("%s |OK| ft_strlen%s\n", GREEN, NO_COLOR);
}

int main(void)
{
	bzero_check();
	strcat_check();
	strlen_check();
	return (0);
}