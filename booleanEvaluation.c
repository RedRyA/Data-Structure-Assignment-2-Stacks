#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "stack.h"
#include "booleanEvaluation.h"
#include "booleanWithError.h"



/* TODO
 * printName
 * input: none
 * output: none
 *
 * Prints name of the student who worked on this solution
 */
void printName( )
{
    /* TODO : Fill in your name */
    printf("This solution was completed by:\n");
    printf("<Ryan Reddoch>\n");
}




/* TODO
 * evaluatePostfix
 * input: a postfix expression (calls tokenizeString to get the tokens from the string)
 * output: T, F, or E
 *
 * Uses a stack to evaluates the postfix expression and returns the result as a string where "T" denotes true and "F" denotes false.
 * If the postfix expression is invalid it returns "E" to denote an error has occurred.  Be sure to use the helpful functions in booleanEvaluation.
 *
 * Hints:
 * - DO NOT free the parameter str.  It is freed by the calling function.
 * - Be sure to use the helpful functions in booleanEvaluation.
 * - Test your code often!  Get it working correctly for the first couple test cases instead of trying to solve all of them at once.
 */
char *evaluatePostfix( char *str )
{

    Stack *s= createStack();
  


int op1; // holds 1st operand
int op2; // holds 2nd operand
char* x[10];  // holds operator;
char* testArray[]= {"NOT","AND","NAND","OR","NOR","XOR","COND","BICOND"};
int i=0;
int j=0;
int count=0;
boolean bool;
char bool2str;
 int boolyTest;
 int strTest;
     /*TOKEN  */
     int tokenCount;
 char **arrTokens = tokenizeString(str, &tokenCount);

 op1 = (int *)malloc(sizeof(int) * count);
 op2 = (int *)malloc(sizeof(int) * count);
 /* Your variable Declarations: */

 /* Currently commented out to prevent a memory leak.  Uncomment to get the tokens from str. */

 /* ARRTOKENS HOLD T F IN THE i AND OPERATORS IN J, */
 /* iterate through arrTokens, push operands in stack */
  for (i=0;i<tokenCount;i++) {
  for (j=0;j<tokenCount;j++){

      if (strcmp(arrTokens[i][j], 'T') || strcmp(arrTokens[i][j], 'F'))   
      {
        // this takes 
          bool = stringToBoolean(&arrTokens[i][j]);

          push(s, &bool);
          printf("%s TEST ME BRAH \n", top(s));
          j++;

// THIS X HOLDS WHAT I NEED 
x[i]=arrTokens[j];

 printf(" X Value %s \n ",x[0]);

      }
 
  
  }
   i++;    
  }

  /*TRIED TO SET X[0] TO A VAR BUT DID NOT WORK */
/////////////////////////////////
  /* NOT TEST */
   strTest = strcmp(x[0], "NOT");

  if (strTest = 0)
  {

int op1=pop(s);
 bool2str=booleanToString(boolyTest);
 boolyTest=!op1;

 printf("%d !Not test \n",boolyTest);
push(s,boolyTest);
free(op1);
free(x);
 return boolyTest;
  }

  ////////// AND TEST //////////////

   strTest = strcmp(x[0], "AND");

  if (strTest = 0)
  {
 printf("%d AND test\n ");
 int op2 = pop(s);
 op1=pop(s);
  bool2str = booleanToString(boolyTest);
  boolyTest = (op1 && op2);
 push(s, boolyTest);
 printf("%s Top TEST \n", top(s));
 free(op1);
 free(op2);
 free(x);
 freeStackElements(s);
 freeStack(s);
 return boolyTest;
  }
  /////////////////////////////////////

  // freeStackElements(&s);
  // freeStack(&s);
  return booleanToString(boolyTest);
  /* Replace this with your actual solution to return */

}
//}


/* TODO
 * postfixToInfix
 * input: a postfix expression (calls tokenizeString to get the tokens from the string)
 * output: the equivalent infix expression
 *
 * Uses a stack to convert str to its equivalent expression in infix.
 * You can assume that the postfix expression is valid
 *
 * Hints:
 * - DO NOT free the parameter str.  It is freed by the calling function.
 * - Be sure to use the helpful functions in booleanEvaluation.
 * - Test your code often!  Get it working correctly for the first couple test cases instead of trying to solve all of them at once.
 */

//////////////////////////////////
///////////////////////////////



char *postfixToInfix( char *str )
{
 /*   
Stack s;
int count; //counts tokens
char* op1; // holds 1st operand
char* op2; // holds 2nd operand
char* x;  // holds operator;
Stack createStack();
*/
    /* Your variable Declarations: */
 //   int tokenCount;
 //   char** arrTokens = tokenizeString( str, &tokenCount );  /* Currently commented out to prevent a memory leak.  Uncomment to get the tokens from str. */




    /* Your code: */




    return booleanToString( ERROR ); /* Replace this with your actual solution to return */
}

/* You may want to create some helper functions down here! */
