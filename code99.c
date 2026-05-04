#include <stdio.h>

void swap(float *a, float *b) {
    float t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int n;
    scanf("%d", &n);

    int target;
    scanf("%d", &target);

    int pos[100], speed[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &pos[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pos[i] < pos[j]) {
                int tp = pos[i];
                pos[i] = pos[j];
                pos[j] = tp;

                int ts = speed[i];
                speed[i] = speed[j];
                speed[j] = ts;
            }
        }
    }

    float time[100];
    for (int i = 0; i < n; i++) {
        time[i] = (float)(target - pos[i]) / speed[i];
    }

    int fleets = 0;
    float curr = 0;

    for (int i = 0; i < n; i++) {
        if (time[i] > curr) {
            fleets++;
            curr = time[i];
        }
    }

    printf("%d", fleets);
    return 0;
}