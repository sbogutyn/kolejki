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
	char *wsk;
	long ident;  

	in = msgget(wejscie,0777);
	out = msgget(wyjscie, 0777);
	ident=getpid();

	printf("Podaj slowo angielskie do przetlumaczenia na jezyk polski: ");
	scanf("%s", k.dane);

	printf("Dane to: %s\n", k.dane);
	k.size = strlen(k.dane);
	wsk = (char*) k.dane;
	k.typ=ident;
	msgsnd(in,&k,sizeof(kom),0);
	printf("klient %5ld wyslalem %5d\n", ident, *wsk);
	msgrcv(out,&k,sizeof(char),ident,0);
	printf("klient %5ld otrzymalem %5d\n", ident, *wsk);
	return 0;
}