class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            // Move left index to the next valid character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right index to the previous valid character
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters in a case-insensitive manner
            if (tolower(s[left]) != tolower(s[right])) {
                return false;  // Not a palindrome
            }

            // Move towards the center
            left++;
            right--;
        }

        return true;  // Is a palindrome
    }
};