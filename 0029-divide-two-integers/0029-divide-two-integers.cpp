class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Overflow case
        }

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert dividend and divisor to long long to prevent overflow
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        // Initialize the result
        long long result = 0;

        // Subtract the divisor multiplied by powers of 2 from the dividend
        while (absDividend >= absDivisor) {
            long long temp = absDivisor;
            int multiple = 1;

            // Double the divisor (using bit shift) until it's larger than the remaining dividend
            while (absDividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract the found multiple of divisor from the dividend
            absDividend -= temp;
            result += multiple;
        }

        // Return the result with the correct sign
        return negative ? -result : result;
    }
};
