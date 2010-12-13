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
	kom k, l;
	int in, out;
	long ident;  

	in = msgget(wejscie,0777);
	out = msgget(wyjscie, 0777);
	ident=getpid();

	printf("Podaj słowo polskie do przetłumaczenia na język angielski: ");
	scanf("%s", k.dane);

	k.size = strlen(k.dane);
	k.typ=ident;

	msgsnd(in,&k,sizeof(kom),0);
	printf("klient %5ld wyslalem: %s\n", ident, k.dane);

	msgrcv(out,&l,sizeof(kom),ident,0);
	printf("klient %5ld otrzymalem: %s\n", ident, l.dane);

	return 0;
}