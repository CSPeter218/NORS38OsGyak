#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
 int helyzet;

   pid_t valtozo;


    if((valtozo = fork())==-1)
        perror("Hiba");

    else if(valtozo == 0){
        excl("/bin/ls","-la", NUll);
        printf("Execlp hibás\n");
    }


    else{
        waitpid(valtozo,0,0);



        printf("\n A gyermek processz befejeződött!\n");
    }
return 0;
}
