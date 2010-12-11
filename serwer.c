#include <stdio.h>
#include <stdlib.h>
#include <linux/msg.h>
#include <linux/ipc.h>
#include <string.h>
#define wejscie 1862336293
#define wyjscie 1694564035

typedef struct komunikat {
	long typ;
	short size;
	char dane[256];
} kom;


int main() {

	kom k;
	int in, out;
	int dlugosc;
   	char *wsk;

	in = msgget(wejscie,0777|IPC_CREAT);
	out = msgget(wyjscie,0777|IPC_CREAT);
	msgrcv(in,&k,sizeof(kom),0,0);
	dlugosc = k.size;
	wsk = (char*) k.dane;
	printf("serwer: otrzymalem wiadomosc %s o rozmiarze %d od %5ld\n", wsk,k.size, k.typ);
	(*wsk)++;
	printf("serwer: odsylam %s do %5ld\n", wsk, k.typ);
	msgsnd(out,&k,sizeof(char),0);
	sleep(5);
	msgctl(in,IPC_RMID,0);
	msgctl(out,IPC_RMID,0);
	return 0;
}
