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
#include <cmath>
#include <vector>

using namespace std;

const int wheel = 4, gear = 8;
vector<vector<int>> wheels(wheel, vector<int>(gear,0));

void rotate(int wheelNumber, int direction, int preWheel){
    int pre = 0, next = 0;

    if(wheelNumber == 0){ // 첫번째 바퀴일 경우
        if((wheels[wheelNumber][2] != wheels[wheelNumber + 1][6]) && wheelNumber + 1 != preWheel){
            rotate(wheelNumber + 1, -direction, wheelNumber);
        }
    }else if(wheelNumber == wheel - 1){ // 마지막 바퀴일 경우
        if((wheels[wheelNumber][6] != wheels[wheelNumber - 1][2]) && wheelNumber - 1 != preWheel){
            rotate(wheelNumber - 1, -direction, wheelNumber);
        }
    }else{ // 바퀴의 양 옆에 바퀴가 존재할 경우
        if((wheels[wheelNumber][6] != wheels[wheelNumber - 1][2]) && wheelNumber - 1 != preWheel){ // left
            rotate(wheelNumber - 1, -direction, wheelNumber);
        }
        if((wheels[wheelNumber][2] != wheels[wheelNumber + 1][6]) && wheelNumber + 1 != preWheel){ // right
            rotate(wheelNumber + 1, -direction, wheelNumber);
        }
    }

    if(direction == 1){ // right rotate
        pre = wheels[wheelNumber][0];
        for(int i = 0; i < gear; i++){
            if (i == gear-1){
                wheels[wheelNumber][0] = next;
            }
            else{
                next = wheels[wheelNumber][i+1];
                wheels[wheelNumber][i+1] = pre;
                pre = next;
            }
        }
    }
    else if(direction == -1){ // left rotate
        pre = wheels[wheelNumber][gear-1];
        for(int i = gear-1; i >= 0; i--){
            if (i == 0){
                wheels[wheelNumber][gear-1] = next;
            }
            else{
                next = wheels[wheelNumber][i-1];
                wheels[wheelNumber][i-1] = pre;
                pre = next;
            }
        }
    }
}

int main(void){
    int rotateCount = 0, wheelNumber = 0, direction = 0, result = 0;

    for(int i = 0; i < wheel; i++){
        for(int j = 0; j < gear; j++){
            scanf("%1d", &wheels[i][j]);
        }
    }

    scanf("%d", &rotateCount);

    for(int i = 0; i < rotateCount; i++){
        scanf("%d %d", &wheelNumber, &direction);
        rotate(wheelNumber - 1, direction, -1);
    }
    
    for (int i = 0; i < wheel; i++){
        if(wheels[i][0] == 1){
            result += pow(2, i);
        }
    }

    printf("%d\n", result);

    return 0;
}