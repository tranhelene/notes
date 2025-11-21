/*
Debug the ISR function below
*/

float ISR_function (float value) {
    value *= 3.14f;
    printf("Value inside ISR: %f\n", value);
    return value;
}



/*
You are given nums, num_bits, and offset
Write a function that reverses the order of {num_bits} bits in nums starting at the offset from the right

Example:
    nums = 1100 0101 0010 1000
    num_bits = 5
    offset = 3

    nums = 1100 0101 0010 1000
                     ^^^^ ^
    result = 1100 0101 1010 0000
                       ^^^^ ^
*/

uint32_t reverse_bits(uint32_t nums, uint32_t num_bits, uint32_t offset) {
    
}