#include <iostream>
<<<<<<< HEAD
=======
<<<<<<< HEAD

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
=======
>>>>>>> 472a7455278af9725957723e3e2408dd575deec0
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

<<<<<<< HEAD
=======
>>>>>>> 339ff9c3d3bfe590aca334f1eb16634f612d5119
>>>>>>> 472a7455278af9725957723e3e2408dd575deec0
    return 0;
}
