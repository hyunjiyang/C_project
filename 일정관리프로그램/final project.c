#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list//�ð� ����ü
{
	int year;
	int month;
	int day;
}list;

struct schedule //������ ����ü
{
	list time; // [1] ����ü�� ����� ������ ����ü
	char place[20];
	char plan[40];
};

void add(struct schedule sch[]);//[2]����ü �迭
void cs_print(struct schedule sch[]);//[2]����ü �迭
void search(struct schedule sch[]);//[2]����ü �迭
void edit(struct schedule sch[]);//[2]����ü �迭
void text(struct schedule sch[]);//[2]����ü �迭

static int num=1; //[4]�������� ����

struct schedule sch[3]; //[2]����ü �迭 
struct schedule* p = sch; // ����ü ������ ���� ����
int i, j;

int main()
{
	while (1)
	{
		int a;

		printf("--------------------------P.S.cheduler--------------------------\n\n"); //[5] ����� ģȭ�� �������̽�
		printf("   �� ���� �߰�\n     \n");
		printf("   �� ���� ����\n     \n"); //�ܼ�â ���
		printf("   �� ���� �˻�\n     \n"); //������ ���
		printf("   �� ���� ����\n     \n");
		printf("   �� ���� ����\n     \n"); //�ؽ�Ʈ���� ���
		printf("   �� ��     ��\n     \n");
		printf("-----------------------------------------------------------------\n"); //[5] ����� ģȭ�� �������̽�
		printf("���ϴ� �޴��� ��ȣ�� �Է����ּ���: "); scanf("%d", &a); 

		switch (a)
		{
		case 1://���� �߰�
			add(sch);
			break;
		case 2://���� ����
			cs_print(sch);
			break;
		case 3://���� �˻�
			search(sch);
			break;
		case 4://���� ����
			edit(sch);
			break;
		case 5://���� ����
			text(sch);
			break;
		case 6://����
			exit(0);


		}
	}

	return 0;
}

void add(struct schedule sch[])//[2]����ü �迭
{
	for (i = 0; i < 3; i++)
	{
		printf("\n------------------------->�����߰� [%d]<----------------------------\n",num); //[5] ����� ģȭ�� �������̽�
		printf("     ����: ");
		scanf("%d", &(p->time.year)); // [3] ����ü ������ ������ �̿��� ��� ����
		printf("       ��: ");
		scanf("%d", &(p->time.month)); // [3] ����ü ������ ������ �̿��� ��� ����
		printf("       ��: ");
		scanf("%d", &(p->time.day)); // [3] ����ü ������ ������ �̿��� ��� ����
		printf("     ���(���� ���� �ܾ�θ� �Է����ּ���): ");
		scanf("%s", p->place); // [3] ����ü ������ ������ �̿��� ��� ����
		printf("���� ����(���� ���� �ܾ�θ� �Է����ּ���): ");
		scanf("%s", p->plan); // [3] ����ü ������ ������ �̿��� ��� ����
		p++;
		num++;
	}
}

void cs_print(struct schedule sch[])//[2]����ü �迭
{
	printf("\n--------------------------P.S.cheduler--------------------------\n\n"); //[5] ����� ģȭ�� �������̽�
	printf("          �ð�          |      ���      |       ����           \n\n"); //[5] ����� ģȭ�� �������̽�
	for (i = 0; i < 3; i++)
	{
		printf("       %d�� ", sch[i].time.year);
		printf("%d�� ", sch[i].time.month);
		printf("%d��", sch[i].time.day);
		printf("	       %s ", sch[i].place);
		printf("	        %s \n", &sch[i].plan);
		
	}
	printf("----------------------------------------------------------------\n\n"); //[5] ����� ģȭ�� �������̽�
}

void search(struct schedule sch[])//[2]����ü �迭
{
	char find[20];
	printf("\n�˻��� ���� ������ �Է��ϼ��� (���� ������ �޴��� ���ư��ϴ�.):");
	scanf("%s", &find);

	for (i = 0; i < 3; i++)
	{
		if (strcmp(sch[i].plan, find) == 0)
		{
			printf("-------------------------->�˻� ���<--------------------------\n\n"); //[5] ����� ģȭ�� �������̽�
			printf("          �ð�          |      ���      |       ����           \n\n"); //[5] ����� ģȭ�� �������̽�
			printf("       %d�� ",  sch[i].time.year);
			printf("%d�� ", sch[i].time.month);
			printf("%d��", sch[i].time.day);
			printf("	       %s ", sch[i].place);
			printf("	        %s \n", &sch[i].plan);
			printf("---------------------------------------------------------------\n\n"); //[5] ����� ģȭ�� �������̽�
		}

	}
}

void edit(struct schedule sch[])//[2]����ü �迭
{
	char find[20];
	printf("\n�����ϰ��� �ϴ� ���� ������ �Է��ϼ��� :");
	scanf("%s", &find);

	for (i = 0; i < 3; i++)
	{
		if (strcmp(sch[i].plan, find) == 0)
		{
			printf("\n------------------------->��������<----------------------------\n"); //[5] ����� ģȭ�� �������̽�
			printf("     ����: ");
			scanf("%d", &sch[i].time.year, find); // [3] ����ü ������ ������ �̿��� ��� ����
			printf("       ��: ");
			scanf("%d", &sch[i].time.month, find); // [3] ����ü ������ ������ �̿��� ��� ����
			printf("       ��: ");
			scanf("%d", &sch[i].time.day, find); // [3] ����ü ������ ������ �̿��� ��� ����
			printf("     ���(���� ���� �ܾ�θ� �Է����ּ���): ");
			scanf("%s", &sch[i].place, find); // [3] ����ü ������ ������ �̿��� ��� ����
			printf("���� ����(���� ���� �ܾ�θ� �Է����ּ���): ");
			scanf("%s", &sch[i].plan, find); // [3] ����ü ������ ������ �̿��� ��� ����
		}

	}
}

void text(struct schedule sch[])//[2]����ü �迭
{
	FILE* f= fopen("data.txt", "w");
		if (f == NULL) 
			{
				printf("File error");
			}
		else 
			{
			fprintf(f,"--------------------------P.S.cheduler--------------------------\n\n"); //[5] ����� ģȭ�� �������̽�
			for (i = 0; i < 3; i++)
			{
				
				fprintf(f,"%d�� ", sch[i].time.year);
				fprintf(f,"%d�� ", sch[i].time.month);
				fprintf(f,"%d�� ", sch[i].time.day);
				fprintf(f,"%s ", sch[i].place);
				fprintf(f,"%s \n", &sch[i].plan);
			}
			fprintf(f, "---------------------------------------------------------------\n\n"); //[5] ����� ģȭ�� �������̽�
			fclose(f);
			}
			
}