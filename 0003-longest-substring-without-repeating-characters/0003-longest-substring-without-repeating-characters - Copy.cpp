#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charMap;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.size(); end++) {
            // If the character is already in the map, move the start pointer
            // after the last occurrence of the current character.
            if (charMap.find(s[end]) != charMap.end()) {
                start = std::max(start, charMap[s[end]] + 1);
            }
            // Update the last occurrence of the character
            charMap[s[end]] = end;
            // Update the maximum length
            maxLength = std::max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
