#include <iostream>
#include <cstdlib>
#include <ctime>

long long rfactorial(int n){
  if (n == 1){
    return 1;
  } else {
    return n * rfactorial(n-1);
  }
}

long long factorialHelper(int n, int result){
  if (n == 1) {
    return result;
  }
  else {
    return factorialHelper(n-1, n * result);
  }
}

long long factorial(int n){
  return factorialHelper(n, 1);
}

/**
 * @brief Iterative Fibonacci Calculator
 * 
 * Adapted from http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
 * Originally created by: joseph.arul83@gmail.com
 * 
 * @param n user defined input for which fibonacci number they would like displayed
 * @return n'th fibonacci number
 */
long long itFibonacci(unsigned int n){
  int first =0;
  int second=1;
  int counter=2;
  while(counter < n){
    int temp=second;
    second=first+second;
    first=temp;
    ++counter;
  }

  if(n==0){
    return 0;
  }
  else{
    return first+second;
  }
}

/**
 * @brief Iterative Fibonacci Calculator
 * 
 * Adapted from http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
 * Originally created by: joseph.arul83@gmail.com
 * 
 * @param n user defined input for which fibonacci number they would like displayed
 * @return n'th fibonacci number
 */
long long recFibonacci(unsigned int n){
  if(n==0){
    return 0;
  }
  else if(n==1){
    return 1;
  }
  return recFibonacci(n-1) + recFibonacci(n-2);
 }

int main(){
  unsigned int userInput = 0;
  std::cout << "Enter a positive number:";
  std::cin >> userInput;
  std::cout << userInput << " was entered." << std::endl;

  clock_t itFibonacciStart = clock();
  std::cout << userInput << "th Fibonacci number: " << itFibonacci(userInput) << std::endl;
  clock_t itFibonacciEnd = clock();
  clock_t itFibonacciResult = itFibonacciEnd - itFibonacciStart;
  std::cout << "Iterative Fibonacci took " << itFibonacciResult << " clock cycles or " << ((float)itFibonacciResult)/CLOCKS_PER_SEC << " seconds" << std::endl;

  clock_t recFibonacciStart = clock();
  std::cout << userInput << "th Fibonacci number: " << recFibonacci(userInput) << std::endl;
  clock_t recFibonacciEnd = clock();
  clock_t recFibonacciResult = recFibonacciEnd - recFibonacciStart;
  std::cout << "Recursive Fibonacci took " << recFibonacciResult << " clock cycles or " << ((float)recFibonacciResult)/CLOCKS_PER_SEC << " seconds" << std::endl;


  long long iterativeResult = 1;
  clock_t itfactTimeStart = clock();
  for(unsigned int i = userInput; i > 0; i--){
    iterativeResult = iterativeResult * i;
  }
  clock_t itfactTimeEnd = clock();
  clock_t itfactTimeResult = itfactTimeEnd - itfactTimeStart;
  std::cout << "Iterative factorial took " << itfactTimeResult << " cycles or "<< ((float)itfactTimeResult)/CLOCKS_PER_SEC << " seconds" << std::endl;

  long long rfactResult = 0;
  clock_t rfactTime = clock(); 
  //std::cout << "Calculating..." << std::endl;
  rfactResult = rfactorial(userInput);
  rfactTime = clock() - rfactTime;
  std::cout << "Non-tail recursion factorial took " << rfactTime << " cycles or "<< ((float)rfactTime)/CLOCKS_PER_SEC << " seconds" << std::endl;

  long long factResult = 0;
  clock_t factTime = clock();
  //std::cout << "Calculating..." << std::endl;
  factResult = factorial(userInput);
  factTime = clock() - factTime;
  std::cout << "Tail recursion factorial took " << factTime << " cycles or "<< ((float)factTime)/CLOCKS_PER_SEC << " seconds" << std::endl;
}
