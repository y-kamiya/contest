#include <cstdio>

using namespace std;

void print(int m);

int main() {
    int m;
    while (scanf("%d", &m) != EOF) {
        print(m);
    }
    return 0;
}

void print(int m) {
    if (m < 100) {
        printf("00\n"); 
    } else if (m < 1000) {
        printf("0%d\n", m / 100); 
    } else if (m <= 5000) {
        printf("%d\n", m / 100); 
    } else if (m <= 30000) {
        printf("%d\n", m / 1000 + 50); 
    } else if (m <= 70000) {
        printf("%d\n", (((m / 1000) - 30) / 5) + 80); 
    } else {
        printf("89\n"); 
    }
}
