#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COLUMNS 6
int numbersInRow = 0;

void printNumber(int num) {
  printf("%10d ", num);
  numbersInRow++; // increases the count
  if(numbersInRow == COLUMNS) {
    printf("\n");
    numbersInRow = 0;
  }
}

void printSieves(int n) {
  char *possiblePrimePt = malloc(n-2 * sizeof(char)); // declares a "boolean" array in heap assuming all numbers to be prime
  for(int i = 2; i < n; i++) {
    possiblePrimePt[i-2] = 1;
  }
  for(int i = 2; i <= sqrt(n); i++) { // loops through all possible primes
    if(possiblePrimePt[i-2]) { // checks if current number is prime
      for(int j = i*i; j <= n; j += i) { // marks all multiples of i as not primes
        possiblePrimePt[j-2] = 0;
      }
    }
  }
  for(int i = 2; i <= n; i++) { // goes through all possible primes
    if(possiblePrimePt[i-2]) { // prints number if it's prime
      printNumber(i);
    }
  }
  free(possiblePrimePt); // fress up the memory used by possiblePrimePt
  printf("\n");
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    printSieves(atoi(argv[1])); // atoi converts the argument to an int
  else
    printf("Please state an interger number.\n");
  return 0;
}
