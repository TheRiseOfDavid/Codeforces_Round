#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 120
using namespace std;
int t , n ;
priority_queue<int> num;
int a , b ;

void judge(){
    int a , b ;
    while(num.size()){
        a = num.top() ;
        a-- ;
        num.pop();
        if(!num.size()){
            cout << "T" << '\n' ;
            return ;
        }

        b = num.top() ;
        b-- ;
        num.pop();
        if(a > 0)
            num.push(a);
        if(b > 0)
            num.push(b);
    }
    cout << "HL" << '\n' ;
}

int main()
{
//#ifdef LOCAL
//    freopen("in1.txt" , "r" , stdin );
//#endif // LOCAL
    cin >> t ;
    while(t--){
        cin >> n ;
        int intTemp ;
        for(int i = 0 ; i < n ; i++){
            cin >> intTemp ;
            num.push(intTemp) ;
        }
        judge();
    }
    return 0;
}
