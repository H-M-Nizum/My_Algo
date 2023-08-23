#include<bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

const int N = 1005;
bool visited[N][N];
int dis[N][N];
int n, m;

vector<pi> path = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isvalid(int c1, int c2){
    return (c1>=0 && c1<n && c2>=0 && c2<m);
}



void bfs(int si, int sj){
    queue<pi> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    visited[si][sj] = true;

    while(!q.empty()){
        pi parent = q.front();
        int p1 = parent.first;
        int p2 = parent.second;
        q.pop();

        for(int i=0; i<4; i++){
            pi p = path[i];
            int c1 = p1+p.first;
            int c2 = p2+p.second;
            if(isvalid(c1, c2) && !visited[c1][c2]){
                visited[c1][c2] = true;
                q.push({c1, c2});
                dis[c1][c2] = dis[p1][p2]+1;
            }
        }


    }
}
int main(){
    cin>>n>>m;
    char a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    int si, sj;
    cin>>si>>sj;
    bfs(si, sj);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}