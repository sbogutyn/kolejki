#include <stdio.h>
#include <stdlib.h>
#include <linux/msg.h>
#include <linux/ipc.h>

int main() {
	int liczba = ftok("/tmp", 111);
	int druga = ftok("/home", 101);
	printf("Wynik ftok() to: %d\n", liczba);
	printf("Wynik ftok() to: %d\n", druga);
	return 0;
}