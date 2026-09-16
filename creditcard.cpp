#include <iostream>
#include <string>

// Function prototypes
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long number;
    std::cout << "Enter a credit card number as a long integer: ";
    std::cin >> number;

    if (isValid(number)) {
        std::cout << number << " is valid" << std::endl;
    } else {
        std::cout << number << " is invalid" << std::endl;
    }

    return 0;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int totalDigits = getSize(number);
    
    // Check length requirement (13 to 16 digits)
    if (totalDigits < 13 || totalDigits > 16) {
        return false;
    }
    
    // Check valid prefix (4 for Visa, 5 for MasterCard, 37 for Amex, 6 for Discover)
    if (!prefixMatched(number, 4) && 
        !prefixMatched(number, 5) && 
        !prefixMatched(number, 37) && 
        !prefixMatched(number, 6)) {
        return false;
    }

    // Perform Luhn check (Step 4 & Step 5)
    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    return (totalSum % 10 == 0);
}

// Step 2: Double every second digit from right to left and sum the resulting digits
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    number /= 10; // Start at the second digit from the right (even place)

    while (number > 0) {
        int digit = (number % 10) * 2;
        sum += getDigit(digit);
        number /= 100; // Move to the next even-place digit
    }

    return sum;
}

// Step 1: Return number if single-digit; otherwise, return the sum of its two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    return (number / 10) + (number % 10);
}

// Step 3: Return sum of odd place digits from right to left
int sumOfOddPlace(long long number) {
    int sum = 0;

    while (number > 0) {
        sum += number % 10;
        number /= 100; // Move to the next odd-place digit
    }

    return sum;
}

// Return true if the digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    int prefixSize = getSize(d);
    return getPrefix(number, prefixSize) == d;
}

// Return the number of digits in d
int getSize(long long d) {
    int count = 0;
    if (d == 0) return 1;

    while (d > 0) {
        count++;
        d /= 10;
    }
    return count;
}

// Return the first k number of digits from number. 
// If total digits < k, return the number itself.
long long getPrefix(long long number, int k) {
    int totalSize = getSize(number);

    if (totalSize < k) {
        return number;
    }

    for (int i = 0; i < totalSize - k; i++) {
        number /= 10;
    }

    return number;
}