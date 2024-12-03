#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>


int main()
{
    int fd = open("ossssd.txt",O_CREAT | O_RDONLY ,0777);
    char *str = get_next_line(fd);
    printf("%s",str);
    char *str1 = get_next_line(fd);
    printf("%s",str1);
    char *str2 = get_next_line(fd);
    printf("%s",str2);
    char *str3 = get_next_line(fd);
    printf("%s",str3);
    char *str33 = get_next_line(fd);
    printf("%s",str33);
    char *str5= get_next_line(fd);
    printf("%s",str5);
}