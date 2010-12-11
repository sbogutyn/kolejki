#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
		if (strcmp(wyraz, wyrazy[i][0]) == 0) {
			return wyrazy[i][1];
		}
	}
	return "nie znaleziono wyrazu";
}


int main() {


	int i;

	printf("Tłumaczenie dla 'jeden' %s ", znajdz("jeden"));


	return 0;
}
