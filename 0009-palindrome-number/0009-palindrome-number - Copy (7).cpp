class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes and numbers ending with 0 are not palindromes unless the number is 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        // Reverse half of the number and compare it with the first half
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // If the number is a palindrome, either the number should be the same as the reversedHalf (for even digits)
        // or x should be the same as reversedHalf / 10 (for odd digits, ignoring the middle digit).
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
