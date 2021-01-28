#include <bits/stdc++.h>
#define LOCAL
#define MAXN 200020
using namespace std ;
int t,n ;
int l[MAXN], pre[MAXN] ;
int r[MAXN], suf[MAXN] ;

int dl(){
    int flag = 1 ;
    for(int i = 1 ; i <= n ; i++ ){
        pre[i] = l[i] - pre[i-1] ;
        if(pre[i] < 0 ){
            if(flag==0)
                return 0 ;
            flag = 0 ;
            pre[i-1] = l[i] - pre[i-2];
            pre[i] = l[i-1] - pre[i-1];
        }
    }
    /*
    cout << "pre ";
    for(int i = 1; i <= n; i++)
        cout << pre[i] << ' ' ;
    cout << '\n';
     */
    if(pre[n] == 0) return 1 ;
    return 0 ;
}

int dr(){
    int flag = 1 ;
    suf[n+1] = 0;
    for(int i = n ; i > 0 ; i-- ){
        suf[i] = r[i] - suf[i+1] ;
        //cout << suf[i] << ' ' ;
        if(suf[i] < 0 ){
            if(flag==0)
                return 0 ;
            flag = 0 ;
            suf[i+1] = r[i] - suf[i+2];
            suf[i] = r[i+1] - suf[i+1];
        }
    }
    /*
    cout << "suf ";
    for(int i = 1; i <= n; i++)
        cout << suf[i] << ' ' ;
    cout << '\n';
    */
    if(suf[1] == 0) return 1 ;
    return 0 ;
}

int debug(){
    cout << "n is " << n << '\n' ;
    for(int i = 1 ; i <= n ; i++){
        cout << l[i] << ' ' ;
    }
    cout << "\n" ;
    for(int i = n ; i > 0 ; i--)
        cout << r[i] << ' ' ;
    cout << "\n\n" ;
}


int main(){
#ifdef LOCAL
    freopen("in1.txt" , "r" , stdin );
#endif // LOCAL
    cin >> t ;
    while(t--){
        cin >> n ;
        int temp = n-1 ;
        for(int i = 1 ; i <= n ; i++){
            cin >> l[i] ;
            r[i] = l[i] ;
        }
        if(dl() == 1 || dr() == 1 )
            cout << "YES\n" ;
        else
            cout << "NO\n" ;
        //debug() ;
    }
}
