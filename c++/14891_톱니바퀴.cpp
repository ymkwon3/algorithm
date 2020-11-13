/* 
회전 시키기 전의 톱니의 극이 다르면 A가 회전한 방향의 반대방향으로 B가 회전
톱니의 상태는 8개의 정수, N극은 0, S극은 1
방향이 1인 경우는 시계방향, -1인 경우는 반시계 방향

점수 출력
1번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 1점
2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점

본인 기준
0 = 12시방향, 2 = 3시방향, 6 = 9시방향
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int wheel = 4, gear = 8;


int* rotate(int arr[], int direction){
    int rotated[gear] = {0,};

    if(direction == 1){ // right rotate
        for(int i = 0; i < gear; i++){
            if (i == gear-1){
                printf("bye %d\n", arr[i]);
                rotated[0] = arr[i];
            }
            else{
                printf("hello %d\n", arr[i]);
                rotated[i+1] = arr[i];
            }
        }
    }
    else if(direction == -1){ // left rotate
        for(int i = 0; i < gear; i++){
            if (i == 0){
                rotated[gear-1] = arr[i];
            }
            else{
                rotated[i-1] = arr[i];
            }
        }
    }
    copy(arr, arr+gear, rotated);
    
    return arr;
}

int main(void){
    int wheels[wheel][gear];

    for(int i = 0; i < wheel; i++){
        for(int j = 0; j < gear; j++){
            scanf("%1d", &wheels[i][j]);
        }
    }

    for(int i = 0; i < wheel; i++){
        for(int j = 0; j < gear; j++){
            printf("%d", wheels[i][j]);
        }
        printf("\n");
    }
    int *ptr = rotate(wheels[0], 1);
    for(int i = 0; i < gear; i++){
        printf("%d", ptr[i]);
    }

    return 0;
}