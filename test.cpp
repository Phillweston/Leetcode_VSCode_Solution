#include<iostream>
using namespace std;
int main() {
    int k = 0, sum = 0;
    while (k < 8) {
        if (0 == k % 3) {
            k ++;
            continue;
        }
        k ++;
        sum += k;
    }
    cout << sum << endl;
}