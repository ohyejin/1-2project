
void userIntro(); //사용자 인터페이스 함수

void student_adjust(); //정렬

void student_add(); //추가

void student_change(); //변경

void student_delete(); //제거

typedef struct {
	char name[20];
	long id;
	float score;
} STUDENT;

STUDENT database[101]; //학생정보를 담을 배열

int compareName(const void *a, const void *b); //이름비교
int compareStudentNum(const void *a, const void *b); //학번비교
int compareScore(const void *a, const void *b); //성적비교
