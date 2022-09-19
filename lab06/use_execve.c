#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char ** argv) {
    char *myargv[2];
    
    myargv[0] = "/usr/bin/printenv";
    myargv[1] = NULL;
    
    //execve("/usr/bin/printenv", myargv, NULL);
    execve("/usr/bin/env", argv, environ);
    
    return 0;
}