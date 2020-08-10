#include "pch.h"

using namespace std;

int main() {
    int bound1;
    int bound2;
    scanf("%d %d", &bound1, &bound2);

    int count = 0;
    double sum_sq = 0.0;
    double mean = (bound1 + bound2) / 2.0;

    auto AddResult = [&](int x) {
        printf("%d ", x);
        ++count;

        double diff = x - mean;
        sum_sq += diff * diff;
    };

    if (bound1 != bound2) {
        if (bound1 < bound2) {
            for (int i = bound1; i <= bound2; ++i)
                AddResult(i);
        }
        else {
            for (int i = bound1; i >= bound2; --i)
                AddResult(i);
        }
    }
    
    printf("\nAverage = %.1f", mean);

    double deviation = count > 0 ? sqrt(sum_sq / (count - 1)) : 0.0;
    printf("\nSD = %.2f", deviation);
}
