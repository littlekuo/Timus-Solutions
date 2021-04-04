#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

/* 题意
1.同一颜色的条纹不能相邻
2.蓝色条纹必须放在白色和红色之间
*/

// 用dp[n]表示长度为n时的涂色方案数，则以白色为开头或者以红色为开头 的方案数 为 dp[n]/2;
// dp[n] = dp[n-1] + dp[n-2]

const int maxn = 50;
long long dp[maxn];

long long getCs(int n){
    if(dp[n] > 0) return dp[n];
    if(n == 1) return 2;
    if(n == 2) return 2;
    if(n == 3) return 4;
    dp[n] = getCs(n-1) + getCs(n-2);
    return dp[n];
}


int main(){
    int n;
    memset(dp, 0, sizeof dp);
    scanf("%d",&n);
    std::cout << getCs(n) << std::endl;
}