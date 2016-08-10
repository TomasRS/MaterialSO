#include <stdio.h>
#include <memory.h>

int main(int argc, char** argv) {

	char str[80];
	strcpy(str, "these ");
	strcat(str, "strings ");
	strcat(str, "are ");
	strcat(str, "concatenated.");

	printf("%s", str);

    return 0;
 }
