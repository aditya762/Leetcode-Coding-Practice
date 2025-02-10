class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, result = 0;
        int n = s.size();

        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for the sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert characters to an integer, stop if a non-digit is encountered
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: Handle overflow/underflow cases
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        // Return the final result with the correct sign
        return result * sign;
    }
};
