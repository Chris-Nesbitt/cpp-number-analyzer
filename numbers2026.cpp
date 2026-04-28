/*
Chris Nesbitt
2026-01-19
A program that reads in an unsigned long long and determines many different numerical qualities it does/doesn't have. 
See version details below for more info.

Version 1.1.0 - implemented isEven and isPerfectSquare
Version 1.1.1 - added isTriangleNumber, isFactorial, findDigits and formatNumber
Version 1.1.2 - reworked all functions to take unsigned long long as the parameter (instead of unsigned long)
Version 1.1.3 - added isPrime, isPowOfTwo and isFibonacci
				fixed bugs in isTriangleNumber when input number was too large 
				(tested with 18446744073709551557 --> largest prime number that can be stored in an unsigned long long)
Version 1.1.4 - added input validation for the number input --> created isNegative, isTooLong, isNotNumber and userInput functions
				added toBinary and isPalindrome
Version 1.1.5 - fixed overflow issues with isFibonacci, isPowOfTwo, isFactorial and isDeficientPerfectAbundant --> tested with the max value
Version 1.1.6 - added getEvenParityBit and printInfo
				fixed bugs in isDeficientPerfectAbundant
Version 1.1.7 - tested and fixed bugs with 0 and 1 (they have strange properties)
*/


int main() {
	printInfo();
}