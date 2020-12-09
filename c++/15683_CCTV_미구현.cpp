/*
지도 크기 n, m
지도에서의  0: 사각지대, 1~5: cctv, 6: 벽, 9: 감시구역
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map; // 지도
vector<int> cctv; // cctv 번호
vector<int> cctv_x; // cctv x좌표
vector<int> cctv_y; // cctv y좌표
int n, m; // 지도 크기

void init(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        vector<int> element(m, 0);
        map.push_back(element);
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6){
                cctv_x.push_back(i);
                cctv_y.push_back(j);
                cctv.push_back(map[i][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

}

void watch(){
    
}

void cctv_5(int number){
    int cctv_number = cctv[number];
    int x = cctv_x[number];
    int y = cctv_y[number];
    for(int i = 0; i < n; i++){
        if(map[x][i] == 6){
            break;
        }
    }
}

void observe(){
    for(int i = 0; i < cctv.size(); i++){

    }
}

int main(void){
    init();
    return 0;
}