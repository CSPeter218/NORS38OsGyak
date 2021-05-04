#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/msg.h>


#define MSGSZ 255	// Üzenet hossza
#define KULCS 10	// Kulcs az üzenetsorhoz

typedef struct msgbuf
{
    long mtype;
    
} message_buf;

static void kezelo(int);

int main()
{
    key_t key = KULCS;	// Kulcs inicializálás
    int msgflg = 0644;
    message_buf rbuf;

    int msqid = msgget(KULCS, msgflg);

    if (msqid < 0)
    {
        perror("msgget() hiba!\n");
        exit(1);
    }

    signal(SIGINT, kezelo);

    rbuf.mtype = 1;
    for ( ; ; )
    {
        printf("Várakozás...\n");
        ssize_t byteok = msgrcv(msqid, &rbuf, MSGSZ, 0, 0);
        if (byteok < 0)
        {
            perror("msgrcv() hiba!\n");		// Hibaellenőrzés
            exit(1);
        }
        printf("PID: %ld\n\n", rbuf.mtype);	// PID kiíratása
    }

    return 0;
}

static void kezelo(int sig)
{
    signal(sig, SIG_IGN);
    int mask, msgid;
    key_t key = KULCS;
    mask = 0644;
    msgid = msgget(KULCS, mask);

    if (msgid == -1)
    {
        printf("Az üzenetsor nem létezik!\n");	// Hibaellenőrzés
        exit(EXIT_SUCCESS);
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1)
    {
        fprintf(stderr, "Az üzenetsort nem sikerült törölni.\n");	// Hibaellenőrzés
        exit(EXIT_FAILURE);
    }
    else
        printf("\nAz üzenetsor sikeresen törölve.\n"); 	//Ctrl + C esetén a megállást jelzi
    exit(0);
}