#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h> 

#define password 2025
#define ROWS 9
#define COLS 9
#define BOOKED '*'
#define EMPTY '-' 


void my_style ( void ) ;
void case_A(char seats[ROWS][COLS]);
void case_B(char seats[ROWS][COLS]);
void case_C(char seats[ROWS][COLS]);
int case_D ( void ) ;
void init_seats(char seats[ROWS][COLS]);
void pause_and_clear();

int main ( void )
{
	my_style ( ) ;
	
	int pwd , counter = 0 , exit_choice ;
	char choice ;
	char seats[ROWS][COLS];
	// Use the current time as the seed to ensure that each execution has a different random number
    srand(time(NULL));  
	
    init_seats(seats); // Initialize seats	
	
	do
	{
		printf("Please enter your 4-digit password:") ;
		scanf("%d", &pwd ) ;
		if( pwd != password)
			counter++ ;
		if( counter == 3 )
			break ;
	}while( pwd != password ) ;
	
	if( counter == 3 )
	{
		printf("This may not be your account!\n") ;
		return 0 ;
	}
	
	printf("welcome!") ;
	system("pause") ;
	system("cls") ;
	
	while (1) {
    printf("----------[Booking System]----------\n"); 
    printf("| a. Available seats               |\n");
    printf("| b. Arrange for you               |\n");
    printf("| c. Choose by yourself            |\n");
    printf("| d. Exit                          |\n");
    printf("------------------------------------\n");

    
    scanf(" %c", &choice);  // Note ! That there is a blank space in front to handle line breaks

    switch (choice)
    {
        case 'a':
        case 'A':
            case_A(seats);
            pause_and_clear();
            break;
        case 'b':
        case 'B':
            case_B(seats);
            pause_and_clear();
            break;
        case 'c':
        case 'C':
     		case_C(seats);  // Pass in the seats array
    		pause_and_clear();
    		break;
	    case 'd':
        case 'D':
			exit_choice = case_D();
            if (exit_choice == 1)
            {
            	pause_and_clear();
    			break;
			}
            else
            {
            	return 0;  // The end . 
			}
            	
        default:
            printf("Invalid option!\n");
            pause_and_clear();
    }
	}
    return 0;
}

void pause_and_clear() 
{
    printf("Press any key to return to the menu...\n");
    getch();
    system("cls");
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

void init_seats(char seats[ROWS][COLS])
{
    int i , j ;
	for ( i = 0; i < ROWS; i++)
        for ( j = 0; j < COLS; j++)
            seats[i][j] = EMPTY;

    int booked = 0;
    while (booked < 10)
    {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == EMPTY)
        {
            seats[r][c] = BOOKED;
            booked++;
        }
    }
}


void case_A(char seats[ROWS][COLS])
{
    printf("\\123456789\n") ;

	int r , c ;
    for ( r = ROWS; r > 0; r-- )
    {
        printf("%d", r);
        
        for ( c = 0; c < COLS; c++ )
        {
         	
            printf("%c", seats[r-1][c]);
        }
	
        printf("\n");
    }

    getch(); // Wait for user keystroke
}

void case_B(char seats[ROWS][COLS])
{
    int n;
    char confirm;
    printf("Please enter the number of seats required¡]1~4¡^¡G");
    scanf("%d", &n);
    if (n < 1 || n > 4) 
	{
        printf("The number of seats does not match, return to the main menu...\n");
        getch();
        return;
    }

    int found = 0;

    // Find recommended seats

    if (n <= 3) {
        int i , j , k ;
		for ( i = 0; i < ROWS && !found; i++) {
            for ( j = 0; j <= COLS - n; j++) {
                int ok = 1;
                for ( k = 0; k < n; k++) {
                    if (seats[i][j + k] != EMPTY) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                	int k ;
					for ( k = 0; k < n; k++) {
                        seats[i][j + k] = '@';
                    }
                    found = 1;
                    break;
                }
            }
        }
    } else if (n == 4) {
        // Priority is given to four people in the same row.
        int i , j , k ;
		for ( i = 0; i < ROWS && !found; i++) {
            for ( j = 0; j <= COLS - 4; j++) {
                int ok = 1;
                for ( k = 0; k < 4; k++) {
                    if (seats[i][j + k] != EMPTY) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    int k ;
					for ( k = 0; k < 4; k++) {
                        seats[i][j + k] = '@';
                    }
                    found = 1;
                    break;
                }
            }
        }
        // Otherwise, find two people in two adjacent rows.
        if (!found) {
            int i , j ;
			for ( i = 0; i < ROWS - 1 && !found; i++) {
                for ( j = 0; j <= COLS - 2; j++) {
                    if (seats[i][j] == EMPTY && seats[i][j + 1] == EMPTY &&
                        seats[i + 1][j] == EMPTY && seats[i + 1][j + 1] == EMPTY) 
						{
                        	seats[i][j] = seats[i][j + 1] = seats[i + 1][j] = seats[i + 1][j + 1] = '@';
                        	found = 1;
                        	break;
                    	}
                }
            }
        }
    }

    if (!found)
	{
        printf("Couldn't find a suitable seat.\n");
        getch();
        return;
    }

    // Show suggested seating chart.
    printf("\\123456789\n");
    int r , c ;
	for ( r = ROWS; r > 0; r--) {
        printf("%d", r);
        for ( c = 0; c < COLS; c++) {
            printf("%c", seats[r-1][c]);
        }
        printf("\n");
    }

    printf("Are you satisfied with these suggested seats?(y/n)¡G");
    fflush(stdin);
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        // Change @ to *
        int i , j ;
		for ( i = 0; i < ROWS; i++)
            for ( j = 0; j < COLS; j++)
                if (seats[i][j] == '@')
                    seats[i][j] = BOOKED;

        printf("Seats reserved!\n");
    } else {
        // Restore @ to EMPTY
        int i , j ;
		for ( i = 0; i < ROWS; i++)
            for ( j = 0; j < COLS; j++)
                if (seats[i][j] == '@')
                    seats[i][j] = EMPTY;

        printf("The suggested seat has been cancelled.\n");
    }

    getch();
}	


void case_C(char seats[ROWS][COLS])
{
    int n;
    char input[10];
    int row, col;

    printf("Please enter the number of seats you would like to select¡]1~81¡^¡G");
    scanf("%d", &n);
    if (n < 1 || n > 81) {
        printf("The number of seats does not match, return to the menu...\n");
        getch();
        return;
    }
	int i , j ;
    for ( i = 0; i < n; i++) {
        while (1) {
            printf("Please enter seat number %d (format: row-col¡A¦p 3-5)¡G", i + 1);
            scanf("%s", input);
            if (sscanf(input, "%d-%d", &row, &col) != 2 ||
                row < 1 || row > ROWS || col < 1 || col > COLS) {
                printf("The format is incorrect, please reenter.\n");
                continue;
            }

            // Convert coordinates to array indices
            if (seats[row - 1][col - 1] == BOOKED || seats[row - 1][col - 1] == '@') {
                printf("The seat is occupied or has been selected repeatedly. Please re-enter the seat.\n");
                continue;
            }

            seats[row - 1][col - 1] = '@';
            break;
        }
    }

    // Show seating map
    printf("\\123456789\n");
    int r , c ;
	for ( r = ROWS; r > 0; r--) {
        printf("%d", r);
        for ( c = 0; c < COLS; c++) {
            printf("%c", seats[r - 1][c]);
        }
        printf("\n");
    }

    printf("Press any key to confirm seat selection.\n");
    getch();

    // Change @ to BOOKED
	for ( i = 0; i < ROWS; i++)
        for ( j = 0; j < COLS; j++)
            if (seats[i][j] == '@')
                seats[i][j] = BOOKED;
}


int case_D(void)
{
    char answer;

    while (1)
    {
        printf("Continue? (y/n): ");
        fflush(stdin) ;
		scanf(" %c", &answer);
        fflush(stdin) ;

        if (answer == 'y' || answer == 'Y') {
            return 1;  // back to menu
        }
        else if (answer == 'n' || answer == 'N') {
            printf("thanks for your using¡I\n");
            return 0;  // The end.
            break ;
        }
        	else {
            	printf("Input error, please enter 'y' or 'n'.\n");
        	}
    }
}

