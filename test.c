/*  Copyright 2017 George Le
    
    Date: 10/5/17 - 
    
    The purpose of this program is to teach!
*/
#include <stdio.h> // printf(), scanf() 

typedef enum Bool { UNSET = -1, FALSE, TRUE} bool;

void receives_input();
double eval_equation(double left, char operation, double right, int repetition);
bool askContinue();
void clearKeyboardBuffer();

int main(void)
{
    do
    {
        receives_input();
    } while(askContinue());
}

void receives_input()
{
    // receives two values from the user to solve in an equation
    int left, right;
    // receives the return value of scanf to validate input
    int number_of_conversions;
    // receives the user's desired operation
    char operation;
    
    printf("Enter in an equation for this program to solve: ");
    number_of_conversions = scanf("%d%c%d", &left, &operation, &right);
    clearKeyboardBuffer();
    
    while(number_of_conversions != 3 || ((operation == '/') && (right == 0))
         || ((operation != '+') && (operation != '-') && (operation != '*') && (operation != '/'))) 
    {
        if((operation == '/') && (right == 0))
        {
            printf("Error, can't divide by zero.\nEnter in new equation: ");
        }
        else if((operation != '+') && (operation != '-') && (operation != '*') && (operation != '/'))
        {
            printf("Error, invalid operation. This calculator can only do +,-,*,/\n");
            printf("Enter in a new equation: ");
        }
        else
        {
            printf("Error, enter in a new equation ex:a+b :");
        }
        number_of_conversions = scanf("%d%c%d", &left, &operation, &right);
        clearKeyboardBuffer();
    }
    
    printf("The result is %lf\n", eval_equation(left, operation, right, 0));
}

double eval_equation(double left, char operation, double right, int repetition)
{
    double result = 0.0;
    
    while(repetition--)
    {
        switch(operation)
        {
            case '+':
            result = left + right;
            break;
            case '-':
            result = left - right;
            break;
            case '*':
            result = left * right;
            break;
            case '/':
            result = left / right;
            break;
        }
    }
    return result;
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
            case 'y': 
            case 'Y':
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
}