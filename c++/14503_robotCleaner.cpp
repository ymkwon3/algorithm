/*
로봇 청소기가 있는 장소는 N * M의 직사각형
각각의 칸은 벽 혹은 빈 칸
지도의 각 칸은 (r,c)로 나타내고
r : 북쪽으로부터 떨어진 칸의 개수
c : 서쪽으로부터 떨어진 칸의 개수
d : 청소기가 바라보는 방향 (0: 북, 1: 동, 2: 남, 3: 서)
*/


# include <iostream>
# include <vector>

using namespace std;

int n, m; // 맵의 크기
int r, c; // 로봇 청소기의 생성 위치
int d; // 로봇 청소기 생성시 바라보는 방향
int cleanCnt;
int rotateCnt;
vector<vector<int>> map; // 지도
vector<vector<bool>> visited; // 방문 기록

void init(){
    cleanCnt = 0;
    rotateCnt = 0;
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i = 0; i < n; i++){
        vector<int> element(m, 0);
        vector<bool> visit(m, false);
        map.push_back(element);
        visited.push_back(visit);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
}

bool research(int x, int y, int direction){
    switch (direction)
    {
    case 0:
        return (map[x][y-1] == 0 & !visited[x][y-1]);
    case 1:
        return (map[x-1][y] == 0 & !visited[x-1][y]);
    case 2:
        return (map[x][y+1] == 0 & !visited[x][y+1]);
    case 3:
        return (map[x+1][y] == 0 & !visited[x+1][y]);
    }
    return false;
}

void move(int direction){
    switch (direction)
    {
    case 0:
        r--;
        break;
    case 1:
        c++;
        break;
    case 2:
        r++;
        break;
    case 3:
        c--;
        break;
    }
}

void rotate(){
    if(d == 0) d = 3;
    else d--;
}

void back(int direction){
    rotateCnt = 0;
    switch (direction)
    {
    case 0:
        r++;
        break;
    case 1:
        c--;
        break;
    case 2:
        r--;
        break;
    case 3:
        c++;
        break;
    }
}

bool isExit(int direction){
    switch (direction)
    {
    case 0:
        if(map[r+1][c] == 1) return true;
        else return false;
    case 1:
        if(map[r][c-1] == 1) return true;
        else return false;
    case 2:
        if(map[r-1][c] == 1) return true;
        else return false;
    case 3:
        if(map[r][c+1] == 1) return true;
        else return false;
    }
    return false;
}

void cleaning(){
    if(!visited[r][c]){
        visited[r][c] = true;
        cleanCnt++;
    }
    
    if(research(r, c, d)){
        rotateCnt = 0;
        rotate();
        move(d);
        cleaning();
    }else{
        rotateCnt++;
        rotate();
        if(rotateCnt == 4){
            if(isExit(d)){
                cout << cleanCnt;
            }else{
                back(d);
                cleaning();
            }
        }else{
            cleaning();
        }
    };

}

int main(void){
    init();
    cleaning();
    return 0;
}