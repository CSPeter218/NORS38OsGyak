# include  < stdio.h >
# include  < stdlib.h >
# include  < unistd.h >
# include  < jel.h >


// int kill (pid_t pid, int sig);
érvénytelen  RiasztásKezelo ( int sig);

int  main ( int argc, char ** argv)
{
    ha (argc! = 2 )
    {
        printf ( " Hasznalat: ./NORS38_gyak3 PID \ n " );
        visszatér  1 ;
    }

    pid_t pid = ( pid_t ) atoi (argv [ 1 ]);
    kill (pid, SIGALRM);

 if ( jel (SIGALRM, AlarmKezelo) == SIG_ERR)
    {
        printf ( " Nem sikerult handlert allitani a (z) \" SIGALRM \ " jelre! \ n " );
        visszatér  1 ;
    }
    szünet ();
    visszatér  0 ;
}
void  AlarmKezelo ( int sig)
{
    printf ( " NORS38 \ n Mostantol nem blokkolodok! \ n " );
    kilépés ( 1 );
}
