#include <iostream> #include <math.h> 
using namespace std;

// 设 t(n) 表示为 123~n 的位数
// 则有 f(n) = f(n-1) + t(n)

int length = 80000;
int tn[80000];

// 计算一个数字的长度，比如 12345678，则返回8
int getLength(int num) {
    int length = 0;
    while (num/10 != 0) {
        num/=10;
        length++;
    }
    return length + 1;
}

// 统一计算 tn[] 的值
void calculationTn() {
    tn[0] = 0;
    tn[1] = 1;
    for (int i =1; i < length; i++) {
        tn[i] = tn[i - 1] + getLength(i);
    }
}

// 计算该数字的第 index 位的数字，比如 12345678 第三位数，则返回 3（number、index 必须大于 0）
int getNumFromIntegerByIndex(int number, int index) {
    int length = getLength(number);
    for (int i = 0; i < length - index; i++) {
        number/=10;
    }
    return number%10;
}

// 从123456789101112..中查找第 index 个数
int findFromNumber(int index) {
    for (int t = 1; t < length; t++) {
        if (index <= tn[t]) {
            return getNumFromIntegerByIndex(t, index - tn[t - 1]);
        }
    }
    return 0;
}

// 从完整数列（1 12 123 1234 12345 ....）中查找第 index 未数
int findFromWhole(int index) {
    for(int i = 1; i < length; i++) {
        if (index > tn[i]) {
            index -= tn[i];
        } else if (index < tn[i]) {
            return findFromNumber(index);
        } else {
            //number == tn[i]
            return getNumFromIntegerByIndex(i, getLength(i));
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    calculationTn();
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        printf("%d\n", findFromWhole(num));
    }
}