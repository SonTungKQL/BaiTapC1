#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000
void readFile(FILE * fPtr);
int countLettersInFile(FILE * fPtr);

int main()
{
    FILE *fPtr;
    char filePath[100];

    char dataToAppend[BUFFER_SIZE];


    printf("Nhap duong dan tep: ");
    scanf("%s", filePath);

    fPtr = fopen(filePath, "a");


    if (fPtr == NULL)
    {
        printf("\nKhong the mo '%s' file.\n", filePath);
        printf("Vui long kiem tra xem tep có ton tai hay không và ban có quyen ghi.\n");
        exit(EXIT_FAILURE);
    }


    
    printf("\nNhap du lieu du noi: ");
    
	while(1) 
	{	
		fflush(stdin);          
	    gets(dataToAppend);
	    
		if(strcmp(dataToAppend, "Exit")==0){  
			printf("Bye bye!");
			break;			
		}
	    
		
	    fputs(dataToAppend, fPtr);
	    fputc('\n', fPtr); 
	}	 

    fPtr = freopen(filePath, "r", fPtr);

    printf("\nÐa noi thanh cong du lieu vào tep. \n");
    printf("Ða thay doi noi dung tep:\n\n");
    readFile(fPtr);
    
    fPtr = freopen(filePath, "r", fPtr);
    printf("\n So chu cai trong tep la: %d", countLettersInFile(fPtr));
    printf("Bye Bye!");


    fclose(fPtr);

    return 0;
}



void readFile(FILE * fPtr)
{
    char ch;

    do 
    {
        ch = fgetc(fPtr);

        putchar(ch);

    } while (ch != EOF);
};

int countLettersInFile(FILE * fPtr)
{
    char ch;
	int count = 0;
    do 
    {
        ch = fgetc(fPtr);
        if (((ch >= 65) && (ch<=90)) || ((ch>=97) && (ch<=122)))
		{
        	count++;
        }

    } while (ch != EOF);    
    
    return count;
}

