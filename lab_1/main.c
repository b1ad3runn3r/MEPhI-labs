/* Вариант 18 */

#include <stdio.h>
#include <stdlib.h>

long long inv(long long num){
	long long res = 0;
	for (; num; num /= 10){
		res = res * 10 + num % 10;
	}

	return res;
}


int main(int argc, char** argv){
	if (argc != 3){
		printf("Usage: %s START END\n", argv[0]);
		return -1;
	}

	long long start = 1; start = atoll(argv[1]);
	long long end 	= 0; end   = atoll(argv[2]);
	
	if (start > end){
		printf("Wrong range!\n");
		return -1;
	}

	long long buf1 = 0, buf2 = 0;

	for(; start <= end; start++){
		buf1 = start * start; buf1 = inv(buf1);
		buf2 = inv(start); buf2 *= buf2;

		if (buf1 == buf2){
			printf("%lld\n", start);
		}

	}

	return 0;
}
