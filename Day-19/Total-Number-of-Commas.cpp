class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long start = 1000;
        long long commas = 1;

        while (start <= n) {
            long long end = start * 1000 - 1;
            long long last = min(n, end);
            long long count = last - start + 1;

            total += count * commas;

            start *= 1000;
            commas++;
        }

        return total;
    }
};