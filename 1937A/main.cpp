#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
using namespace std;

map<char , int> dict ;
string strTemp ;
int t , n  ;

void ans(){
    for(auto it : dict){
        //cout << it.second << '\n' ;
        if(it.second % n){
            cout << "NO" << '\n' ;
            return ;
        }
    }
    cout << "YES" << '\n' ;
}

int main()
{

//#ifdef LOCAL
//    freopen("in1.txt" , "r" , stdin );
//#endif // LOCAL

    cin >> t ;
    while(t--){
        cin >> n ;
        dict.clear();
        for(int i = 0 ; i < n ; i++){
            cin >> strTemp ;
            for(int j = 0 ; j < strTemp.length() ; j++){
                dict[strTemp[j]] +=1 ;
            }
        }
        ans();
    }
    return 0;
}
