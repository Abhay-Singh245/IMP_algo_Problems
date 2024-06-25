#include<bits/stdc++.h>
#define ll long long
#define all(arr) arr.begin(),arr.end()
using namespace std;
void pv(vector<ll>v){ for(ll i=0;i<(ll)v.size();i++) cout<<v[i]<<" ";cout<<endl;}
void pyn(bool f) {cout<<(f?"Yes":"No")<<endl;} 
const ll mod=998244353 , M = 1e9 + 7 ;
 
   // ONCE A NOOB ALWAYS A NOOB 

     void solve(){
                    
               ll n , m , inf = 1e18;           
               cin >> n >> m ;

                vector<array<ll,3>>edges ;

              
                while(m --){
                   ll a , b, c;
                   cin >> a >> b >> c ;
                   edges.push_back({--a , --b , c}) ;
                }
                vector<ll>dist(n,inf) , par(n);

                dist[0] = 0 ;

                for(ll i = n  ; i >= 1 ; i --){

                        for(auto arr: edges){
                           ll a = arr[0] , b = arr[1] , c = arr[2] ;
                                if(dist[b] > c + dist[a]){
                                       dist[b] = dist[a] + c ;
                                       par[b] = a ;
                                       if (i == 1){
                                             vector<ll>ans;
                                          for(ll i  = 0 ; i < n ;i ++){
                                               a = par[a] ;
                                          }
                                             ans = {a + 1};
                                             ll  curr = a ;
                                             curr = par[curr] ;
                                             while(curr != a){                                               
                                                   ans.push_back(curr + 1);
                                                   curr = par[curr] ;
                                            }
                                             ans.push_back(a + 1) ;
                                             reverse(all(ans)) ;
                                             cout << "YES" << endl;
                                             pv(ans) ;
                                             return ;
                                       }
                                }   
                        }
                }
                 cout << "NO" << endl;
            
   } 

int main(){

   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T = 1;
   //  cin>>T;  
    while(T--){
     solve();  
   }  
 return 0;
}