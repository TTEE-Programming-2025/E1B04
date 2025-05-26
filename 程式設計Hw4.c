#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STUDENTS 10
#define MIN_STUDENTS 5

typedef struct {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void my_style ( void ) ;
void show_menu ( void ) ;
void clear_screen( void ) ;
int get_valid_int(const char * , int , int ) ;
void enter_student_grades( void ) ;
void display_grades( void ) ;
void search_grades( void ) ;

float calc_average(Student s) {
    return (s.math + s.physics + s.english) / 3.0;
}


int main ( void )
{
	my_style ( ) ;
	
	int pwd , counter = 0 ;
	
	do
	{
		if( counter == 3 )
		{
			return 0 ;
		}
		printf("請輸入4位數的密碼: ") ;
		scanf("%d", &pwd ) ;
		if( pwd != 2025 )
		{
			counter++ ;
		}
	}
	while( pwd != 2025 );
	
	printf("welcome!\n") ;
	
	system("pause") ;
	system("cls") ;
	
	char choice ;
	
	while(1)
	{
		system("cls") ;
		show_menu ( ) ;
		printf("Enter your choice: ") ;
		scanf(" %c", &choice ) ;
		
		switch( choice )
		{
			case 'a' :
				enter_student_grades() ;
				break ;
			case 'b' :
				display_grades() ;
				break ;
			case 'c' :
				search_grades() ;
				break ;
		}
	}
	
	return 0 ;
	
	
}

void my_style ( void )
{
	printf("||||||||||||||\n") ;  //personal paint
	printf("||\n") ;
	printf("||\n") ;
	printf("||\n") ;
	printf("||||||||||||||\n") ;
	printf("            ||\n") ;
	printf("            ||\n") ;
	printf("            ||\n") ;
	printf("||||||||||||||\n") ;
	printf("\n") ;
	printf("||          ||\n") ;
	printf("||          ||\n") ;
	printf("||          ||\n") ;
	printf("||          ||\n") ;
	printf("||          ||\n") ;
	printf("||          ||\n") ;
	printf("||          ||\n") ;
	printf("||          ||\n") ;
	printf("||          ||\n") ;
	printf("||||||||||||||\n") ;
}

void show_menu ( void )
{
printf("------------[Grade System]----------\n") ;
printf("| a. Enter student grades 		|\n") ;
printf("| b. Display student grades 		|\n") ;
printf("| c. Search for student grades 		|\n") ;
printf("| d. Grade ranking 			|\n") ;
printf("| e. Exit system 			|\n") ;
printf("------------------------------------\n") ;
}

void clear_screen()
{
	system("cls") ;
}

int get_valid_int(const char *prompt, int min, int max) {
    int value;
    char newline;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &value, &newline) != 2 || newline != '\n') {
            printf("Invalid input. Please enter an integer.\n");
            fflush(stdin) ; // 清除緩衝區
        } else if (value < min || value > max) {
            printf("Value must be between %d and %d.\n", min, max);
        } else {
            return value;
        }
    }
}

void enter_student_grades() {
    clear_screen();
    int n = get_valid_int("Enter number of students (5~10): ", MIN_STUDENTS, MAX_STUDENTS);
    student_count = n;
	
	int i ;
    for ( i = 0 ; i < n ; i++ ) {
        printf("Student #%d:\n", i + 1);

        printf("  Enter name: ");
        while (getchar() != '\n'); // 清除前次輸入緩衝
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // 去除換行符

        while (1) {
            printf("  Enter 6-digit ID: ");
            if (scanf("%d", &students[i].id) != 1 || students[i].id < 100000 || students[i].id > 999999) {
                printf("  Invalid ID. Must be a 6-digit integer.\n");
                while (getchar() != '\n'); // 清除緩衝區
            } else {
                break;
            }
        }

        students[i].math = get_valid_int("  Math score (0-100): ", 0, 100);
        students[i].physics = get_valid_int("  Physics score (0-100): ", 0, 100);
        students[i].english = get_valid_int("  English score (0-100): ", 0, 100);
        students[i].average = calc_average(students[i]);
    }

    clear_screen();
    show_menu();
}

void display_grades() {
	int i ;
    clear_screen();
    printf("Name\tID\tMath\tPhysics\tEnglish\tAverage\n");
    for ( i = 0 ; i < student_count ; i++ ) {
        printf("%s\t%d\t%d\t%d\t%d\t%.1f\n",
               students[i].name, students[i].id,
               students[i].math, students[i].physics,
               students[i].english, students[i].average);
    }
    printf("\nPress any key to return to menu...\n");
    system("pause");
}

void search_grades() {
    char search_name[50] ;
    int found = 0 , i ;

    clear_screen();
    printf("Enter the name to search: ");
    while (getchar() != '\n'); // 清除前次輸入緩衝
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = '\0';

    for ( i = 0 ; i < student_count ; i++ ) {
        if (strcmp(students[i].name, search_name) == 0) {
            printf("\nFound:\n");
            printf("Name: %s\nID: %d\nMath: %d\nPhysics: %d\nEnglish: %d\nAverage: %.1f\n",
                   students[i].name, students[i].id,
                   students[i].math, students[i].physics,
                   students[i].english, students[i].average);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }

    printf("\nPress any key to return to menu...\n");
    system("pause");
}


