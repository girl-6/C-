#include<stdio.h>
#include<stdlib.h>

int check_sys()//ǿ������ת��Ϊchar���ͣ�������1����С�ˣ������Ǵ��
{
	int a = 1;
	//����1��ʾС��,����0��ʾ���
	return (*(char*)&a);
}

int main()

{
	if (1 == check_sys())
		printf("С��\n");
	else
		printf("���\n");

	system("pause");
	return 0;
}
