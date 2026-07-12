class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        int sign = (x< 0) ? -1:1;
        x = abs(x);

        while(x > 0) {
            rev = rev*10 + x % 10;
            x/= 10;
        }
        rev*=sign;
        if (rev < numeric_limits<int>::min() || rev > numeric_limits<int>::max())
        return 0;

    return static_cast<int>(rev);
    }
};
