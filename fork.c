#include <stdio.h>
#include <unistd.h>
int main()
{
/* fork a child process */
fork();
printf("1\n");
/* fork another child process */
fork();
printf("2\n");
/* and fork another */
fork();
printf("3\n");

    return 0;
}

