#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main ( void )
{
	printf("||||||||||||||\n") ;  //�ӤH���� 
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
	
	printf("�����N���~��...\n") ;
	getch() ;
	system("cls") ;
	
	int password , counter = 0 ;  //�ŧi��� 
	
	do
	{
		fflush ( stdin ) ;
		printf("�п�J4��ƱK�X:") ;
		scanf("%d", &password) ;
		
		if( password != 2025 )
		counter++ ;
		if( counter == 3 )
		{
			printf("ĵ�i!�o�i�ण�O�A���b��!\n") ;
			return 0 ;
		}
		
	}while( password != 2025 ) ;  //��password==2025���X�h�A�i��U�@�B�J�C 
	
	system("cls") ;
	
	char word ;  //�ŧi�r��
	int i = 0 , j = 0 , n = 0 , flag = 0 , triangle = 0 , y_or_n = 0 ; //�ŧi��ơA������n�Oflag=1... 
	
	do
	{
		system("cls") ;
		fflush( stdin ) ;
		
		printf("--------------------------\n") ;
		printf("| a. �e�X�����T���� 	|\n") ;
		printf("| b. ��ܭ��k�� 	|\n") ;
		printf("| c. ���� 		|\n") ;
		printf("--------------------------\n") ; 
	 
		printf("�п�Ja,b,c:\n") ;
		scanf("%c", &word ) ;
	
		//�]�����ؤ��h�A��switch�C 
		switch ( word )
		{
			case 'a' :
			case 'A' :
				
				system("cls") ;
				//�]���n�^�ӿ�J�A�ҥH�ΰj��C 
				do
				{
					fflush( stdin ) ;
					
					printf("�п�J'a'~'n'���r��:") ;
					scanf("%c", &triangle ) ;
					if( triangle < 'a' || triangle > 'n' )
						printf("�w�W�X�A�νd��!�ɭ��s��J!\n") ;
				} while( triangle < 'a' || triangle > 'n' ) ;
				//�ݨ�T���ΡA�Ĥ@��ı�����j��C 
				for( i = triangle ; i >= 'a' ; i-- )
				{
					for( j = 'a' ; j <= triangle ; j++ )  //�֤F�ӵ���... 
					{
						if( j < i )
							printf(" ") ;
						else
							printf("%c", j ) ;  //��Ascii code�ন�r�� 
					}
					printf("\n") ;
				}
				
				printf("�����N��^�쭺��...\n") ;
				getch() ;
				system("cls") ;
				break ;
				
			case 'b' :
			case 'B' :
				
				system("cls") ;
				
				do
				{
					fflush( stdin ) ;
					if( n < 1 || n >9 )
						printf("�w�W�X�A�νd��!�ɭ��s��J!\n") ;
					printf("�п�J1~9�����:") ;
					scanf("%d", &n ) ;
				} while( n < 1 || n >9 ) ;
				//�ݨ����ܼơA�Ĥ@��ı�����j��C 
				for( i = 1 ; i <= n ; i++ )
				{
					for( j = 1 ; j <= n ; j++ )
						printf("%3d*%3d=%3d", i , j , i*j ) ;
					printf("\n") ;
				}
				
				printf("�����N��^�쭺��...\n") ;
				getch() ;
				system("cls") ;
				break ;
				
			case 'c' :
			case 'C' :
				
				while( 1 )
				{
					fflush( stdin ) ;
					system("cls") ;
					
					printf("\'Contiune?(y/n)\'\n") ;
					scanf("%c", &y_or_n ) ;
					if( y_or_n == 'y' || y_or_n == 'Y' )
						break ;
					else if( y_or_n == 'n' || y_or_n == 'N' )
					{
						flag = 1 ;
						break ;
					}
						else
							printf("�Э��s��J\n") ;
				}							//�o�̦n���i�H��i... 
				
				break ;
			
			default :
				break ;
		}
	}while( flag != 1 ) ; //�ѤF�[����... 
	
	printf("Thanks for your using!\n") ;
	printf("�����N��d�ݤ߱o...\n") ;
	getch() ;
	system("cls") ;
	
	printf("�g�L�o�����{���m�ߡA�ڲ{�b�����x�j�骺�ϥΡA���ަb�ɾ��B�P�_����...�����ܤj�����ɡA\n") ;
	printf("�H�μW�j�ۤvdebug����O(�����D����Ѥ~��b�ŧi���ɭԧ�X���t��1)�A�T���Ϊ������A\n") ;
	printf("�ڤ]�O��ҤF�ܤ[�~�Q�X�P�_������A�]�ƲߤF�ܦh���y�k(switch)�C\n") ;
	printf("���ޫ�򻡡A�o����ڨ����O�Ӥj�D�ԡC\n") ;
	system("pause") ;
	return 0 ;

}
