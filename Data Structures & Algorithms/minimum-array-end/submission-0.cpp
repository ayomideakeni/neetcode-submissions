class Solution {
public:
    long long minEnd(int n, int x) {
        // We need to increment the sequence n - 1 times from the starting point x
        long long remaining_increments = n - 1;
        long long result = x;
        
        // Iterate through each bit position up to 62 bits to prevent integer overflow
        int shift_idx = 0;
        while (remaining_increments > 0) {
            // If the current bit in x is 0, we can fill it with a bit from remaining_increments
            if (((result >> shift_idx) & 1) == 0) {
                // Take the lowest bit of remaining_increments and put it at shift_idx
                result |= (remaining_increments & 1) << shift_idx;
                // Move to the next bit of remaining_increments
                remaining_increments >>= 1;
            }
            shift_idx++;
        }
        
        return result;
    }
};
