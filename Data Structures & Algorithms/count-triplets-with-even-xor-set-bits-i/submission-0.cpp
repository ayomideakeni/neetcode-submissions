#include <vector>

class Solution {
public:
    long long tripletCount(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c) {
        // Count of numbers with even/odd number of set bits in array 'a'
        long long evenA = 0, oddA = 0;
        for (int num : a) {
            if (__builtin_popcount(num) % 2 == 0) evenA++;
            else oddA++;
        }

        // Count of numbers with even/odd number of set bits in array 'b'
        long long evenB = 0, oddB = 0;
        for (int num : b) {
            if (__builtin_popcount(num) % 2 == 0) evenB++;
            else oddB++;
        }

        // Count of numbers with even/odd number of set bits in array 'c'
        long long evenC = 0, oddC = 0;
        for (int num : c) {
            if (__builtin_popcount(num) % 2 == 0) evenC++;
            else oddC++;
        }

        // Sum up the counts of the 4 valid combinations
        long long ans = 0;
        ans += evenA * evenB * evenC; // E, E, E
        ans += evenA * oddB * oddC;   // E, O, O
        ans += oddA * evenB * oddC;   // O, E, O
        ans += oddA * oddB * evenC;   // O, O, E

        return ans;
    }
};
