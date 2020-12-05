/*
연구소의 크기 N * M
연구소는 빈칸: 0, 벽: 1, 바이러스: 2로 구성
바이러스는 상하좌우 인접한 빈칸으로 증식 가능
*** 무조건 벽 3개를 세워야 함
*** 3 <= N, M <= 8
*** 2 <= 바이러스 <= 10
*** 3 <= 빈칸
이 때의 빈칸의 최댓값을 구하는 프로그램 구현
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> lab(8, vector<int>(8, 0));
vector<vector<int>> labCopy(8, vector<int>(8, 0));
vector<vector<int>> combination;
vector<int> visited;
vector<int> wall;
vector<int> temp;


int doCombination(vector<int> c, int n, int m){
    int vx, vy, sum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            labCopy[i][j] = lab[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        vx = c[i] / 10;
        vy = c[i] % 10;
        labCopy[vx][vy] = 1;
    }

    int i = 0, j = 0;
    while(i < n){ // 바이러스 증식
        while(j < m){
            if(labCopy[i][j] == 2){
                if(i - 1 >= 0 && labCopy[i-1][j] == 0){ // 윗부분이 연구소 밖이 아니고 빈칸일 경우
                    labCopy[i-1][j] = 2;
                    i--; j--;
                }else if(j - 1 >= 0 && labCopy[i][j-1] == 0){ // 왼쪽부분이 연구소 밖이 아니고 빈칸일 경우
                    labCopy[i][j-1] = 2;
                    j -= 2;
                }else if(j + 1 < m && labCopy[i][j+1] == 0){ // 오른쪽부분이 연구소 밖이 아니고 빈칸일 경우
                    labCopy[i][j+1] = 2;
                    j--;
                }else if(i + 1 < n && labCopy[i+1][j] == 0){ // 아랫부분이 연구소 밖이 아니고 빈칸일 경우
                    labCopy[i+1][j] = 2;
                }
            }
            j++;
        }
        j = 0;
        i++;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(labCopy[i][j] == 0) sum += 1;
        }
    }
    return sum;
}

void bruteForce(int n, int m){
    int vi, vj;
    int max = -1;
    int save = 0;
    
    for(int i = 0; i < n; i++){ // 조합을 위한 빈칸 모음
        for(int j = 0; j < m; j++){
            if(lab[i][j] == 0){
                visited.push_back(i*10 + j);
            }
        }
    }

    for(int i = 0; i < visited.size() - 3; i++){
        wall.push_back(0);
    }
    for(int i = 0; i < 3; i++){
        wall.push_back(1);
    }
    do{
        for(int i = 0; i < wall.size(); i++){
            if(wall[i] == 1){
                temp.push_back(visited[i]);
            }
        }
        combination.push_back(temp);
        temp.clear();
    }while(next_permutation(wall.begin(), wall.end()));

    for(int i = 0; i < combination.size(); i++){
        save = doCombination(combination[i], n, m);
        if(max < save) max = save;
    }
    cout << max << "\n";
}

int main(void){
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> lab[i][j];
        }
    }
    bruteForce(n,m);
    return 0;
}