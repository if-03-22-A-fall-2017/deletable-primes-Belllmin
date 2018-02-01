/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "deletable_primes.h"

unsigned long remove_digit(int index, unsigned long n)
{
  int divisor = pow(10, index + 1);
  int a = pow(10, index);
  double res = n / divisor;
  res *= a;
  res += n % a;
  return res;

  return 0;
 }
 int get_ways(unsigned long p)
 {
   int count = 0;
   int len = get_length(p);

   if(len == 1)
   {
     unsigned long digit = remove_digit(len, p);
     if(is_prime(digit)) ++count;
   }
   for(int i = 1; i < len; i++)
   {
     unsigned long digit = remove_digit(i, p);
     if(is_prime(digit)) ++count;
     if(len == 2)
     {
       unsigned long digit = remove_digit(i - 1, p);
       if(is_prime(digit)) ++count;
     }
   }
   //return ++count; // return count_of_primes++; ist nicht gegangen weil er zuerst returnt hat und dann um 1 erhöht
   return count;
 }
 int get_length(unsigned long number)
 {
   int count = 0;
   unsigned long temp = number;
   while(temp)
   {
     temp /= 10;
     count++;
   }
   return count;
 }
 bool is_prime(unsigned long number)
 {
   bool prim = true;
   for(int i = 2; i < number - 1; i++)
   {
     if(number % i != 0) continue;
     prim = false;
   }
   if(prim) return true;
   return false;
 }
