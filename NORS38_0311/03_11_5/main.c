#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys / type.h>
#include <sys / wait.h>

int main ()
{
    int helyzet;
    pid_t valtozo;
    ha (((valtozo = villa ()) == - 1)
    perror ("Hiba");


    else if ((helyzet = execl ("/ bin / ls,", "- la", NULL)) <0)
           perror ("rendszer () hiba");

              ha [WIFEXITED (helyzet)]

             {
             printf ("Befejezõdés, visszakapott érték =% d \ n", WEXITSTATUS (helyzet));
          }

    ha (((valtozo = villa ()) == - 1)
        perror ("Hibaa");

    else if ((helyzet = rendszer ("körte")) <0)
        perror ("rendszer () hiba");

            ha [WIFEXITED (helyzet)]
    {

printf ("Nem normális végzõdés, visszatérõ érték =% d \ n", WEXITSTATUS (helyzet));
    }


    más{
        waitpid (valtozo, 0,0);


        printf ("\ n gyermek processz befejezte a futást! \ n");

    }


    visszatér 0;
}
