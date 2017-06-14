#include <bits/stdc++.h>
#define MAXN 41000
#define MLN 20
using namespace std;
struct tup{
    int nr[2];
    int ind;
};
int P[MAXN][MLN];

bool cmp(tup a,tup b){
    if(a.nr[0] != b.nr[0]){
        return a.nr[0] < b.nr[0];
    }
    return a.nr[1] < b.nr[1];
}
tup arr[MAXN];
int SA[MAXN];
vector<int> SuffixArray(string s){

        int N = s.size();
        for(int i=0;i<N;i++){
            P[i][0] = s[i] - 'a';

        }
        int step =1,pow = 1;
        for(step = 1;(pow>>1)< N;step++)
        {
            for(int i=0;i<N;i++){
                arr[i].nr[0] = P[i][step-1];
                arr[i].nr[1] = (i + pow) < N ? P[i+pow][step-1]:INT_MAX;
                arr[i].ind = i;
            }
            sort(arr,arr+N,cmp);
            for(int i=0;i<N;i++){
                P[arr[i].ind][step] = i > 0 && arr[i].nr[0] == arr[i-1].nr[0] && arr[i].nr[1]==arr[i-1].nr[1] ? P[arr[i-1].ind][step] : i;
            }
            pow *= 2;
        }
        int mins = INT_MAX;
        int mini = 0;
        for(int i=0;i<N;i++){
            SA[P[i][step-1]= i;
            //cout<<SA[i]<<endl;


        }
        vector<int> s;
        for(int i=0;i<n;i++)
        {
            s.push_back(SA[i]);
        }
        return s;


}
vector<int> lcp(string s,vector<int> sa){
        int n = s.size(), k =0;
        vector<int> lcpa(n,0);
        vector<int> ranks(n,0);
        for(int i=0;i<n;i++){
            ranks[sa[i]] = i;
        }
        for(int i=0;i<n;i++,k>0?k--:0){
            if(ranks[i] == n-1){
                k = 0;
                continue;
            }
            int j = sa[ranks[i] + 1];
            while(i+k < n and j+k <n and s[i+k] == s[j+k])k++;
            lcpa[ranks[i]] = k;



        }

        return lcpa;

}
