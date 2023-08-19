#include "main.h"

/**
 * print current environment
 * return 0;
*/
int main(void){
    unsigned int i;
    for (i=0; environ[i]; i++){
        puts(environ[i]);
    return 0;
    }
}