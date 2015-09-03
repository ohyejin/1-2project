

/* 학생 자료처리 - 변경 */

#include <stdio.h>
#include <stdlib.h>
#include "oh.h"

void student_change()
{
	FILE *file;

	int i=0;
	long j=0;
	int count=0;
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

	file=fopen("student.db", "w");

	//기존의 데이터 다시 보여줌
	printf("☞기존 데이터☜\n");
	printf("------------------------------");

	i=0;
	while(i<count)
	{
		printf("\n%s %ld %f\n", database[i].name, database[i].id, database[i].score);
		i++;
	}

	printf("------------------------------\n\n");

	printf("변경할 학번을 입력하세요.\n");
	scanf("%ld", &j);

	i=0;
	while(i<count)
	{
		if(database[i].id==j) //기존학번=입력한 학번
		{
			printf("이름 학번 점수를 입력하세요.\n"); //변경
			scanf("%s %ld %f", database[i].name, &database[i].id, &database[i].score);

			break;
		}
		i++;
	}

	i=0;
	while(i!=count) //수정된 사항을 student.db에 다시저장
	{
		fprintf(file, "%s %ld %f", database[i].name, database[i].id, database[i].score);
		i++;
	}
	fclose(file);


	///출력///
	printf("\n\n☞변경된 데이터☜\n");
	printf("(잘못 누르셨을 경우 다시 처음부터 시작해주세요.)\n");
	printf("\n\n*공지*\n학생수가 100명이 넘어갈 경우 100명까지만 출력합니다.\n\n");
	printf("------------------------------");

	i=0;
	while(i!=count)
	{
		printf("\n%s %ld %f\n", database[i].name, database[i].id, database[i].score);
		i++;
	}

	printf("------------------------------\n\n");

	userIntro(); //다시 처음부터

}
