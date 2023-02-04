/*
// a SWITCH CASE FOR T F and OPERATORS


unary operator op1 NOT !op1
binary operator op1 op2 AND op1 && op2
binary operator op1 op2 NAND !(op1 && op2)
binary operator op1 op2 OR op1 || op2
binary operator op1 op2 NOR !(op1 || op2)
binary operator op1 op2 XOR op1 ! = op2
binary operator op1 op2 COND !op1 || op2
binary operator op1 op2 BICOND op1 == op2







*/
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
void printName() {
  /* TODO : Fill in your name */
  printf("This solution was completed by:\n");
  printf("<Ryan Reddoch>\n");
}
int i = 0;

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

char *evaluatePostfix(char *str) {
  /* Your variable Declarations: */
  char op1;
  char op2;
  char boolean;
  Stack *ps;
  int tokenCount;

  char **arrTokens = tokenizeString(str, &tokenCount);
  for (i = 0; i < tokenCount; i++) {
    if (str[i] == 'T' || str[i] == 'F') {
      push(ps, &str[i]);

    } else {
      boolean = str[i];
    }
  }

  if (boolean == 'AND') {

    and(op1, op2, boolean);
  }

  /* switch(operator){

         case 'AND' :

            break;
         case 'NOT' :
           return !op1;
         case 'NAND' :
            return !(op1 && op2);
            break;
         case 'OR' :
            return op1 || op2;
            break;
         case 'XOR':
            return op1 ! = op2;
            break;
         case 'NOR':
             return !(op1 || op2);
             break;
         case 'COND':
             return !op1 || op2;
            break;
         case "BICOND":
             return op1 == op2;
         default:
         return booleanToString;
      }

   }



 */

  // Currently commented out to   prevent a memory leak.
  // Uncomment to get the token from str.

  // char *postfixToInfix( char *str );

  /* Your code: */

  return booleanToString(
      ERROR); /* Replace this with your actual solution to return */
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
char *postfixToInfix(char *str) {
  /* Your variable Declarations: */
  int tokenCount;

  //  = tokenizeString(str, &tokenCount); /* Currently commented out to prevenb

  /* Your code: */
  // free()

  return booleanToString(
      ERROR); /* Replace this with your actual solution to return */
}

/* You may want to create some helper functions down here! */
///////////////MY LOGIC FUNCTIONS//////////////////////////
/////////////////////////////////////////

/* void not(){
if ( !op1){
return !op1


}

}

} */

int and (op1, op2, op) {
  Stack *ps;
  pop(ps);
  op1 = top;
  pop(ps);
  op2 = top;
  if (op1 && op2) {

    return T;
  }
}

/////////NAND ///////////////
/* void nand()
if (FF,TF,FT){
 !(op1 && op2)
return True;

} else return False


*/
///////////OR/////////////
/*
int or(){
if {TT || TF || FT}{
 op1 || op2
return True;



} else return False;

}
*/
////////XOR////////////////
/*int xor(){
if (TF || FT){
op1 ! = op2
return True;


}else return False;

}
*/
///////////////NOR/////////////
/*
int nor(){
!(op1 || op2)
if (FF){

return True;

}else return False;

}

*/

////////////CONDITIONAL////////////
/*
int cond(){
!op1 || op2
if (TT || FT || FF){
return True;



}else return False




}


*/

//////////BICONDITIONAL//////////////
/*
int bicon(){
op1 == op2
if (TT || FF){
return True;

}

}

*/
