/*
http://codevs.cn/problem/3145/
page 14
*/

#include "iostream"

using namespace std;

void hanoi(int n, char A, char B, char C){
    if(n == 1){
        cout<<1<<" from "<<A<<" to "<<C<<endl;
        return;
    }
    hanoi(n-1, A, C, B);
    cout<<n<<" from "<<A<<" to "<<C<<endl;
    hanoi(n-1, B, A, C);
}

int main(){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}