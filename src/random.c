#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
__declspec(dllexport) int radom(int small_number, int large_number) {
	int min = small_number;
	int max = large_number;
	return min + rand() % (max - min + 1);
}
__declspec(dllexport) char radon_str(char* string, int index) {
	(void)index;
	if (!string || !*string) return '\0';
	int ra = radom(0, (int)strlen(string) - 1);
	return string[ra];
}
__declspec(dllexport) int radon_strings(char* strings) {
	if (!strings || strlen(strings) < 2) return 0;
	int len = (int)strlen(strings) - 1;
	return radom(0, len);
}