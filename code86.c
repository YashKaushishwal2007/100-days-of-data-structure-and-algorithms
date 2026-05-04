#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long low = 0, high = n, ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (mid <= n / mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%lld", ans);
    return 0;
}