# include  < stdio.h >
# include  < stdlib.h >
# include  < unistd.h >
# include  < sys / type.h >
# include  < sys / wait.h >

int  main ()
{
    rendszer ( " cc gyermek.c -o gyermek.out " );
    rendszer ( " ./gyermek.out " );



    kilépés ( 0 );
}
