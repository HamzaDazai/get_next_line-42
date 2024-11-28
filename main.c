#include <fcntl.h>   // For open
#include <unistd.h>  // For read and close
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int fd = open("dazia.txt", O_CREAT | O_RDONLY );
    if (fd == -1)
        return(printf("the file descripter is fd"));
    ssize_t buffer_is_pr; // read ka return sh7al 9rat yak so had beffer kay tkhazen feh sh7al t9ra
    char buffer[100]; hana khan khazno sh
    buffer_is_pr = read(fd,buffer,sizeof(buffer ));
    buffer[buffer_is_pr] = '\0';
    printf("%s \n",buffer);
    int i = 2;
    while(i)
    {
        printf("ed");
    }
    return(printf("we donr"));
}