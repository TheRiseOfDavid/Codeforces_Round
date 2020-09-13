#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 110
using namespace std;
int t , n , num[MAXN] ={} ;

int main()
{
//#ifdef LOCAL
//    freopen("in1.txt" ,"r" , stdin ) ;
//#endif // LOCAL

    cin >> t ;
    while(t--){
        cin >> n ;
        for(int i = 0 ; i < n ; i++)
            cin >> num[i] ;
        sort(num,num+n);

        int a=0 , b = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(num[i] == a ) a++;
            else if (num[i] == b ) b++ ;
        }
        cout << a + b << '\n' ;
    }

    return 0;
}
