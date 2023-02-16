#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "booleanEvaluation.h"
#include "booleanWithError.h"
#include "stack.h"

/* TODO
 * printName
 * input: none
 * output: none
 *
 * Prints name of the student who worked on this solution
 */
void printName()
{
  /* TODO : Fill in your name */
  printf("This solution was completed by:\n");
  printf("<Ryan Reddoch>\n");
}

/* TODO
 * evaluatePostfix
 * input: a postfix expression (calls tokenizeString to get the tokens from the
 * string) output: T, F, or E
 *
 * Uses a stack to evaluates the postfix expression and returns the result as a
 * string where "T" denotes true and "F" denotes false. If the postfix
 * expression is invalid it returns "E" to denote an error has occurred.  Be
 * sure to use the helpful functions in booleanEvaluation.
 *
 * Hints:
 * - DO NOT free the parameter str.  It is freed by the calling function.
 * - Be sure to use the helpful functions in booleanEvaluation.
 * - Test your code often!  Get it working correctly for the first couple test
 * cases instead of trying to solve all of them at once.
 */
char *evaluatePostfix(char *str)
{

  Stack *s = createStack();

  char *op1; /* holds 1st operand*/
  char *op2; /*holds 2nd operand*/ 
  boolean res=TRUE;
  int i = 0;

  int count = 0; /* counts T and F*/
  

  int tokenCount; /*# of Tokens*/
  char **arrTokens = tokenizeString(str, &tokenCount);

 /* op1 = (char *)malloc(sizeof(char) * count);
  op2 = (char *)malloc(sizeof(char) * count);*/
  /* Your variable Declarations: */

  /* Currently commented out to prevent a memory leak.  Uncomment to get the
   * tokens from str. */
  for (i = 0; i < tokenCount; i++)
  {
    /* PARSE THROUGH ARRTOKENS FOR T AND F and Push EM' */
    if (strequals(arrTokens[i], "T") || strequals(arrTokens[i], "F"))
    {
      /* count counts the number of T and F */
      count++;
      push(s, arrTokens[i]);

      
    }
  
    /* NOT START */

    if (strequals(arrTokens[i], "NOT") && tokenCount )
    {
     
     op1=pop(s);
     
       
        res = !stringToBoolean(op1);

    
    }
    /*NOT END */

    /*AND START*/
    else if (strequals(arrTokens[i], "AND") && tokenCount )
    {
      if((top(s)+1)==NULL ){
        res=stringToBoolean("E");
      }else{

         op2 = pop(s);
      op1 = pop(s);
       res=(stringToBoolean(op1) && stringToBoolean(op2));
      }
     

     
      
    }
    /*AND END*/

    /*NAND START*/

    else if (strequals(arrTokens[i], "NAND") && tokenCount )
    {
      op2 = pop(s);
      op1 = pop(s);

      
        res =!( stringToBoolean(op1) && stringToBoolean(op2));
      
    }
    /*END NAND*/

    /*START OR*/
  else  if (strequals(arrTokens[i], "OR") && tokenCount )
    {

        if ((top(s) + 1) == NULL)
        {
       res = stringToBoolean("E");
        }
        else
        {

       op2 = pop(s);
       op1 = pop(s);
   res=( stringToBoolean(op1) || stringToBoolean(op2));
        }
  

   
      
    }
    /*END OR*/

    /*START XOR*/
  else  if (strequals(arrTokens[i], "XOR") && tokenCount )
    {
      op2=pop(s);
      op1=pop(s);
        res = (stringToBoolean(op1) !=stringToBoolean(op2)) ;
      
    }
    /*END XOR*/

    /*START NOR*/
   else if (strequals(arrTokens[i], "NOR") && tokenCount )
    {
      op2 = pop(s);
      op1 = pop(s);

        res =!( stringToBoolean(op1) || stringToBoolean(op2));
      
    }
    /*END NOR*/

    /*START COND*/
  else  if (strequals(arrTokens[i], "COND") && tokenCount )
    {
      op2 = pop(s);
      op1 = pop(s);

      res=(!stringToBoolean(op1) || stringToBoolean(op2));

    }
    /*END COND*/

    /*BICOND START */
  else  if (strequals(arrTokens[i], "BICOND") && tokenCount )
    {
      op2 = pop(s);
      op1 = pop(s);

      
        res = (stringToBoolean(op1)==stringToBoolean(op2));
      
    }
 
  
   
    }
 
 if((top(s))!=NULL){

    res=stringToBoolean("E");
  }

  
 
  freeStack(s);
  for (i = 0; i < tokenCount; i++)
  {
    free(arrTokens[i]);
  }
  free(arrTokens);

 
  
  return booleanToString(res);
  /* Replace this with your actual solution to return */
}


/* TODO
 * postfixToInfix
 * input: a postfix expression (calls tokenizeString to get the tokens from the
 * string) output: the equivalent infix expression
 *
 * Uses a stack to convert str to its equivalent expression in infix.
 * You can assume that the postfix expression is valid
 *
 * Hints:
 * - DO NOT free the parameter str.  It is freed by the calling function.
 * - Be sure to use the helpful functions in booleanEvaluation.
 * - Test your code often!  Get it working correctly for the first couple test
 * cases instead of trying to solve all of them at once.
 */


char *postfixToInfix(char *str)
{
  Stack *s = createStack();
  Stack *s2 = createStack();


  int i = 0;


  int tokenCount; /*# of Tokens*/
  char **arrTokens = tokenizeString(str, &tokenCount);
  char *cur_op;
  char *str1;
  char *str2;
  char *str3;
  char *str4;
  char *op1;
  char *xOp; /*holds operator*/
      boolean loop_entered;

  str1 = (char *)malloc(sizeof(char) * 1024);
  str3 = (char *)malloc(sizeof(char) * 1024);
  str4 = (char *)malloc(sizeof(char) * 1024);

  memset(str1, '\0', 1024);
  memset(str3, '\0', 1024);
  memset(str4, '\0', 1024);

  for (i = 0; i < tokenCount; ++i)
  {
    if (strequals(arrTokens[i], "T") || strequals(arrTokens[i], "F"))
    {
      /* count counts the number of T and F */

      push(s, arrTokens[i]);
    }
    else
    {
      push(s2, arrTokens[i]);
    }
  }
    xOp = pop(s2);

  if (strequals(xOp, "NOT"))
  {

    sprintf(str1, "( %s %s )",xOp, "%s");
    printf("273  str1 %s \n",str1);
  }
  else
  {
    sprintf(str1, "( %s %s %s )", "%s", xOp, pop(s));
    printf("278 str1 %s \n", str1);
  }

   loop_entered = FALSE;

  while (!isEmpty(s2))
  {
    loop_entered = TRUE;
    xOp = pop(s2);

    if (strequals(xOp, "NOT"))
    {
      sprintf(str4, str1, "( NOT %s )");
      printf("291 str1 %s \n", str1);
    }

    else if (strequals(xOp,"AND"))
    {
      str2 = pop(s);
      printf("296 pop(s) str2 %s \n", str1);
      sprintf(str3, "( %s %s %s )","%s", xOp,str2 ); 
      sprintf(str4, str1, str3);
      strcpy(str1, str4);
      printf("300 str1 %s \n", str1);
    }
    else if (strequals(xOp, "OR"))
    {
      str2 = pop(s);
      printf("296 pop(s) str2 %s \n", str1);
      sprintf(str3, "( %s %s %s )", str2,xOp, "%s" );
      sprintf(str4, str1, str3);
      strcpy(str1, str4);
      printf("300 str1 %s \n", str1);

    }
    
    else
    {
      str2 = pop(s);
      sprintf(str3, "( %s %s %s )", "%s", xOp, str2);
      sprintf(str4, str1, str3);
      strcpy(str1, str4);
      printf("308 str1 %s \n", str1);
    }

  }

  if (loop_entered) {
    sprintf(str1, str4, pop(s));
  printf("315 str1 %s \n", str1);
  }
  else {
    sprintf(str1, str1, pop(s));
    printf("319 str1 %s \n", str1);
  }
    

  freeStackElements(s);
  freeStackElements(s2);
  freeStack(s2);

  free(str3);
  free(str4);
  freeStack(s);

  for (i = 0; i < tokenCount; i++)
  {
    free(arrTokens[i]);
  }
  free(arrTokens);
  return str1;
}

/* You may want to create some helper functions down here! */


/* You may want to create some helper functions down here! */
