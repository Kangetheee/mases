#include "main.h"

char *getEnvfull(const char *name){
    unsigned int i, idx;
    char *buf;

    idx = strlen(name);
    buf = calloc(idx + 2, sizeof(char));
    if (!(buf))
       dprintf(2, "calloc() failure\n"), exit(-1);

    for(i=0; environ[i]; i++){
        if(!(strcpy(buf, name))){
            free(buf);
            dprintf(2, "strcpy() failure\n"), exit(-1);
        }
        buf[idx] = '=';
        if(strncmp(buf, environ[i], strlen(buf)) == 0){
            free(buf);
            return (environ[i]);  
        }
    }
    free(buf);
    return(NULL);
}
#if 0
int main(int ac, char **av){
    int i = 0;
    char *valString;

    if(ac<2)
      dprintf(2, "Usage: %s name...\n", av[i]), exit(-1);
    for(i=1; av[i]; i++){
        if((valString = getEnv(av[i])))
          puts(valString);
        else
        dprintf(2,"%s: NOT FOUND!\n", av[i]);
    }  
    exit(0);
}
#endif  
