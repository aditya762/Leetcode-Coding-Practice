class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Traverse both strings from right to left
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            // Add the bits from 'a'
            if (i >= 0) {
                sum += a[i--] - '0';
            }

            // Add the bits from 'b'
            if (j >= 0) {
                sum += b[j--] - '0';
            }

            // Compute the current bit and update carry
            carry = sum / 2;
            result += (sum % 2) + '0';
        }

        // The result is built in reverse, so we reverse it before returning
        reverse(result.begin(), result.end());
        return result;
    }
};
