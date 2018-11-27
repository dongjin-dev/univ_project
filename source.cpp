#include "myheader.h"
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define STR strtol(strtok(strncpy(int_bf + (i * 5), buffer + (i * 4), 4), "-"), &pos, 16)



char buffer[100] = {};//파일에서 받아오는 배열
char int_bf[100] = {};//4개씩 끊은 데이터 저장하는 배열
int carry = 0;
unsigned int checksum = 0;
char * pos = NULL;
long value1 = 0;
long value2 = 0;
long value3 = 0;
char a[50] = {};

int i = 0;
int main2(void) {

	FILE* fp = NULL;
	
	fp = fopen("C:\\Users\\김동진\\Desktop\\network\\input.dat", "r");
	if (!feof(fp))
		/*fgets(buffer, 50, fp);*/
		fscanf(fp, "%s", buffer); //데이터 한줄로 입력 받기
	
	fclose(fp);
	printf("입력받은 데이터 : %s\n", buffer); //입력 검증

	for (i = 0; i < 11; i++) {
		
		strncpy(int_bf+(i*5), buffer + (i * 4), 4); //4개씩 쪼갠 데이터를 int_bf에 copy
		value2 += STR;
		if (i <10)
		{
			strcat(&int_bf[i*5], "-");
		}
		
			// 4자리 문자열을 16진수로 변환
		/*value2 += value2;*/
		//a += int_bf(i * 4);
		/*int_bf += int_bf*/
		//ten_bf[i] = hextoten(int_bf);
		/*printf("10진수 : %d\n",hextoten(int_bf));*/
		//printf("저장됐는지 확인(%d) : %d\n",i, ten_bf[i]);
	}
	/*printf("%s\n", a);*/
	
	/*printf("16진수 : %c\n", int_bf[3]);
	printf("16진수 : %s\n", int_bf);*/
	
	/*value2 = strtol(strtok(int_bf, "-"), &pos, 16);*/
	carry = (value2 >> 16 );
	printf("carry : %lx\n", carry);
	checksum = ((int)value2 << (32-16));
	checksum = (checksum >> 16);
	checksum = (int)checksum + carry;
	checksum = ~checksum;
	checksum = ((int)checksum << 16);
	checksum = checksum >> 16;
	printf("16진수 : %lx\n", value2);
	printf("checksum : %x\n", checksum);
	return 0;
}
