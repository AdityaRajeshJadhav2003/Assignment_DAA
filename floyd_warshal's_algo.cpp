#include<bits/stdc++.h>
using namespace std;
//#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N = 510;
const int INF = 1e9 + 10; 
int dist[N][N];

int main(){
    //boost
    //giving all nodes a longest (infinity) distance
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(i == j){
                dist[i][j] == 0;
            }
            else dist[i][j] == INF;
        }
    }

    //taking inputs of 2D array
    int vertexes, edges;
    cin >> vertexes >> edges;

    for(int i = 0; i<edges ; i++){
        int x,y,wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }

    //floyd warshal's algo
    for(int k = 1; k <= vertexes; k++){
        for(int i = 1; i <= vertexes; i++){
            for(int j = 1; j <= vertexes; j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    //for printing the infinity distances
    for(int i = 1; i <= vertexes; i++){
            for(int j = 1; j <= vertexes; j++){
                if(dist[i][j] == INF){
                    cout<<"I ";
                }
                else{
                    cout<<dist[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    return 0;
}