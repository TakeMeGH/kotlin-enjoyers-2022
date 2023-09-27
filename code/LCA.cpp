/* Quick Note :
 * Jangan Mikir Lama - lama, sampahin dulu aja kalo OI
 * Always Try to reset
*/
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ld PI = 4*atan((ld)1);
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll nax = 2e5 + 5;

ll t, n, q;
ll a[nax];
vector<ll> v[nax];
ll dep[nax], pa[nax][35];

bool cmp(pair<ll,ll> xx, pair<ll,ll> yy){
	if(xx.ff == yy.ff){
		return xx.ss > yy.ss;
	}
	return xx.ff < yy.ff;
}

void dfs_lca(ll idx, ll bfr, ll cur_dep = 0){
	pa[idx][0] = bfr;
	dep[idx] = cur_dep;
	for(ll i = 1; i < 21; i++){
		if(pa[idx][i-1] == -1) continue;
		pa[idx][i] = pa[pa[idx][i-1]][i-1];
	}
	for(auto it : v[idx]){
		if(it == bfr) continue;
		dfs_lca(it, idx, cur_dep + 1);
	}
}

ll LCA(ll x, ll y){
	if(dep[x] < dep[y]){
		swap(x, y);
	}
	ll diff = dep[x] - dep[y];
	for(ll i = 0; i < 21; i++){
		if((1 << i) & diff){
			x = pa[x][i];
		}
	}
	if(x == y) return x;
	for(int i = 20; i >= 0; i--){
		if(pa[x][i] != pa[y][i]){
			x = pa[x][i];
			y = pa[y][i];
		}
	}
	return pa[x][0];
}
	
int main(){ 
	memset(pa, -1, sizeof(pa));
	dfs_lca(1, -1);
}
