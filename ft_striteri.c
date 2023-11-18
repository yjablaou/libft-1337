#include "libft.h"
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int i;

    i = 0;
    if (f == 0 || s == 0)
        return;
    
    while(s[i])
    {
        f(i,s[i]);
        i++;
    }
}
