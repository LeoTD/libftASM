#ifndef LIBFTASM_H
# define LIBFTASM_H

# include <stdlib.h>

void		ft_bzero(void *, size_t);
char		*ft_strcat(char *, char *);
int			ft_isupper(char);
int			ft_islower(char);
int			ft_isalpha(char);
int			ft_isdigit(char);
int			ft_isalnum(char);
int			ft_isascii(char);
int			ft_isprint(char);
char		ft_toupper(char);
char		ft_tolower(char);
int			ft_puts(char *);
int			ft_strlen(char *);
void		*ft_memset(void *, int, size_t);
void		*ft_memcpy(void *, void *, size_t);
void		ft_cat(int fd);
char		*ft_strdup(char *);

#endif
