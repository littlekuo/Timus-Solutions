#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;


const int INF = 1e7;

const int maxn = 302;

int g[maxn][maxn], d[maxn];
string a[maxn][3];           
map<string, int> m;
bool used[maxn];


void dijkstra(int s, int V){                //Dijkstra算法
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0;

    while(true){
        int v = -1;

        for(int u = 0; u < V; u++){
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }

        if(v == -1) break;
        used[v] = true;

        for(int u = 0; u < V; u++){
            d[u] = min(d[u], d[v] + g[v][u]);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
         m[ a[i][0] ] = 0; m[ a[i][1] ] = 0; m[ a[i][2] ] = 0;         
    }

    int num = 0;
    //给每一个字符串进行编号
    for(auto it = m.begin(); it!=m.end(); it++){
            it->second = ++num;                       
    }

    for(int i=0; i < maxn; i++){
        for(int j=0; j < maxn; j++) {
            g[i][j] = INF;
        }
    }

    //初始化组员 之间距离
    for(int i=0; i<n; i++){                          
            int f1 = m.find(a[i][0])->second, f2 = m.find(a[i][1])->second, f3 = m.find(a[i][2])->second;
            g[f1][f2] = g[f2][f3] = g[f1][f3] = 1;
            g[f2][f1] = g[f3][f2] = g[f3][f1] = 1;
    }

    auto it = m.find("Isenbaev");
    if(it == m.end()){
        for(it=m.begin(); it!=m.end(); it++) 
           cout<< it->first << " " << "undefined" << endl;
    }
    else{
        dijkstra(it->second, m.size() + 1);

        for(it=m.begin(); it!=m.end(); it++){
            cout << it->first << " ";
            if(d[it->second] == INF) puts("undefined");
            else cout<< d[it->second] << endl;
        }
    }
    
    return 0;
}
