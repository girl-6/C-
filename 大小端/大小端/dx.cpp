#include<stdio.h>
#include<stdlib.h>

int check_sys()//强制类型转换为char类型，如果输出1就是小端，否则是大端
{
	int a = 1;
	//返回1表示小端,返回0表示大端
	return (*(char*)&a);
}

int main()

{
	if (1 == check_sys())
		printf("小端\n");
	else
		printf("大端\n");

	system("pause");
	return 0;
}
