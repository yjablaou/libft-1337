#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

size_t find(const char *s, char c, int **l)
{
    size_t k = 0;
    size_t i = 0;
    size_t p = 0;
    *l = (int *)malloc((ft_strlen(s) + 1) * sizeof(int));
    if (!*l)
        return 0;
    
    while (s[p])
    {
        if (s[p] == c)
        {
            (*l)[k++] = p;
            i++;
        }
        p++;
    }
    (*l)[k] = p; // Store the end position at index k
    return (i + 1); // Return the count of delimiters + 1 (for the end position)
}

char **ft_split(char const *s, char c)
{
    size_t i;
    size_t p;
    char **str;
    int *l;

    p = 0;
    l = NULL;
    i = find(s, c, &l);
    if (!s || !(str = (char **)malloc((i + 1) * sizeof(char *))) || !l)
    {
        if (l)
            free(l);
        return (NULL);
    }
    while (p < i)
    {
        str[p] = ft_substr(s, (unsigned int)l[p] + 1, l[p + 1] - l[p] - 1);
        if (str[p] == NULL)
        {
            while (p > 0)
            {
                free(str[p]);
                p--;
            }
            free(str);
            free(l);
            return (NULL);
        }
        p++;
    }
    free(l);
    str[p] = NULL;
    return (str);
}

int main()
{
    char **result;
    char str[] = "This is a test string";
    char sep = ' ';

    result = ft_split(str, sep);

    if (result == NULL)
    {
        printf("Memory allocation error or input string is empty.\n");
        return 1;
    }

    // Print the resulting strings
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("Token %d: %s\n", i + 1, result[i]);
        free(result[i]); // Free each string
    }

    free(result); // Free the array of strings

    return 0;
}
