#include<stdio.h>
#include<stdlib.h>

int main ()
{
printf ("I am %d\n", getpid());

pid_t pid = fork();
printf ("I am %d\n", pid);

return 0;
}
