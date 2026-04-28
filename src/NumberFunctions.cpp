#include <iostream>
#include <cmath>
#include <bitset>
#include <sstream>  // for stringstreams
#include <string>   // for strings

using namespace std;

using number = unsigned long long;

bool isEven(number num) {
	return num % 2 == 0;
}

bool isTriangleNumber(number num) {
	number triangleSum = 1;
	number counter = 2;
	constexpr number BIGGEST_TRIANGLE{ 18446744065119617000 }; //the largest triangle number that can be stored in an unsigned long long

	if (num > BIGGEST_TRIANGLE) {
		return false;
	}

	while (triangleSum < num && triangleSum < BIGGEST_TRIANGLE) {
		triangleSum += counter;
		counter++;
	}
	return triangleSum == num;
}

bool isPrime(number num) {
	if (num == 0 || num == 1) {
		return false;
	}

	number maxFactor = static_cast<unsigned long long>(ceil(sqrt(num)));
	for (number i = 2; i <= maxFactor; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

bool isPerfectSquare(number num) {
	number result = static_cast<unsigned long long>(sqrt(num));
	return result * result == num;
}

bool isPowOfTwo(number num) {
	constexpr number BIGGEST_POWOFTWO{ 9223372036854775808 }; //the largest power of two that can be stored in an unsigned long long
	number product = 1;

	while (product < num && product < BIGGEST_POWOFTWO) {
		product *= 2;
	}
	return product == num;
}

bool isFactorial(number num) {
	constexpr number BIGGEST_FACTORIAL{ 2432902008176640000 }; //the largest factorial that can be stored in an unsigned long long
	number factorialProduct = 1;
	number counter = 1;
	while (factorialProduct < num && factorialProduct < BIGGEST_FACTORIAL) {
		factorialProduct *= counter;
		counter++;
	}
	return factorialProduct == num;
}

bool isFibonacci(number num) {
	constexpr number BIGGEST_FIBONACCI{ 12200160415121876738 }; //the largest fibonacci number that can be stored in an unsigned long long
	number a = 0;
	number b = 1;
	number temp;
	while (a < num && a < BIGGEST_FIBONACCI) {
		temp = a + b;
		a = b;
		b = temp;
	}

	return num == a;
}

int isDeficientPerfectAbundant(number num, bool prime) {
	number halfWay = static_cast<unsigned long long>(ceil(sqrt(num)));
	number divPair2;
	number sumOfDivs = 1;

	if (prime) {
		return 1; //deficient
	}

	if (num == 0) {
		return 4;
	}

	if (num == 1) {
		return 1;
	}

	for (number divPair1 = 2; divPair1 < halfWay; divPair1++) {
		if (num % divPair1 == 0) {
			divPair2 = num / divPair1;
			if (sumOfDivs > num - divPair1) { //really checking if sumOfDivs + divPair1 > num --> but that can cause overflow
				return 3;
			}
			sumOfDivs += divPair1;

			//check again for the second multiple in the pair
			if (divPair2 != divPair1) { // making sure it isnt doubling for a perfect square
				if (sumOfDivs > num - divPair2) { //really checking if sumOfDivs + divPair2 > num --> but that can cause overflow
					return 3;
				}
				sumOfDivs += divPair2;
			}
		}
	}

	if (sumOfDivs < num) {
		return 1; //deficient
	}
	else if (sumOfDivs == num) {
		return 2; //perfect
	}
	else {
		return 3; //abundant
	}
}

bool findEvenParityBit(string num) {
	unsigned int binaryCounter = 0;
	for (size_t i = 0; i < num.size(); i++) {
		if (num[i] == '1') {
			binaryCounter++;
		}
	}

	return binaryCounter % 2 == 1;
}

unsigned int findDigits(number num) {
	unsigned int digits = 1;
	constexpr unsigned int base = 10; //what base im calculating digits for 
	//... will always be 10, but theoretically could be changed
	while (num >= base) {
		num /= base;
		digits++;
	}
	return digits;
}

bool isPalindrome(number num) {
	string str = to_string(num);
	auto backward = str;
	reverse(backward.begin(), backward.end());
	return str == backward;
}

string toBinary(number num) {
	return bitset<64>(num).to_string();
}

string formatNumber(number num) {
	istringstream is(to_string(num));
	string formattedNum;
	char ch;

	const char digitsPerPeriod = 3; //avoiding magic numbers: how many numbers between each ','

	unsigned int digits = findDigits(num);
	unsigned int fPeriodCount = digits % 3 == 0 ? 3 : digits % 3; //number of digits in the 1st period
	unsigned int periodsAfterFirst = (digits - fPeriodCount) / 3; //how many times to repeat , %d%d%d (how many periods)

	//the first period (anywhere from 1-3 digits)
	for (unsigned long i = 0; i < fPeriodCount; i++) {
		is.get(ch);
		formattedNum += ch;
	}

	//all remaining periods (they all have the format ',%d%d%d')
	for (unsigned long i = 0; i < periodsAfterFirst; i++) {
		formattedNum += ',';
		for (unsigned long j = 0; j < digitsPerPeriod; j++) {
			is.get(ch);
			formattedNum += ch;
		}
	}

	return formattedNum;
}

/* NO LONGER NEEDED --> USED FOR DEBUGGING AND EARLY TESTING
string boolToString(bool a) {

	if (a) {
		return "true";
	}
	return "false";
}
*/

bool isNegative(string num) {
	if (num[0] == '-') {
		cout << "Error: you entered a negative number." << endl;
		cout << "---> the valid range is [0..." << formatNumber(numeric_limits<unsigned long long>::max()) << "]" << endl;
		return true;
	}
	return false;
}

bool isNotNumber(string num) {
	for (size_t i = 0; i < num.size(); i++) {
		if (!isdigit(num[i])) {
			cout << "Error: input is non - numeric." << endl;
			return true;
		}
	}
	return false;
}

bool isTooLong(string num) {
	if (num.size() > to_string(numeric_limits<unsigned long long>::max()).size()) {
		cout << "Error: input number is too large" << endl << "--> the valid range is [0..." << formatNumber(numeric_limits<unsigned long long>::max()) << "]" << endl;;
		return true;
	}

	else if (num.size() < to_string(numeric_limits<unsigned long long>::max()).size()) {
		return false;
	}

	else if (num.size() == to_string(numeric_limits<unsigned long long>::max()).size()) {
		if (num > to_string(numeric_limits<unsigned long long>::max())) {
			return true;
		}
		else {
			return false;
		}
	}
}

number userInput() {
	bool validInput = false;
	string num;
	number ullNum;

	cout << "Numbers v1.1.7, (c) - Chris Nesbitt" << endl;
	cout << "Enter a number in the range [0..." << formatNumber(numeric_limits<unsigned long long>::max()) << "]" << endl;

	while (!validInput) {
		cin >> num;
		validInput = true;
		if (isNegative(num)) {
			validInput = false;
		}
		else if (isNotNumber(num)) {
			validInput = false;
		}
		else if (isTooLong(num)) {
			validInput = false;
		}
	}

	ullNum = stoull(num);
	return ullNum;
}

void printInfo() {
	//all the variables needed for the other methods
	number num = userInput();
	bool prime = isPrime(num);
	string binary = toBinary(num);
	unsigned short dpa = isDeficientPerfectAbundant(num, prime);

	if (isEven(num)) {
		cout << "The number is even." << endl;
	}
	else {
		cout << "The number is odd." << endl;
	}

	if (isTriangleNumber(num)) {
		cout << "The number is triangular." << endl;
	}
	else {
		cout << "The number is not triangular." << endl;
	}

	if (prime) {
		cout << "The number is prime." << endl;
	}
	else {
		cout << "The number is composite." << endl;
	}

	if (isPerfectSquare(num)) {
		cout << "The number is square." << endl;
	}
	else {
		cout << "The number is not square." << endl;
	}

	if (isPowOfTwo(num)) {
		cout << "The number is a power of two." << endl;
	}
	else {
		cout << "The number is not a power of two." << endl;
	}

	if (isFactorial(num)) {
		cout << "The number is a factorial." << endl;
	}
	else {
		cout << "The number is not a factorial." << endl;
	}

	if (isFibonacci(num)) {
		cout << "The number is a fibonacci number." << endl;
	}
	else {
		cout << "The number is not a fibonacci number." << endl;
	}

	if (dpa == 1) {
		cout << "The number is deficient." << endl;
	}
	else if (dpa == 2) {
		cout << "The number is perfect." << endl;
	}
	else if (dpa == 3) {
		cout << "The number is abundant." << endl;
	}
	else {
		cout << "The number is outside the domain of perfect numbers." << endl;

	}

	cout << "Even parity bit: " << findEvenParityBit(binary) << endl;
	cout << "The number has " << findDigits(num) << " digits." << endl;

	if (isPalindrome(num)) {
		cout << "The number is palindromic" << endl;
	}
	else {
		cout << "The number is not palindromic." << endl;
	}

	cout << "In binary: " << binary << endl;
	cout << "The number thousand separated is " << formatNumber(num) << endl;

}