#include <iostream>

using namespace std;

int main(void){
    int t, a, b;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%1d,%1d", &a, &b);
        printf("%d\n", a+b);
    }

    return 0;
}