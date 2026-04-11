#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define dll __declspec(dllexport)
extern "C" {
	__declspec(dllexport) char* change_int_to_str(int string) {
		char* re;
		re = (char*)malloc(32);
		if (re) {
			snprintf(re, 32, "%d", string);
		}
		return re;
	}
	__declspec(dllexport) int free_str(char* str) {
		free(str);
		return 0;
	}
	__declspec(dllexport) char* add(const char* string1, const char* string2) {
		if (!string1) string1 = "";
		if (!string2) string2 = "";
		size_t n1 = strlen(string1);
		size_t n2 = strlen(string2);
		char* out = (char*)malloc(n1 + n2 + 1);
		if (!out) return NULL;
		memcpy(out, string1, n1);
		memcpy(out + n1, string2, n2 + 1);
		return out;
	}
}