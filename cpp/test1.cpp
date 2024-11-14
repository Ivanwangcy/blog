#include <stdio.h>
// 思考题1 位数输出
int main() {
    int n;
    scanf("%d", &n);
    printf(" has %d digits\n", printf("%d", n)); // 有多余输出
    char output[50];
    int ret = sprintf(output, "%d", n);
    printf("%d\n", ret); // 无多余输出
    return 0;
}
