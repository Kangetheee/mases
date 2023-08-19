#include "main.h"
/**
 * main function prints current environment
 * 
 * env is a pointer to environment
*/

int main(int acc __attribute__((unused)), char **av __attribute__ ((unused)), char **env){
    unsigned int i;
    for(i = 0; env[i];i++){
        puts(env[i]);
    }
    return 0;
}
