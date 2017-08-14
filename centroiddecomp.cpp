#include<bits/stdc++.h>/* In the name of God we code */
using namespace std;
#define debug(a)    			cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define show1(a,n) 			cout<<endl;for(int i=0;i<n;i++){cout<<a[i]<<" ";}
#define show2(a,n,m) 			cout<<endl;for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<" ";}cout<<endl;}

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#define pb(i) 				push_back(i)
#define mp(i,j) 			make_pair(i,j)
#define mod 				1000000007
#define F           			first
#define S           			second
#define endl        			'\n'
#define ll 				long long
#define pii           pair <int,int>
#define N 1000010
int subtreeSize[N];
bool blocked[N];
int parent[N];
vector<int> tree[N];
queue<int> qu;
void dfs1(int src,int p){
    subtreeSize[src] = 1;
    parent[src] = p;
    for(auto ch:tree[src]){
        if(ch!=p and !blocked[ch]){
            dfs1(ch,src);
            subtreeSize[src]+=subtreeSize[ch];
        }
    }
    //trace3(src,subtreeSize[src],parent);
}
void findCentroid(int vert){
    //trace1(vert);
    dfs1(vert,vert);
    qu.push(vert);
    int minSize = INT_MAX;
    int centroid;
    while(!qu.empty()){
        int cur_ver = qu.front();
        qu.pop();
        int sz = subtreeSize[vert] - subtreeSize[cur_ver];
        for(auto ch:tree[cur_ver]){
            if(ch!=parent[cur_ver] and !blocked[ch] ){
                sz = max(sz,subtreeSize[ch]);
                qu.push(ch);
            }

        }
        if(sz < minSize){
            minSize = sz;
            centroid = cur_ver;
        }
        //trace2(cur_ver,minSize);
    }
    //trace2(centroid,minSize);
    ansarr[centroid] = rk;

    blocked[centroid] = true;

    for(auto ch:tree[centroid]){
        if(!blocked[ch]){
            findCentroid(ch);
        }

    }
}

int main()
{

	ios_base:: sync_with_stdio(false); cin.tie(0);
    int n,s,d;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>s>>d;
        tree[s].pb(d);
        tree[d].pb(s);
    }
    dfs1(1,1);
    findCentroid(1);







	return 0;

}
