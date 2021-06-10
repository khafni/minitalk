/*
**	a resizable string that can be appended to its end
**	(a char * on steroids)
*/
#ifndef RSTR_H
# define RSTR_H
# include <stdlib.h>
# include <stdio.h>
# include "../tools/tools.h"

char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
void	*ft_mem_grow(void *addr, size_t old_size, size_t new_size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		strstr_modified(const char *haystack, const char *needle);

typedef struct s_rstr	*t_rstr;
struct			s_rstr
{
	char		*data;
	int			alloc;
	int			len;
};
/*
**	rstr constructor
*/
t_rstr	rstr_create (int alloc);
/*
**	rstr destructor
*/
void	rstr_destroy (void *rs);
/*
**	rstr setter
*/
void	rstr_set (t_rstr rs, size_t index, char value);
/*
**	appending to the end of the rstr
*/
void	rstr_add (t_rstr rs, char value);
/*
**	clear rstr
*/
void	rstr_clear(t_rstr rs);

/*
**	convert str to c string
*/

char	*rstr_to_cstr(t_rstr rs);
char	rstr_get(t_rstr rs, int index);
t_rstr	cstr_to_rstr(char *cstr);
/*
**	copy a c string to a resizble string without making
** a new resizble string in memory
*/
void	cstr_to_rstr_without_n_rs(char *src, t_rstr dst);

/*
** make a clone of a resizble string
*/
t_rstr	rstr_clone(t_rstr src);

int		is_str_at_rstr_end(t_rstr rs, char *str);
#endif