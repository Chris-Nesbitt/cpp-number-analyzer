#pragma once

#include <string>

using number = unsigned long long;

// number property checks
bool isEven(number num);
bool isTriangleNumber(number num);
bool isPrime(number num);
bool isPerfectSquare(number num);
bool isPowOfTwo(number num);
bool isFactorial(number num);
bool isFibonacci(number num);

// classification
int isDeficientPerfectAbundant(number num, bool prime);

// binary / parity
bool findEvenParityBit(std::string num);
std::string toBinary(number num);

// digit utilities
unsigned int findDigits(number num);
bool isPalindrome(number num);
std::string formatNumber(number num);

// input validation
bool isNegative(std::string num);
bool isNotNumber(std::string num);
bool isTooLong(std::string num);

// input / output
number userInput();
void printInfo();