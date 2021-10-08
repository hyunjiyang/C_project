#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list//시간 구조체
{
	int year;
	int month;
	int day;
}list;

struct schedule //스케줄 구조체
{
	list time; // [1] 구조체를 멤버로 가지는 구조체
	char place[20];
	char plan[40];
};

void add(struct schedule sch[]);//[2]구조체 배열
void cs_print(struct schedule sch[]);//[2]구조체 배열
void search(struct schedule sch[]);//[2]구조체 배열
void edit(struct schedule sch[]);//[2]구조체 배열
void text(struct schedule sch[]);//[2]구조체 배열

static int num=1; //[4]정적변수 선언

struct schedule sch[3]; //[2]구조체 배열 
struct schedule* p = sch; // 구조체 포인터 변수 선언
int i, j;

int main()
{
	while (1)
	{
		int a;

		printf("--------------------------P.S.cheduler--------------------------\n\n"); //[5] 사용자 친화적 인터페이스
		printf("   ① 일정 추가\n     \n");
		printf("   ② 일정 보기\n     \n"); //콘솔창 출력
		printf("   ③ 일정 검색\n     \n"); //나만의 기능
		printf("   ④ 일정 수정\n     \n");
		printf("   ⑤ 일정 저장\n     \n"); //텍스트파일 출력
		printf("   ⑥ 종     료\n     \n");
		printf("-----------------------------------------------------------------\n"); //[5] 사용자 친화적 인터페이스
		printf("원하는 메뉴의 번호를 입력해주세요: "); scanf("%d", &a); 

		switch (a)
		{
		case 1://일정 추가
			add(sch);
			break;
		case 2://일정 보기
			cs_print(sch);
			break;
		case 3://일정 검색
			search(sch);
			break;
		case 4://일정 수정
			edit(sch);
			break;
		case 5://일정 저장
			text(sch);
			break;
		case 6://종료
			exit(0);


		}
	}

	return 0;
}

void add(struct schedule sch[])//[2]구조체 배열
{
	for (i = 0; i < 3; i++)
	{
		printf("\n------------------------->일정추가 [%d]<----------------------------\n",num); //[5] 사용자 친화적 인터페이스
		printf("     연도: ");
		scanf("%d", &(p->time.year)); // [3] 구조체 포인터 변수를 이용한 멤버 참조
		printf("       월: ");
		scanf("%d", &(p->time.month)); // [3] 구조체 포인터 변수를 이용한 멤버 참조
		printf("       일: ");
		scanf("%d", &(p->time.day)); // [3] 구조체 포인터 변수를 이용한 멤버 참조
		printf("     장소(띄어쓰기 없이 단어로만 입력해주세요): ");
		scanf("%s", p->place); // [3] 구조체 포인터 변수를 이용한 멤버 참조
		printf("일정 내용(띄어쓰기 없이 단어로만 입력해주세요): ");
		scanf("%s", p->plan); // [3] 구조체 포인터 변수를 이용한 멤버 참조
		p++;
		num++;
	}
}

void cs_print(struct schedule sch[])//[2]구조체 배열
{
	printf("\n--------------------------P.S.cheduler--------------------------\n\n"); //[5] 사용자 친화적 인터페이스
	printf("          시간          |      장소      |       내용           \n\n"); //[5] 사용자 친화적 인터페이스
	for (i = 0; i < 3; i++)
	{
		printf("       %d년 ", sch[i].time.year);
		printf("%d월 ", sch[i].time.month);
		printf("%d일", sch[i].time.day);
		printf("	       %s ", sch[i].place);
		printf("	        %s \n", &sch[i].plan);
		
	}
	printf("----------------------------------------------------------------\n\n"); //[5] 사용자 친화적 인터페이스
}

void search(struct schedule sch[])//[2]구조체 배열
{
	char find[20];
	printf("\n검색할 일정 내용을 입력하세요 (내용 없을시 메뉴로 돌아갑니다.):");
	scanf("%s", &find);

	for (i = 0; i < 3; i++)
	{
		if (strcmp(sch[i].plan, find) == 0)
		{
			printf("-------------------------->검색 결과<--------------------------\n\n"); //[5] 사용자 친화적 인터페이스
			printf("          시간          |      장소      |       내용           \n\n"); //[5] 사용자 친화적 인터페이스
			printf("       %d년 ",  sch[i].time.year);
			printf("%d월 ", sch[i].time.month);
			printf("%d일", sch[i].time.day);
			printf("	       %s ", sch[i].place);
			printf("	        %s \n", &sch[i].plan);
			printf("---------------------------------------------------------------\n\n"); //[5] 사용자 친화적 인터페이스
		}

	}
}

void edit(struct schedule sch[])//[2]구조체 배열
{
	char find[20];
	printf("\n수정하고자 하는 일정 내용을 입력하세요 :");
	scanf("%s", &find);

	for (i = 0; i < 3; i++)
	{
		if (strcmp(sch[i].plan, find) == 0)
		{
			printf("\n------------------------->일정수정<----------------------------\n"); //[5] 사용자 친화적 인터페이스
			printf("     연도: ");
			scanf("%d", &sch[i].time.year, find); // [3] 구조체 포인터 변수를 이용한 멤버 참조
			printf("       월: ");
			scanf("%d", &sch[i].time.month, find); // [3] 구조체 포인터 변수를 이용한 멤버 참조
			printf("       일: ");
			scanf("%d", &sch[i].time.day, find); // [3] 구조체 포인터 변수를 이용한 멤버 참조
			printf("     장소(띄어쓰기 없이 단어로만 입력해주세요): ");
			scanf("%s", &sch[i].place, find); // [3] 구조체 포인터 변수를 이용한 멤버 참조
			printf("일정 내용(띄어쓰기 없이 단어로만 입력해주세요): ");
			scanf("%s", &sch[i].plan, find); // [3] 구조체 포인터 변수를 이용한 멤버 참조
		}

	}
}

void text(struct schedule sch[])//[2]구조체 배열
{
	FILE* f= fopen("data.txt", "w");
		if (f == NULL) 
			{
				printf("File error");
			}
		else 
			{
			fprintf(f,"--------------------------P.S.cheduler--------------------------\n\n"); //[5] 사용자 친화적 인터페이스
			for (i = 0; i < 3; i++)
			{
				
				fprintf(f,"%d년 ", sch[i].time.year);
				fprintf(f,"%d월 ", sch[i].time.month);
				fprintf(f,"%d일 ", sch[i].time.day);
				fprintf(f,"%s ", sch[i].place);
				fprintf(f,"%s \n", &sch[i].plan);
			}
			fprintf(f, "---------------------------------------------------------------\n\n"); //[5] 사용자 친화적 인터페이스
			fclose(f);
			}
			
}