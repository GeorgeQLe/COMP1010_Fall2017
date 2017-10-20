/*  Copyright 2017 George Le
    
    Date: 10/5/17 - 
    
    The purpose of this program is to teach!
*/
#include <stdio.h> // printf(), scanf() 

typedef enum Bool { UNSET = -1, FALSE, TRUE} bool;
typedef enum skeleton_states{NULLSTATE = -1, EXIT = 0, IDLE = 1, DEFENDS, GLARES, DIES, skeletonATTACKS} SkeletonStates;
typedef enum hero_actions {NOTHING = -1, FLEE, heroATTACKS, ADVANCES} HeroStates;

// Function that prompts and receives input from the user on what equation they would like 
// to be solved. Calls eval_equations() and then prints the result.
void receives_equation_input();
double eval_equation(double left, char operation, double right, int repetition);

// Function that prompts and receives input from the user on whether they want to continue
// using the program or not.
// Returns TRUE if they want to continue, returns FALSE otherwise
bool askContinue();

// Self-contained function that clears the keyboard buffer using a brute force method
void clearKeyboardBuffer();

typedef struct statemachine {
    SkeletonStates previous;
    SkeletonStates current;
    SkeletonStates next;
} StateMachine;

int main(void)
{
    do
    {
        // infinite loop
    } while(askContinue());
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

void receives_equation_input()
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
            printf("Error, enter in a new equation ex:a+b : ");
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
