#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define GREEN "\033[1;32m"
#define RED "\033[38;5;9;1m"
#define NO_COLOR "\033[0m"
#define UP_LN "\033[1A"


void		ft_bzero(void *, size_t);
char		*ft_strcat(char *, char *);
int			ft_isupper(char);
int			ft_islower(char);
int			ft_isalpha(char);
int			ft_isdigit(char);
int			ft_isalnum(char);
int			ft_strlen(char *);

void	bzero_test()
{
	int		bsize = 100;
	char	buf[bsize];

	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	ft_bzero(&buf, bsize);
	for(int i = 0; i < bsize; ++i)
	{
		assert(buf[i] == 0);
	}
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	strcat_test()
{
	char	s1[] = "Hello \0yikes dude";
	char	*s2 = "World";
	char	*s3 = "Hello World";

	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	ft_strcat(s1, s2);
	assert(!strcmp(s1, s3));
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	isupper_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	assert(ft_isupper('B') == 1);
	assert(ft_isupper('b') == 0);
	assert(ft_isupper('a') == 0);
	assert(ft_isupper('Z') == 1);
	assert(ft_isupper('z') == 0);
	assert(ft_isupper(' ') == 0);
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	islower_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	assert(ft_islower('a') == 1);
	assert(ft_islower('z') == 1);
	assert(ft_islower('l') == 1);
	assert(ft_islower('~') == 0);
	assert(ft_islower('{') == 0);
	assert(ft_islower('`') == 0);
	assert(ft_islower(' ') == 0);
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	isalpha_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	assert(ft_isalpha('a') == 1);
	assert(ft_isalpha('z') == 1);
	assert(ft_isalpha('l') == 1);
	assert(ft_isalpha('A') == 1);
	assert(ft_isalpha('Z') == 1);
	assert(ft_isalpha('[') == 0);
	assert(ft_isalpha('{') == 0);
	assert(ft_isalpha('\n') == 0);
	assert(ft_isalpha('~') == 0);
	assert(ft_isalpha('{') == 0);
	assert(ft_isalpha('`') == 0);
	assert(ft_isalpha(' ') == 0);
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	isdigit_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	assert(ft_isdigit('0') == 1);
	assert(ft_isdigit('3') == 1);
	assert(ft_isdigit('9') == 1);
	assert(ft_isdigit(':') == 0);
	assert(ft_isdigit('/') == 0);
	assert(ft_isdigit('~') == 0);
	assert(ft_isdigit(' ') == 0);
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	isalnum_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('z') == 1);
	assert(ft_isalnum('l') == 1);
	assert(ft_isalnum('A') == 1);
	assert(ft_isalnum('Z') == 1);
	assert(ft_isalnum('[') == 0);
	assert(ft_isalnum('{') == 0);
	assert(ft_isalnum('\n') == 0);
	assert(ft_isalnum('~') == 0);
	assert(ft_isalnum('{') == 0);
	assert(ft_isalnum('`') == 0);
	assert(ft_isalnum(' ') == 0);
	assert(ft_isalnum('0') == 1);
	assert(ft_isalnum('3') == 1);
	assert(ft_isalnum('9') == 1);
	assert(ft_isalnum(':') == 0);
	assert(ft_isalnum('/') == 0);
	assert(ft_isalnum('~') == 0);
	assert(ft_isalnum(' ') == 0);
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	strlen_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	assert(ft_strlen("Hello World") == 11);
	assert(ft_strlen("Hell\0o World") == 4);
	assert(ft_strlen("1234567890") == 10);
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

int main(void)
{
	bzero_test();
	strcat_test();
	isupper_test();
	islower_test();
	isalpha_test();
	isdigit_test();
	isalnum_test();
	strlen_test();
	return (0);
}
