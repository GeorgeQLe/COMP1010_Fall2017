/*  Copyright 2017 George Le
    
    Date: 10/5/17 - 
    
    The purpose of this program is to teach!
*/
#include <stdio.h> // printf(), scanf() 

typedef enum Bool { UNSET = -1, FALSE, TRUE} bool;

bool askContinue();
void clearKeyboardBuffer();

int main(void)
{
    bool wantContinue = TRUE;
    
    
    
    do
    {
        // start from here next time
    } while(wantContinue);
}

bool askContinue()
{
    char y_or_n = ' ';
    bool wantContinue = UNSET;
    
    do
    {
        printf("Do you want to continue?: ");
        scanf("%c", &y_or_n);
        clearKeyboardBuffer();
        
        switch(y_or_n)
        {
            case 'y': case 'Y':
                wantContinue = TRUE;
                break;
            case 'n':
            case 'N':
                wantContinue = FALSE;
                break;
            default:
                printf("Error: You entered in %c\n", y_or_n);
        }
    } while(wantContinue == UNSET);
    
    return wantContinue;
}

void clearKeyboardBuffer()
{
    char temp;
    do
    {
        scanf("%c", &temp);
    }while(temp != '\n');
    
    while(getchar() == '\n')
}