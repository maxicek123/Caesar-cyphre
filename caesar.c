// Caesar cyphre implementation
// @author Maximilian Mayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
   // shift is an int value, which decides direction of
   // movement of a text
   int shift;
   char s;
   char read;
   printf("choose your SHIFT!\npositive number is for right shift\nnegative number for left shift ");

   // Verifying if choosed shift is a number
   // if conidition is false, ending program
   // if condition is true, the program continues to read users input
   if (scanf("%d%c", &shift, &s) != 2 || s != '\n')
   {
      printf("required int\n");
      return 1;
   }
   else
   {
      printf("now write a text to be cyphred, using numbers and letters only\nother signes will be replaced with ! sign\n");

      // reading whole users input from console
      // (10 is ascii for ENTER key)
      while ((read = getc(stdin)) != 10)
      {
         // mathematical formurals for implementing caesars
         // cyphre for uppercase letters, lowercase numbers
         // and numbers
         char upperWords = ((read - 65 + shift) % 26) + 65;
         char lowerWords = ((read - 97 + shift) % 26) + 97;
         char numbers = ((read - 48 + shift) % 10) + 48;

         // verifying if input is uppercase
         if (read >= 'A' && read <= 'Z')
         {
            if ((shift < 0) && ((read - 65 + shift < 0)))
            {

               putc(upperWords + 26, stdout);
            }
            else
            {

               putc(upperWords, stdout);
            }
         }
         // verifying if input is lowercase
         else if (read >= 'a' && read <= 'z')
         {
            if ((shift < 0) && ((read - 97 + shift < 0)))
            {
               putc(lowerWords + 26, stdout);
            }

            else
            {
               putc(lowerWords, stdout);
            }
         }
         // verifying if input is a number
         else if (read >= '0' && read <= '9')
         {
            if ((shift < 0) && ((read - 48 + shift < 0)))
            {
               putc(numbers + 10, stdout);
            }
            else
            {

               putc(numbers, stdout);
            }
         }
         // if input includes a space, we keep the space between letters
         else if (read == ' ')
         {
            fprintf(stdout, " ");
         }
         // if input neither a letter or number, we replace it with !
         else
         {
            putc('!', stdout);
         }
      }
   }
   return 0;
}