#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t forked_id;
    int status;
    pid_t my_id;
    forked_id = fork();
    my_id = getpid();
 
    if (forked_id == 0) /* forked id = 0 for newly created process  */
		printf("Im the child: forked_id = %u, my_id = %u\n", forked_id, my_id);
    else
    {
        wait(&status);
        printf("Im the parent: forked_id = %u, my_id = %u\n", forked_id, my_id);
	}
	printf("$\n");
	return (0);

}
