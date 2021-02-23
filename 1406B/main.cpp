#include <iostream>
#include <bits/stdc++.h>
#define LOCAL
<<<<<<< HEAD
#define ll long long
using namespace std;
struct lln{
    ll num , neg ;
};
deque<lln> dnum;
int t , n ;
ll maxn = 0;
int compare(lln a , lln b){
    return  a.num < b.num ;
}

void p(int index , ll sum , int i , ll intNeg ){
    //cout << index << ' ' << sum << ' ' << i << ' ' << intNeg << '\n' ;

    if(index >= 5){
        maxn = max(sum,maxn) ;
        //cout << sum << '\n' ;
        return ;
    }
    if(i < 0 )
        return ;
    p(index +1 , sum * dnum[i].num * (dnum[i].neg? -1 : 1) , i-1 , intNeg+dnum[i].neg);

    if((intNeg+dnum[i].neg) % 2 == 1){
        p(index, sum , i-1 , intNeg);
    }
}

int main()
{
#ifdef LOCAL
    freopen("in1.txt", "r" , stdin );
#endif // LOCAL

    lln temp ;

    cin >> t ;
    while(t--){
        cin >> n ;
        dnum.clear();
        maxn = -1e15;
        for(int i = 0 ; i < n ; i++){
            cin >> temp.num ;
            if(temp.num < 0){
                temp.neg = 1 ;
                temp.num *= -1 ;
            }
            else
                temp.neg = 0 ;
            //cout << temp.num << ' ' << temp.neg << '\n';
            dnum.push_back(temp) ;
        }
        //cout << '\n' ;
        sort(dnum.begin() , dnum.end(), compare ) ;
        p(0,1,n-1,0);
        cout << maxn << '\n' ;
    }



=======
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

>>>>>>> 339ff9c3d3bfe590aca334f1eb16634f612d5119
    return 0;
}
