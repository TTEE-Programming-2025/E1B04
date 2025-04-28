#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main ( void )
{
	printf("||||||||||||||\n") ;  //個人頁面 
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
	
	printf("按任意鍵繼續...\n") ;
	getch() ;
	system("cls") ;
	
	int password , counter = 0 ;  //宣告整數 
	
	do
	{
		fflush ( stdin ) ;
		printf("請輸入4位數密碼:") ;
		scanf("%d", &password) ;
		
		if( password != 2025 )
		counter++ ;
		if( counter == 3 )
		{
			printf("警告!這可能不是你的帳號!\n") ;
			return 0 ;
		}
		
	}while( password != 2025 ) ;  //讓password==2025跳出去，進行下一步驟。 
	
	system("cls") ;
	
	char word ;  //宣告字元
	int i = 0 , j = 0 , n = 0 , flag = 0 , triangle = 0 , y_or_n = 0 ; //宣告整數，為什麼要令flag=1... 
	
	do
	{
		system("cls") ;
		fflush( stdin ) ;
		
		printf("--------------------------\n") ;
		printf("| a. 畫出直角三角形 	|\n") ;
		printf("| b. 顯示乘法表 	|\n") ;
		printf("| c. 結束 		|\n") ;
		printf("--------------------------\n") ; 
	 
		printf("請輸入a,b,c:\n") ;
		scanf("%c", &word ) ;
	
		//因為項目不多，用switch。 
		switch ( word )
		{
			case 'a' :
			case 'A' :
				
				system("cls") ;
				//因為要回來輸入，所以用迴圈。 
				do
				{
					fflush( stdin ) ;
					
					printf("請輸入'a'~'n'的字元:") ;
					scanf("%c", &triangle ) ;
					if( triangle < 'a' || triangle > 'n' )
						printf("已超出適用範圍!糗重新輸入!\n") ;
				} while( triangle < 'a' || triangle > 'n' ) ;
				//看到三角形，第一直覺雙重迴圈。 
				for( i = triangle ; i >= 'a' ; i-- )
				{
					for( j = 'a' ; j <= triangle ; j++ )  //少了個等於... 
					{
						if( j < i )
							printf(" ") ;
						else
							printf("%c", j ) ;  //把Ascii code轉成字元 
					}
					printf("\n") ;
				}
				
				printf("按任意鍵回到首頁...\n") ;
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
						printf("已超出適用範圍!糗重新輸入!\n") ;
					printf("請輸入1~9的整數:") ;
					scanf("%d", &n ) ;
				} while( n < 1 || n >9 ) ;
				//看到雙變數，第一直覺雙重迴圈。 
				for( i = 1 ; i <= n ; i++ )
				{
					for( j = 1 ; j <= n ; j++ )
						printf("%3d*%3d=%3d", i , j , i*j ) ;
					printf("\n") ;
				}
				
				printf("按任意鍵回到首頁...\n") ;
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
							printf("請重新輸入\n") ;
				}							//這裡好像可以改進... 
				
				break ;
			
			default :
				break ;
		}
	}while( flag != 1 ) ; //忘了加分號... 
	
	printf("Thanks for your using!\n") ;
	printf("按任意鍵查看心得...\n") ;
	getch() ;
	system("cls") ;
	
	printf("經過這次的程式練習，我現在更能熟悉迴圈的使用，不管在時機、判斷條件...都有很大的提升，\n") ;
	printf("以及增強自己debug的能力(不知道哪位天才把在宣告的時候把旗杆另為1)，三角形的部分，\n") ;
	printf("我也是思考了很久才想出判斷的條件，也複習了很多的語法(switch)。\n") ;
	printf("不管怎麼說，這次對我來講是個大挑戰。\n") ;
	system("pause") ;
	return 0 ;

}
