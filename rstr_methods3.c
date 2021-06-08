#include "rstr.h"

int             is_str_at_rstr_end(t_rstr rs, char *str)
{
    int e;
    int i;
    int j;

    e = 0;
    i = rs->len - 1;
    j = ft_strlen(str) - 1;
    while (j >= 0 && rstr_get(rs, i) != 42)
    {
        if (rstr_get(rs, i) != str[j])
            return (1);
        j--;
        i--;
    }
    return (0);
}