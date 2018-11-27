#include "myheader.h"
unsigned int checksum_f = 62919;
int value_f = 2616;
unsigned int result = 0;
int main(void) {
	
	result = checksum_f + value_f;
	result = ~(result)<<16;

	printf("°ËÁõ : %x", result);

	return 0;
}