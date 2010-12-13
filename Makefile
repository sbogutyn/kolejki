CC=gcc
KLIENT=klient
SERWER=serwer


all: klient serwer

klient: ${KLIENT}.c
	$(CC) ${KLIENT}.c -o ${KLIENT}

serwer: serwer.c
	$(CC) ${SERWER}.c -o ${SERWER}

clean:
	rm -f ${KLIENT} ${SERWER}
