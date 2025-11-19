/*************************************************** bitwise operation notes ****************************************************************/

// & (AND) sets bit to 1 if both bits are 1
    0 & 0 = 0
    1 & 0 = 0
    1 & 1 = 1
    
// | (OR) sets bit to 1 if at least one bit is 1
    0 | 0 = 0
    1 | 0 = 1
    1 | 1 = 1

// ^ (XOR) sets bit to 1 if bits are different
    0 ^ 0 = 0
    1 ^ 0 = 1
    1 ^ 1 = 0
    
// ~ (NOT) inverts bits
    ~0 = 1
    ~1 = 0

// << (left shift) shifts bits to the left (multiplies by powers of 2)
    0010 << 2 = 1000
    = 2 * 2^2 = 8           //<- 2^x where x = shift amount

// >> (right shift) shifts bits to the right (divides by powers of 2)
    1000 >> 2 = 0010
    = 8 / 2^2 = 2           //<- 2^x where x = shift amount

// 2's complement (negative numbers)
    -n = ~n + 1
    -1 = ~(0001) + 1 = 1110 + 1 = 1111

/*-------------------- examples: ----------------------*/

// use & to check if a number is odd or even
int odd_or_even(int x) {
    (x & 1) ? printf("Odd") : printf("Even");
    return 0;
}
/* explanation:
all even numbers have last bit 0

{even number} & 1 = 0
8 & 1 = 1000 & 0001 = 0000
*/


// signed vs unsigned
int negative_num(int x) {
    printf("Signed Result %d \n", ~x);      // %d prints -1
    printf("Unsigned Result %u", ~x);       // %u prints 15 (1111)
    return 0;
}



/******************************************************* bit manipulation notes ************************************************************/

// set a bit
    num |= (1 << {bit});

// clear a bit
    num &= ~(1 << {bit});

// toggle a bit
    num ^= (1 << {bit});

// check if a bit is set
    if(num & (1 << {bit}))
    // OR
    return (num & (1 << {bit})) != 0;

// masking
    {value} & 0xF

/*-------------------- examples: ----------------------*/

// check 3rd bit is set
    return (num & (1 << 3)) != 0;

// toggle bit 7
    num ^= (1 << 7);

// clear bit 2
    reg &= ~0x04;



/********************************************************* leetcode practice (easy) ********************************************************/

/*-------------------- 136 Single Number ---------------------
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space. */
int singleNumber(int* nums, int numsSize) {
    int result = 0;

    for(int i = 0; i < numsSize; i++) {
        result = result ^ nums[i];
    }
    return result;
}
/* explanation:
nums = [4,1,2,1,2]

result = result ^ nums[i]
    = 0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2
    = 4 ^ (1 ^ 1) ^ (2 ^ 2)         <- pairs cancel out
    = 4 ^ 0 ^ 0
    = 4
*/



/*-------------------- 231 Power of 2 -----------------------
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x. */
bool isPowerOfTwo(int n) {
    if(n <= 0) {
        return false;
    }
    return (n & (n - 1)) == 0;
}
/* explanation:
n = 2^x = 1 (1), 2 (10), 4 (100), 8 (1000)      <- only first bit is 1
(n - 1) = 0 (0), 1 (01), 3 (011), 7 (0111)      <- bits flip for 2^x - 1

n & (n - 1) = 2 & 1 = 10 & 01 = 00              <- 2^x & (2^x - 1) = 0      
*/



/*------------------- 191 Number of 1 bits ------------------
Given a positive integer n, write a function that returns the number of set bits in its binary representation. */
int hammingWeight(int n) {
    int count = 0;

    while(n != 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}
/* explanation:
n = 6 (110)

n &= (n - 1)                            <- n & (n - 1) removes the rightmost 1 bit
    = 6 & 5 = 110 & 101 = 100 (4)
    = 4 & 3 = 100 & 011 = 000 (0)       <- count = 2, so there are 2 set bits
*/



/*-------------------- 461 Hamming Distance -----------------
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, return the Hamming distance between them. */
int hammingDistance(int x, int y) {
    int n = x ^ y;
    int count = 0;

    while(n != 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}
/* explanation:
x = 1 (001), y = 4 (100)

n = x ^ y = 001 ^ 100 = 101

n &= (n - 1)                    <- n & (n - 1) removes the rightmost 1 bit
    = 101 & 100 = 100
    = 100 & 011 = 000           <- count = 2, so distance is 2
*/



/*-------------------- 268 Missing Number -------------------
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array. */
int missingNumber(int* nums, int numsSize) {
    int n = 0;
    
    for(int i = 0; i < numsSize; i++) {
        n = n ^ nums[i] ^ (i + 1);
    }
    return n;
}
/* explanation:
nums = [3, 0, 1]

n = n ^ nums[i] ^ (i + 1)
    = 0 ^ 3 ^ 1 ^ 0 ^ 2 ^ 1 ^ 3
    = 0 ^ (3 ^ 3) ^ 0 ^ (1 ^ 1) ^ 2         <- pairs cancel out
    = 0 ^ 0 ^ 0 ^ 0 ^ 2
    = 2
*/



/*--------------------- 190 Reverse Bits ---------------------
Reverse bits of a given 32 bits signed integer. */
int reverseBits(int n) {
    int size = 32;
    int result = 0;

    for(int i = 0; i < size; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}
/* explanation:
result <<= 1                    <- shift result to left to make space for next bit
result |= (n & 1)               <- (n & 1) gets the rightmost bit, (result |=) appends that bit to result
n >>= 1                         <- shift n to right to process the next bit
*/



/*---------------------- 67 Add Binary -----------------------
Given two binary strings a and b, return their sum as a binary string. */
char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = (i > j ? i : j) + 3;
    char *s = malloc(k); 
    int c = 0;
    s[k-1] = '\0';

    while (i >= 0 || j >= 0 || c != 0) {
        int sum = c;

        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        } 
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        k--;
        s[k-1] = (sum % 2) + '0';
        c = sum / 2;
    }
    return s + k - 1;
}



/*-------------------- 338 Counting Bits ---------------------
Given an integer n, 
return an array ans of length n + 1 such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i. */
int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int* ans = malloc((*returnSize) * sizeof(int));

    for(int i = 0; i < *returnSize; i++) {
        int m = i;
        int count = 0;
        while(m != 0) {
            m &= (m - 1);
            count++;
        }
        ans[i] = count;
    }
    return ans;
}
/* explanation:
m &= (m - 1)                            <- m & (m - 1) removes the rightmost 1 bit
    = 6 & 5 = 110 & 101 = 100 (4)
    = 4 & 3 = 100 & 011 = 000 (0)       <- count = 2, so there are 2 set bits
*/



/*------------------ 389 Find the Difference ------------------
You are given two strings s and t.
String t is generated by random shuffling string s and then add one more letter at a random position.
Return the letter that was added to t. */
char findTheDifference(char* s, char* t) {
    char result = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        result ^= s[i];
    }

    for(int i = 0; t[i] != '\0'; i++) {
        result ^= t[i];
    }
    return result;
}
/* explanation:
s = "abcd", t = "abcde"

result = result ^ s[i] ^ t[i]
    = 0 ^ a ^ b ^ c ^ d ^ a ^ b ^ c ^ d ^ e
    = (a ^ a) ^ (b ^ b) ^ (c ^ c) ^ (d ^ d) ^ e         <- pairs cancel out
    = 0 ^ 0 ^ 0 ^ 0 ^ e
    = e
*/



/*--------- 201 Bitwise AND of Numbers Range (medium) ---------
Given two integers left and right that represent the range [left, right], 
return the bitwise AND of all numbers in this range, inclusive. */
int rangeBitwiseAnd(int left, int right) {
    int shift = 0;

    while(left != right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}
/* explanation:
left >>= 1; right >>= 1;            <- shift both numbers to right until they are equal to find common prefix
left << shift                       <- shift left to reinsert trailing zeros

left = 5 (0101), right = 7 (0111)

while (left != right)
    0101 != 0111
    0010 != 0011
    0001 == 0001                    <- common prefix is 1 (shift = 2)
return 0001 << 2 = 0100 (4)
*/



/********************************************* interrupt service routine (ISR) notes ********************************************************/

/*
general notes:
    - quick checklist:
        - fast
        - volatile variables
        - no blocking calls
        - no loops/ delays/ printf
        - interrupt flag cleared
        - using FromISR version of APIs
        - safe access to shared data
        - ISR not doing heavy work
    - ISR functions should be as short as possible
    - variables shared between ISR and main code need to be volatile (volatile int {variable})
    - disable interrupts around critical sections in main code
*/

/*-------------------- examples: ----------------------*/

// Bad ISR
int flag = 0;

void TIM2_IRQHandler(void) {
    for(int i = 0; i < 10000; i++) {}   // long delay loop

    printf("Interrupt!\n");            // BAD in ISR

    flag = 1;

    TIM2->SR &= ~1;                    // incorrectly clearing flag
}
// wrong: delay loop/ printf/ flag is not volatile/ clear flag using &= ~1

// fixed code
volatile int flag = 0;

void TIM2_IRQHandler(void) {
    flag = 1;                     // set flag quickly

    TIM2->SR = 0;                 // clear interrupt flag properly
}



// Using RTOS calls incorrectly
void UART_IRQHandler(void) {
    char c = UART->DR;

    xQueueSend(uartQueue, &c, portMAX_DELAY); // BAD: blocks inside ISR
    UART->INTCLR = 1;
}
// wrong: xQueueSend() blocks/ must use FromISR

// fixed code
void UART_IRQHandler(void) {
    char c = UART->DR;

    BaseType_t xHigher;
    xQueueSendFromISR(uartQueue, &c, &xHigher);

    portYIELD_FROM_ISR(xHigher);     // optional
    UART->INTCLR = 1;
}



// forgetting volatile and race condition
int count = 0;

void EXTI1_IRQHandler(void) {
    count++;
    EXTI->PR = 1;     // clear interrupt
}
// wrong: count not volatile/ 32 bit addition not atomic

// fixed code
volatile uint32_t count = 0;

void EXTI1_IRQHandler(void) {
    count++;            // short, fast
    EXTI->PR = 1;
}



// good ISR example
void ISR_Name(void) {
    // 1. Read data from hardware
    uint32_t status = PERIPH->STATUS;

    // 2. Clear interrupt flag immediately
    PERIPH->INTCLR = 1;

    // 3. Do minimal processing
    uint8_t event = status & 0x01; // example

    // 4. Notify main code or RTOS
    BaseType_t xHigher;
    xQueueSendFromISR(queue, &event, &xHigher);

    portYIELD_FROM_ISR(xHigher);
}



// general structure
void <InterruptName>_IRQHandler(void) {

    // Step 1: Read interrupt status (optional)
    uint32_t status = PERIPH->STATUS;

    // Step 2: Clear interrupt flag
    PERIPH->INTCLR = 1;

    // Step 3: Minimal processing
    dataReady = 1;

    // Step 4: Exit (return automatically)
}
