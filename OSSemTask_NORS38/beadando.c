#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <unistd.h>

#define MSGSZ 255 	// Üzenet hossza
#define KULCS 10	// Kulcs az üzenetsorhoz

typedef struct msgbuf
{
    long pid;
    char mtext[MSGSZ+1];
} message_buf;



int main()
{
    message_buf sbuf;
    sbuf.pid = getpid();	// PID inicializálás

    printf("Kezdőérték (PID) = %ld.\nKüldés folyamatban...", sbuf.pid);
            

    key_t key = KULCS; // Kulcs inicializálás
    int mask = 0644 | IPC_CREAT;	// Üzenetsor létrehozása
    int msgid = msgget(KULCS, mask);
    if (msgid < 0)
    {
        fprintf(stderr, "Nem sikerült a kulcs létrehozása.%d\n", KULCS);	// Hibaellenőrzés
        exit(EXIT_FAILURE);
    }


    do
    {
    sleep(1);
    sbuf.pid = sbuf.pid + 2;							// A feladat szerint PID küldése, majd vár 1 másodpercet, majd PID+2 küldése így tovább.
    msgsnd(msgid, &sbuf, strlen(sbuf.mtext)+1, 1);
    }while(1);


    return 0;
}