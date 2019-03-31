#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define GREEN "\033[1;32m"
#define RED "\033[38;5;9;1m"
#define NO_COLOR "\033[0m"
#define UP_LN "\033[1A"

#include "libftASM.h"

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

void	isprint_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	assert(ft_isprint('a') == 1);
	assert(ft_isprint('z') == 1);
	assert(ft_isprint('l') == 1);
	assert(ft_isprint('A') == 1);
	assert(ft_isprint('Z') == 1);
	assert(ft_isprint('[') == 1);
	assert(ft_isprint('{') == 1);
	assert(ft_isprint('~') == 1);
	assert(ft_isprint('{') == 1);
	assert(ft_isprint('`') == 1);
	assert(ft_isprint(' ') == 1);
	assert(ft_isprint('1') == 1);
	assert(ft_isprint('3') == 1);
	assert(ft_isprint('9') == 1);
	assert(ft_isprint(':') == 1);
	assert(ft_isprint('/') == 1);
	assert(ft_isprint('~') == 1);
	assert(ft_isprint(' ') == 1);
	assert(ft_isprint(0) == 0);
	assert(ft_isprint(127) == 0);
	assert(ft_isprint(31) == 0);
	assert(ft_isprint('\t') == 0);
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	isascii_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	assert(ft_isascii('a') == 1);
	assert(ft_isascii('z') == 1);
	assert(ft_isascii('l') == 1);
	assert(ft_isascii('A') == 1);
	assert(ft_isascii('Z') == 1);
	assert(ft_isascii('[') == 1);
	assert(ft_isascii('{') == 1);
	assert(ft_isascii('~') == 1);
	assert(ft_isascii('{') == 1);
	assert(ft_isascii('`') == 1);
	assert(ft_isascii(' ') == 1);
	assert(ft_isascii('1') == 1);
	assert(ft_isascii('3') == 1);
	assert(ft_isascii('9') == 1);
	assert(ft_isascii(':') == 1);
	assert(ft_isascii('/') == 1);
	assert(ft_isascii('~') == 1);
	assert(ft_isascii(' ') == 1);
	assert(ft_isascii(-1) == 0);
	assert(ft_isascii(-128) == 0);
	assert(ft_isascii(-42) == 0);
	assert(ft_isascii(-99) == 0);
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	toupper_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	assert(ft_toupper('z') == 'Z');
	assert(ft_toupper('a') == 'A');
	assert(ft_toupper('l') == 'L');
	assert(ft_toupper('G') == 'G');
	assert(ft_toupper('@') == '@');
	assert(ft_toupper('~') == '~');
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	tolower_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	assert(ft_tolower('Z') == 'z');
	assert(ft_tolower('A') == 'a');
	assert(ft_tolower('L') == 'l');
	assert(ft_tolower('g') == 'g');
	assert(ft_tolower('@') == '@');
	assert(ft_tolower('~') == '~');
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	puts_test()
{
	ft_puts("\033[1;32m |OK| puts_test\033[0m\n");
}

void	strlen_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	assert(ft_strlen("Hello World") == 11);
	assert(ft_strlen("Hell\0o World") == 4);
	assert(ft_strlen("1234567890") == 10);
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	memset_test()
{
	char	*buf = malloc(25);
	bzero(buf, 25);
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	ft_memset(buf, 'a', 3);
	assert(strcmp(buf, "aaa") == 0);
	ft_memset(buf, 'b', 7);
	assert(strcmp(buf, "bbbbbbb") == 0);
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
	free(buf);
}

void	memcpy_test()
{
	char	*buf = malloc(25);
	bzero(buf, 25);
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	ft_memcpy(buf, "aaa\0", 4);
	assert(strcmp(buf, "aaa") == 0);
	ft_memcpy(buf, "bbbbbbb\0bb", 8);
	assert(strcmp(buf, "bbbbbbb") == 0);
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
	free(buf);
}

void	cat_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);
	int		fd = open("ashortfile", O_RDONLY);
	ft_cat(fd);
	close(fd);
	for (fd = 0; fd < 20; ++fd)
		printf("%s%s", UP_LN, "\033[2K");
	printf("%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
}

void	strdup_test()
{
	printf("%s |KO| %s%s\n", RED, __func__, NO_COLOR);

	char	*s, *s2;
	asprintf(&s, "%s%s |OK| %s%s\n", UP_LN, GREEN, __func__, NO_COLOR);
	s2 = ft_strdup(s);
	printf("%s", s2);
}

int main(void)
{
	bzero_test();
	strcat_test();
	isalpha_test();
	isdigit_test();
	isalnum_test();
	isascii_test();
	isprint_test();
	toupper_test();
	tolower_test();
	puts_test();
	strlen_test();
	memset_test();
	memcpy_test();
	strdup_test();
	cat_test();

	isupper_test();
	islower_test();
	return (0);
}
