#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long left = 0, right = n, ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (mid * mid <= n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%lld", ans);
    return 0;
}