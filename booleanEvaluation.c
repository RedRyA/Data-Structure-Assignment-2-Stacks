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

    char *op1;   // holds 1st operand
    char *op2;   // holds 2nd operand
    char *x[10]; // holds operator;
    char *testArray[] = {"NOT", "AND", "NAND", "OR",
                         "NOR", "XOR", "COND", "BICOND"};

    int i = 0;
    int j = 0;
    int count = 0; /* counts T and F*/
    boolean res;
    boolean bool;
    boolean bool2;
    int tokenCount; /*# of Tokens*/
    char **arrTokens = tokenizeString(str, &tokenCount);

    op1 = (char *)malloc(sizeof(char) * count);
    op2 = (char *)malloc(sizeof(char) * count);
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

        if (strequals(arrTokens[i], "NOT") && tokenCount <= 2)
        {
            op1 = pop(s);
            if (strequals(op1, "T"))
            {

                op1 = "F";
                res = stringToBoolean(op1);
            }

            else if (strequals(op1, "F"))
            {
                op1 = "T";
                res = stringToBoolean(op1);
            }
        }
        /*NOT END */

        /*AND START*/
        if (strequals(arrTokens[i], "AND") && tokenCount <= 3)
        {
            op2 = pop(s);
            op1 = pop(s);

            if (strequals(op1, "T") && strequals(op2, "T"))
            {
                res = stringToBoolean(op1);
            }
            else
            {
                res = stringToBoolean("F");
            }
        }
        /*AND END*/

        /*NAND START*/

        if (strequals(arrTokens[i], "NAND") && tokenCount <= 3)
        {
            op2 = pop(s);
            op1 = pop(s);

            if (strequals(op1, "T") && strequals(op2, "T"))
            {
                res = stringToBoolean("F");
            }
            else
            {
                res = stringToBoolean("T");
            }
        }
        /*END NAND*/

        /*START OR*/
        if (strequals(arrTokens[i], "OR") && tokenCount <= 3)
        {
            op2 = pop(s);
            op1 = pop(s);

            if (strequals(op1, "T") || strequals(op2, "T"))
            {
                res = stringToBoolean("T");
            }
            else
            {
                res = stringToBoolean("F");
            }
        }
        /*END OR*/

        /*START XOR*/
        if (strequals(arrTokens[i], "XOR") && tokenCount <= 3)
        {
            op2 = pop(s);
            op1 = pop(s);

            if (strequals(op1, "T") && strequals(op2, "F") ||
                strequals(op1, "F") && strequals(op2, "T"))
            {
                res = stringToBoolean("T");
            }
            else
            {
                res = stringToBoolean("F");
            }
        }
        /*END XOR*/

        /*START NOR*/
        if (strequals(arrTokens[i], "NOR") && tokenCount <= 3)
        {
            op2 = pop(s);
            op1 = pop(s);

            if (strequals(op1, "F") && strequals(op2, "F"))
            {
                res = stringToBoolean("T");
            }
            else
            {
                res = stringToBoolean("F");
            }
        }
        /*END NOR*/

        /*START COND*/
        if (strequals(arrTokens[i], "COND") && tokenCount <= 3)
        {
            op2 = pop(s);
            op1 = pop(s);

            if (strequals(op1, "T") && strequals(op2, "F"))
            {
                res = stringToBoolean("F");
            }
            else
            {
                res = stringToBoolean("T");
            }
        }
        /*END COND*/

        /*BICOND START */
        if (strequals(arrTokens[i], "BICOND") && tokenCount <= 3)
        {
            op2 = pop(s);
            op1 = pop(s);

            if (strequals(op1, "T") && strequals(op2, "T") ||
                strequals(op1, "F") && strequals(op2, "F"))
            {
                res = stringToBoolean("T");
            }
            else
            {
                res = stringToBoolean("F");
            }
        }
        /*BICOND END*/

        /*MULTI BOOLOEAN START*/
        if (tokenCount > 3)
        {
           /*MULTI NOT START*/
            if (strequals(arrTokens[i], "NOT"))
            {
                op2 = pop(s);
                bool = stringToBoolean(op2);
                bool = !(op2);
                push(s, booleanToString(bool));
            }
            /*MULTI NOT END*/

            /*MULTI AND START*/
            if (strequals(arrTokens[i], "AND"))
            {
                op2 = pop(s);
                op1 = pop(s);
              if(strequals(op1,op2))
              {
                push(s,"T");

              }
              else
              {
                push(s,"F");
              }
            }
            /*MULT AND END*/

            /*MULTI NAND START*/
            if (strequals(arrTokens[i], "NAND"))
            {
                op2=pop(s);
                op1=pop(s);
                if(strequals(op1,"T") && strequals(op2,"T"))
                {
                    push(s,"F");
                } 
                else{

                    push(s,"T");
                }
            }
            /*MULTI NAND END*/

            /*MULTI OR START*/
            if (strequals(arrTokens[i], "OR"))
            {
                op2=pop(s);
                op1=pop(s);
                if (strequals(op1, "T") ||strequals(op2, "T"))
                {
                    push(s,"T");

                }  else{

                    push(s,"F");
                }
            }
            /*MULTI OR END*/

            /*MULTI NOR START*/
            if (strequals(arrTokens[i], "NOR"))
            {
                op2=(pop,s);
                op1=(pop,s);

                if (strequals(op1, "F") && strequals(op2, "F"))
                {
                    push(s,"T");
                }
                else
                {
                    push(s,"F");
                }
            }
            /*MULTI NOR END*/

              /*MULTI XOR START*/
            if (strequals(arrTokens[i], "XOR"))
            {
                op2=pop(s);
                op1=pop(s);

                if (strequals(op1, "F") && strequals(op2, "F")||strequals(op1, "T") && strequals(op2, "T" ))
                {
                         



                }
            }
          
            /*MULTI XOR END*/

        }
       
    }
        return booleanToString(res);
        /* Replace this with your actual solution to return */
    }

    //}

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

    //////////////////////////////////
    ///////////////////////////////

    char *postfixToInfix(char *str)
    {
        printf("p2I \n");
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
        //   char** arrTokens = tokenizeString( str, &tokenCount );  /* Currently
        //   commented out to prevent a memory leak.  Uncomment to get the tokens from
        //   str. */

        /* Your code: */

        // return booleanToString(
        //     ERROR); /* Replace this with your actual solution to return */
    }

    /* You may want to create some helper functions down here! */
