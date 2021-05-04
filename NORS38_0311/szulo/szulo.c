# include  < stdio.h >
# include  < stdlib.h >
# include  < unistd.h >
# include  < sys / type.h >
# include  < sys / wait.h >

int  main ()
{
    rendszer ( " cc child.c -o child.out " );
    rendszer ( " ./child.out " );



    kilépés ( 0 );
}
