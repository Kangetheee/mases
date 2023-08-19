#include "main.h"

/**
 * main function prints address of env and environ
 * @ac arg count
 * @av arg vector
 * return 0;
*/

int main(int ac __attribute__ ((unused)), char **av __attribute__ ((unused)), char **env)
{
	printf("&env: %p\n", &env);
	printf("&environ: %p\n", &environ);
	return (0);
}
