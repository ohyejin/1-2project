

/* 학생 자료처리 - 정렬 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "oh.h"

int compareName(const void *a, const void *b) //이름순
{
	return strcmp(((STUDENT *)a)->name, ((STUDENT *)b)->name);
}

int compareStudentNum(const void *a, const void *b) //학번순
{
	return (((STUDENT *)a)->id)-(((STUDENT *)b)->id);
}

int compareScore(const void *a, const void *b) //성적순
{
	return (((STUDENT *)a)->score)-(((STUDENT *)b)->score);
}

void student_adjust()
{
	
	FILE *file;

	int count=0;
	int nu1=0; //ui에서 입력받을 숫자
	int k=0;
	
	file=fopen("student.db", "r");

	while(!feof(file)) //database에 학생자료 받기
	{
		fscanf(file, "%s %ld %f", database[count].name, &database[count].id, &database[count].score);

		count++; //count=학생수
		if(count>=100) //학생수는 최대 100명
			count=100;
	}
	fclose(file);

	printf("************\n* 1.이름순 *\n* 2.학번순 *\n* 3.성적순 *\n*  4.뒤로  *\n************\n");
	scanf("%d", &nu1);

	if(nu1==1 || nu1==2 || nu1==3) //4번 및 오류값 입력시 출력할 필요x
		printf("\n\n*공지*\n학생수가 100명이 넘어갈 경우 100명까지만 출력합니다.\n\n");
	
	if(nu1==1) //정렬-이름순
	{
		qsort(database,count,sizeof(STUDENT),compareName);

		printf("☞이름순 정렬☜\n");
		printf("------------------------------");

		k=0;
		while(k!=count)
		{
			printf("\n%s %ld %f\n", database[k].name, database[k].id, database[k].score);
			k++;
		}

		printf("------------------------------\n\n");

		userIntro(); //다시 처음부터

	}

	else if(nu1==2) //정렬-학번순
	{

		qsort(database,count,sizeof(STUDENT),compareStudentNum);

		printf("☞학번순 정렬☜\n");
		printf("------------------------------");

		k=0;
		while(k!=count)
		{
			printf("\n%s %ld %f\n", database[k].name, database[k].id, database[k].score);
			k++;
		}

		printf("------------------------------\n\n");

		userIntro(); //다시 처음부터

	}

	else if(nu1==3) //정렬-성적순
	{

		qsort(database,count,sizeof(STUDENT),compareScore);

		printf("☞성적순 정렬☜\n"); 
		printf("------------------------------");

		k=0;
		while(k!=count)
		{
			printf("\n%s %ld %f\n", database[k].name, database[k].id, database[k].score);
			k++;
		}

		printf("------------------------------\n\n");

		userIntro(); //다시 처음부터

	}

	else if(nu1==4) //정렬-뒤로가기
	{
		userIntro();
	}

	else
		printf("올바르지 않은 값을 입력하였습니다.\n\n");

}
