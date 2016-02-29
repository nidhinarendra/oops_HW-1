#include <stdio.h>
#include <unistd.h>
int main()
{
int i=0;
for (i = 0; i < 4; i++)
{fork();

}
printf ("i am %d\n", i);
return 0;
}
