#include <stdio.h>
#include <stdlib.h>
#include <linux/msg.h>
#include <linux/ipc.h>
#include <string.h>
#include <signal.h>

#define wejscie 1862336293
#define wyjscie 1694564035
#define PL 0
#define ENG 1

typedef struct komunikat {
	long typ;
	short size;
	char dane[256];
} kom;

char* znajdz(char* wyraz) {
	char* wyrazy[][2] = {
		{"jeden", "one"},
		{"dom", "house"},
		{"rower", "bike"},
		{"piłka", "ball"}
	};
	int i;
	int wynik = 0;
	for (i=0;i<4;i++) {
		if (strcmp(wyraz, wyrazy[i][PL]) == 0) {
			return wyrazy[i][ENG];
		}
	}
	return "nie znaleziono wyrazu";
}

int in, out;
void przerwanie() {
	msgctl(in,IPC_RMID,0);
	msgctl(out,IPC_RMID,0);
	exit(0);
}

int main() {
	kom k;
	int dlugosc;
	char *wsk;
	in = msgget(wejscie,0777|IPC_CREAT);
	out = msgget(wyjscie,0777|IPC_CREAT);
	signal(SIGINT, przerwanie);
	while(1) {
		msgrcv(in,&k,sizeof(kom),0,0);
		dlugosc = k.size;
		wsk = (char*) k.dane;
		printf("serwer: otrzymalem wiadomosc %s o rozmiarze %d od %5ld\n", wsk,k.size, k.typ);
		strcpy(k.dane, znajdz(wsk));
		printf("serwer: odsylam %s do %5ld\n", k.dane, k.typ);
		msgsnd(out,&k,sizeof(kom),0);
	}
	return 0;
}
