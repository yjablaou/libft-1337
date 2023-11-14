#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

size_t find(const char *s, char c, int **l) {
    size_t k = 0;
    size_t i = 0;
    size_t p = 0;
    *l = (int *)malloc((ft_strlen(s) + 1) * sizeof(int));
    if (!*l) return 0;

    while (s[p]) {
        if (s[p] == c) {
            (*l)[k++] = p;
            i++;
        }
        p++;
    }
    (*l)[k] = -1; // Use -1 to mark the end of positions instead of the string length
    return (i);   // Return the count of delimiters
}

char **ft_split(char const *s, char c) {
    size_t i;
    size_t p;
    char **str;
    int *l;

    if (!s || !(l = (int *)malloc((ft_strlen(s) + 1) * sizeof(int))))
        return (NULL);

    i = find(s, c, &l);
    if (!(str = (char **)malloc((i + 1) * sizeof(char *)))) {
        free(l);
        return (NULL);
    }

    p = 0;
    i = 0;
    while (l[i] != -1) {
        str[i] = ft_substr(s, p, l[i] - p);
        if (str[i] == NULL) {
            while (i > 0)
                free(str[--i]);
            free(str);
            free(l);
            return (NULL);
        }
        p = l[i++] + 1;
    }
    str[i] = NULL;
    free(l);
    return (str);
}

int main() {
    char **result;
    char str[] = "This is a test string jbjbk jbjkbjb kjkjbnkjn jkbkjbkub hjbujbub uibkub biubjkbinb kibikbuk buknb jkb jkbn ionkb jkbuk bjkbkj ";
    char sep = ' ';

    result = ft_split(str, sep);

    if (result == NULL) {
        printf("Memory allocation error or input string is empty.\n");
        return 1;
    }

    // Print the resulting strings
    for (int i = 0; result[i] != NULL; i++) {
        printf("Token %d: %s\n", i + 1, result[i]);
        free(result[i]); // Free each string
    }

    free(result); // Free the array of strings

    return 0;
}
