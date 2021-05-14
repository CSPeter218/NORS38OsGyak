# include  < stdio.h >
# include  < stdlib.h >
# include  < unistd.h >
# include  < sys / type.h >
# include  < sys / wait.h >

int  main ()
{
int i = 0 ;


    pid_t valtozo = villa ();
    if (valtozo == 0 ) {
        printf ( " --- Gyermek processz --- \ n " );

    csinálni
    {

    printf ( " \ n \ n tanuló: Csősz Péter \ n Neptunkód: NORS38\ n " );
    i ++;

    } míg (i < 5 );

    kijárat ( 127 );
}
 else {
    waitpid (valtozo, 0 , 0 );



    printf ( " --- Szülõ processz --- \ n A processz befejezte a futását! \ n " );
}


visszatér  0 ;
}
