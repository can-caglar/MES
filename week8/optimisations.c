/*
***************************************************************************
Week 9 Exercise - Optimizations

Choose a small algorithm to implement in different ways. 
Describe when/why you might use each. You can choose any small algorithm. 
Consider the algorithms with respect to speed, RAM, and code space

Algorithm chosen:  Find the first 100 prime numbers
*************************************************************************** 
*/

#include <stdio.h>
#include <stdint.h>

typedef uint8_t(*isPrimeFn)(uint8_t);
void findPrimesUpTo100(isPrimeFn primeFuncUnderTest);

// *************************************************************************** 
// Technique 1: calculate it on the fly
// Speed:       Slow
// RAM usage:   Low
// Code space:  Low
// *************************************************************************** 
uint8_t isPrime_method1(uint8_t number)
{
    // 0 and 1 are not prime
    if (number < 2)
    {
        return 0;
    }
    // Check if it's even
    if ((number != 2) && (number % 2 == 0))
    {
        return 0;
    }
    // half the divisor as no number larger than half would
    // divide evenly anyway
    uint8_t divisor = number >> 1;
    while (divisor > 1)
    {
        if (number % divisor == 0)
        {
            return 0;
        }
        divisor--;
    }
    return 1;  // must be prime
}

// *************************************************************************** 
// Technique 2, lookup table with search 
// (binary search might be faster but it's not implemented here)
// Speed:       Faster
// RAM usage:   Medium
// Code space:  Medium
// *************************************************************************** 
#define PRIMES_0_100_COUNT 25

static const uint8_t gPrimes[PRIMES_0_100_COUNT] = 
{
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
};

uint8_t isPrime_method2(uint8_t num)
{
    uint8_t isPrime = 0;
    for (int i = 0; i < PRIMES_0_100_COUNT; i++)
    {
        if (gPrimes[i] == num)
        {
            isPrime = 1;
            break;
        }
    }
    return isPrime;
}

// *************************************************************************** 
// Technique 3, "giant" lookup table
// Speed:       Fastest
// RAM usage:   High
// Code space:  High
// *************************************************************************** 
static const uint8_t gPrimeMap[101] = 
{
//  0  1  2  3  4  5  6  7  8  9  10
    0, 0, 1, 1, 0, 1, 0, 1, 0, 0,    // 0
    0, 1, 0, 1, 0, 0, 0, 1, 0, 1,    // 1
    0, 0, 0, 1, 0, 0, 0, 0, 0, 1,    // 2
    0, 1, 0, 0, 0, 0, 0, 1, 0, 0,    // 3
    0, 1, 0, 1, 0, 0, 0, 1, 0, 0,    // 4
    0, 0, 0, 1, 0, 0, 0, 0, 0, 1,    // 5
    0, 1, 0, 0, 0, 0, 0, 1, 0, 0,    // 6
    0, 1, 0, 1, 0, 0, 0, 0, 0, 1,    // 7
    0, 0, 0, 1, 0, 0, 0, 0, 0, 1,    // 8
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0  // 9
};
uint8_t isPrime_method3(uint8_t num)
{
    return gPrimeMap[num];
}
// *************************************************************************** 

int main(void)
{
    findPrimesUpTo100(isPrime_method1);
    findPrimesUpTo100(isPrime_method2);
    findPrimesUpTo100(isPrime_method3);
    return 0;
}

void findPrimesUpTo100(isPrimeFn primeFuncUnderTest)
{
    printf("Prime numbers: ");
    for (int i = 0; i <= 100; i++)
    {
        if (primeFuncUnderTest(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}
