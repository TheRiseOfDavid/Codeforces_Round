#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
#define MAXN 200010
#define ll long long
using namespace std;
ll t , n , a[MAXN] = {} ;

int main()
{
//#ifdef LOCAL
//    freopen("in1.txt" , "r" , stdin );
//#endif // LOCAL
    cin >> t ;
    while(t--){
        cin >> n ;
        for(int i = 0 ; i < n ; i++)
            cin >> a[i] ;
        sort(a , a + n);

        ll ans[5] = {} ;
        ans[0] = a[n-1] * a[n-2] * a[n-3] * a[n-4] * a[n-5] ;
        ans[1] = a[n-1] * a[n-2] * a[n-3] * a[0] * a[1] ;
        ans[2] = a[n-1] * a[0] * a[1] * a[2] * a[3] ;
        sort(ans,ans+3);
        cout << ans[2] << '\n' ;
    }

    return 0;
}
