#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_SIZE 100000

using namespace std;

int aLen , bLen;
int result[MAX_SIZE];

void sum(char* a, char* b, bool minus);
void sub(char* a, char* b, bool minus);
int main(void){
    bool minusA = false, minusB = false;
    int i = 0, compare = 0;
    char a_char[MAX_SIZE];
    char b_char[MAX_SIZE];
    cin >> a_char >> b_char;
    aLen = strlen(a_char);
    bLen = strlen(b_char);

    if(a_char[0] == '-'){
        memmove(a_char, a_char+1, aLen);
        minusA = true;
    }
    if(b_char[0] == '-'){
        memmove(b_char, b_char+1, bLen);
        minusB = true;
    }

    aLen = strlen(a_char);
    bLen = strlen(b_char);

    compare = strcmp(a_char, b_char);
    reverse(a_char, a_char+aLen);
    reverse(b_char, b_char+bLen);

    if(aLen > bLen){
        if(!minusA && !minusB){
            sum(a_char, b_char, false);
        }else if(minusA && minusB){
            sum(a_char, b_char, true);
        }else if(minusA && !minusB){
            sub(a_char, b_char, true);
        }else if(!minusA && minusB){
            sub(a_char, b_char, false);
        }
    }else if(aLen < bLen){
        if(!minusA && !minusB){
            sum(b_char, a_char, false);
        }else if(minusA && minusB){
            sum(b_char, a_char, true);
        }else if(minusA && !minusB){
            sub(b_char, a_char, false);
        }else if(!minusA && minusB){
            sub(b_char, a_char, true);
        }
    }else if(aLen == bLen){
        if(compare >= 0){
            if(!minusA && !minusB){
                sum(a_char, b_char, false);
            }else if(minusA && minusB){
                sum(a_char, b_char, true);
            }else if(!(minusA == minusB) && compare == 0){
                cout << 0;
            }else if(minusA && !minusB){
                sub(a_char, b_char, true);
            }else if(!minusA && minusB){
                sub(a_char, b_char, false);
            }
        }else{
            if(!minusA && !minusB){
                sum(b_char, a_char, false);
            }else if(minusA && minusB){
                sum(b_char, a_char, true);
            }else if(minusA && !minusB){
                sub(b_char, a_char, false);
            }else if(!minusA && minusB){
                sub(b_char, a_char, true);
            }
        }
    }
    return 0;
}

void sum(char* a, char* b, bool minus){
    int quotient = 0, remainder = 0, i = 0, aValue = 0, bValue = 0;
    aLen = strlen(a);
    bLen = strlen(b);

    while(i < aLen){
        aValue = int(a[i] - '0');
        if(i < bLen){
            bValue = int(b[i] - '0');
            remainder = ((aValue + bValue) % 10) + quotient;
            quotient = (aValue + bValue) / 10;
        }else{
            remainder = aValue + quotient;
            quotient = 0;
        }
        if(remainder > 9){
            remainder = 0;
            quotient++;
        }
        result[i] = remainder;
        if(quotient == 1 && i == aLen - 1) {
            result[i+1] = quotient;
            i++;
        }
        i++;
    }
    if(minus)cout << "-";
    for(int j = i-1; j >= 0; j--){
        cout << result[j];
    }
}

void sub(char* a, char* b, bool minus){
    aLen = strlen(a);
    bLen = strlen(b);
    int remainder = 0, i = 0, j = 1, aValue = 0, bValue = 0;
    bool continuosZero = true;
    while(i < aLen){
        aValue = int(a[i] - '0');
        if(i < bLen){
            bValue = int(b[i] - '0');
            if(aValue >= bValue){
                remainder = aValue - bValue;
            }else{
                while(int(a[i+j] - '0') == 0){
                    a[i+j] = '9';
                    j++;
                }
                a[i+j]--;
                remainder = aValue - bValue + 10;
                j = 1;
            }
        }else{
            remainder = aValue;
        }
        result[i] = remainder;
        if(i + j == aLen - 1 && int(a[i+j] - '0') == 0) break;
        i++;
    }
    if(minus)cout << "-";
    for(int j = i; j >= 0; j--){
        if(result[j] == 0 && continuosZero)continue;
        continuosZero = false;
        cout << result[j];
    }
}