
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(a%2 == 0)
    {
        cout << "yes" << endl;
    }
    else if(b%2 == 1){
        cout << "yes" << endl;
    }
    else cout << "no" << endl;
}