# include  < stdio.h >
# include  < unistd.h >
# include  < stdlib.h >
# include  < sys / file.h >
# include  < sys / type.h >
# include  < sys / stat.h >
# include  < fcntl.h >
# include  < string.h >



int  main ()
{
    int FÁJL;
    int vissza;
    char puffer [ 50 ];

    puffer [ 0 ] = 0 ;

    FÁJL = nyitott ( " NORS38.txt " , O_RDWR);

    ha (FÁJL == - 1 ) {
        perror ( " Fajl megnyitas open () -> hiba! \ n " );
        kilépés (- 1 );
    }
    else {

    }

    vissza = olvas (FÁJL, puffer, 50 );
    printf ( " % d byteot olvasott be read (). \ n \ n " , vissza);
    strcpy (puffer, " NORS38 " );


    vissza = lseek (FÁJL, 0 , SEEK_SET);
    printf ( " A lseek () beallitva a ->   % d . helyen " , vissza);

    vissza = ír (FÁJL, puffer, 6 );
    printf ( "  % d byteot irt ki a write () ...: % s \ n \ n \ n " , vissza, puffer);
    strcpy (puffer, " NORS38 " );

    bezár (FÁJL);

    visszatér  0 ;
}
