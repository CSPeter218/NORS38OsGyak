# include  < stdlib.h >
# include  < stdio.h >
# include  < sys / type.h >
# include  < sys / ipc.h >
# include  < sys / sem.h >
# define  SEMKEY  0x12

int semID;
int nsems;
int semnum;
int r;
int semflag;
int cmd;

struct sembuf sembuf, * sop;
szakszervezeti szemun;

int  main ()
{
    int arg;
	nsems = 1 ;
	semflag = 00666 | IPC_CREAT;
	semID = semget (SEMKEY, nsems, semflag);
	if (semID < 0 ) {
        perror ( " Probléma / hiba! \ n " );
        visszatér  0 ;}
	más
        printf ( " Az ID avagy azonosító: % d \ n " , semID);
	printf ( " Kérem a semval értéket: " );

	semnum = 0 ;
	cmd = BEÁLLÍTÁS;
	scanf ( " % d " , & arg);
	r = semctl (semID, semnum, cmd, arg);
	printf ( " \ n Visszatérési érték: % d , semval érték: % d \ n " , r, arg);

    visszatér  0 ;

}
