#include "myheader.h"
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define STR strtol(strtok(strncpy(int_bf + (i * 5), buffer + (i * 4), 4), "-"), &pos, 16)



char buffer[100] = {};//���Ͽ��� �޾ƿ��� �迭
char int_bf[100] = {};//4���� ���� ������ �����ϴ� �迭
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
	
	fp = fopen("C:\\Users\\�赿��\\Desktop\\network\\input.dat", "r");
	if (!feof(fp))
		/*fgets(buffer, 50, fp);*/
		fscanf(fp, "%s", buffer); //������ ���ٷ� �Է� �ޱ�
	
	fclose(fp);
	printf("�Է¹��� ������ : %s\n", buffer); //�Է� ����

	for (i = 0; i < 11; i++) {
		
		strncpy(int_bf+(i*5), buffer + (i * 4), 4); //4���� �ɰ� �����͸� int_bf�� copy
		value2 += STR;
		if (i <10)
		{
			strcat(&int_bf[i*5], "-");
		}
		
			// 4�ڸ� ���ڿ��� 16������ ��ȯ
		/*value2 += value2;*/
		//a += int_bf(i * 4);
		/*int_bf += int_bf*/
		//ten_bf[i] = hextoten(int_bf);
		/*printf("10���� : %d\n",hextoten(int_bf));*/
		//printf("����ƴ��� Ȯ��(%d) : %d\n",i, ten_bf[i]);
	}
	/*printf("%s\n", a);*/
	
	/*printf("16���� : %c\n", int_bf[3]);
	printf("16���� : %s\n", int_bf);*/
	
	/*value2 = strtol(strtok(int_bf, "-"), &pos, 16);*/
	carry = (value2 >> 16 );
	printf("carry : %lx\n", carry);
	checksum = ((int)value2 << (32-16));
	checksum = (checksum >> 16);
	checksum = (int)checksum + carry;
	checksum = ~checksum;
	checksum = ((int)checksum << 16);
	checksum = checksum >> 16;
	printf("16���� : %lx\n", value2);
	printf("checksum : %x\n", checksum);
	return 0;
}
