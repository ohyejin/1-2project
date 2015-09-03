

/*20143079 오예진
기말프로젝트 - 사용자 인터페이스*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "oh.h"

void userIntro()
{
	int first;

	printf("**********\n* 1.정렬 *\n* 2.추가 *\n* 3.변경 *\n* 4.삭제 *\n**********\n원하는 번호를 입력하세요.\n");
	scanf("%d", &first);

	if(first==1) //정렬
	{
		student_adjust();
	}

	else if(first==2) //추가
	{
		student_add();
	}

	else if(first==3) //변경
	{
		student_change();
	}

	else if(first==4) //삭제
	{
		student_delete();
	}

	else
	{
		printf("\n올바르지 않은 값을 입력하였습니다.\n");
		printf("프로그램을 종료합니다.\n\n");
	}
}
