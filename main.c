#include "floater.h"
#include <stdio.h>

int main() {
	char s[100];
	printf("Input float numer: ");
	scanf("%s", s);
	Float f = parse_float(s);
	char* out = fmt_float(f);
	printf("f is: %s\n", out);
	return 0;
}
