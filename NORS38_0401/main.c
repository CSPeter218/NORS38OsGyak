# include  < stdio.h >
# include  < stdlib.h >

# include  < unistd.h >
# include  < jel.h >

érvénytelen  Megszakitas ( int jel);
érvénytelen  kilepes ( int jel);

aláíratlan  int Megszakitasok = 0 ;

int  main ( érvénytelen )
{
    if ( jel (SIGINT, Megszakitas) == SIG_ERR)
    {
        printf ( " Nem sikerult handlert allitani a (z) SIGINT jelre! \ n " );
        visszatér  0 ;
    }

    if ( jel (SIGQUIT, kilepes) == SIG_ERR)
    {
        printf ( " Nem sikerult handlert allitani a (z) SIGQUIT jelre! \ n " );
        visszatér  0 ;
    }

    míg (Megszakitasok < 2 )
    {
        printf ( " Varakozas a jelre ... \ n " );
        alvás ( 1 );
    }

    printf ( " Megvan a masodik SIGINT jel! " );
    visszatér  0 ;
}

érvénytelen  Megszakitas ( int jel)
{
    printf ( " SIGINT jel: % d \ n " , jel);
    Megszakitasok ++;
}

érvénytelen  kilepes ( int jel)
{
    printf ( " SIGQUIT jel: % d \ n " , jel);
}
