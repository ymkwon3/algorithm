/*
크기가 N * M인 지도
--주사위전개도--
       2
     4 1 3
       5
       6  -- 뒷면
---------------
지도의 좌표 (r, c)
지도에서 주사위가 놓이는 칸은 항상 0
이동하는 순서 1: 동쪽, 2: 서쪽, 3: 북쪽, 4: 남쪽
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map; // 지도
vector<int> order; // 주사위 이동 명령
vector<int> diceH(3, 0); // 주사위전개도 4 1 3 부분
vector<int> diceV(3, 0); // 주사위전개도 2 1 5 부분
int back; // 주사위 전개도 6 부분 (뒷면)

int n, m; // 지도의 크기
int x, y; // 주사위 좌표
int k; // 명령의 개수

void init(){
    int tmp;
    back = 0;
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++){
        vector<int> element(m, 0);
        map.push_back(element);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < k; i++){
        cin >> tmp;
        order.push_back(tmp);
    }
}

bool move(int direction){
    int tmp = back;
    switch (direction)
    {
    case 1:
        if(y+1 == m) return false;
        back = diceH[2]; diceH[2] = diceH[1];
        diceH[1] = diceH[0]; diceH[0] = tmp;
        diceV[1] = diceH[1];
        y++;
        break;
    case 2:
        if(y == 0) return false;
        back = diceH[0]; diceH[0] = diceH[1];
        diceH[1] = diceH[2]; diceH[2] = tmp;
        diceV[1] = diceH[1];
        y--;
        break;
    case 3:
        if(x == 0) return false;
        back = diceV[0]; diceV[0] = diceV[1];
        diceV[1] = diceV[2]; diceV[2] = tmp;
        diceH[1] = diceV[1];
        x--;
        break;
    case 4:
        if(x+1 == n) return false;
        back = diceV[2]; diceV[2] = diceV[1];
        diceV[1] = diceV[0]; diceV[0] = tmp;
        diceH[1] = diceV[1];
        x++;
        break;

    default:
        break;
    }
    return true;
}

void rolling(int index){
    int value = order[index];
    if(move(value)){
        cout << diceH[1] << "\n";
        if(map[x][y] == 0) map[x][y] = back;
        else{
            back = map[x][y];
            map[x][y] = 0;
        }
    }
}

int main(void){
    init();
    for(int i = 0; i < k; i++){
        rolling(i);
    }
    return 0;
}