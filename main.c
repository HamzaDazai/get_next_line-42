#include "stdio.h"
#include "get_next_line.h"
#include "unistd.h"
#include "fcntl.h"

void ll(){
    system("leaks a.out");
}

int main(){
    atexit(ll);
    int fd = open("get_next_line.c", O_RDONLY);
    char *s = NULL;

    while ((s = get_next_line(fd)) != NULL)
    {
        printf("%s", s);
        free(s);
        break;
    }
    return (0);
}
