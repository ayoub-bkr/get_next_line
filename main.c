#include "get_next_line.h"
#include <stdio.h>
int main()
{
    int a = open("text", O_RDONLY);
    char *str;
    // while (!(str = get_next_line(a)))
    // {
    //     printf("%s", str);
    //     free(str);
    // }
    // close(a);
    str = get_next_line(a);
    printf("%s", str);
    free(str);
    str = get_next_line(a);
    printf("%s", str);
    free(str);
    close(a);
    // printf("%s", get_next_line(a));
    // printf("%s", get_next_line(a));
    // printf("%s", get_next_line(a));
}