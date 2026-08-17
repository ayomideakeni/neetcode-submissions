#include <string>
#include <algorithm>

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            // Adjust for 1-based indexing
            columnNumber--; 
            
            // Get the current character ('A' + remainder)
            char currentChar = 'A' + (columnNumber % 26);
            result += currentChar;
            
            // Move to the next place value
            columnNumber /= 26;
        }
        
        // The characters were added from right to left, so reverse the string
        reverse(result.begin(), result.end());
        
        return result;
    }
};