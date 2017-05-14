#include <bits/stdc++.h>
using namespace std;
#define I will do fft
const long long MAXN = 1<<15;
const double PI=2*(acos((long double)0.0));
struct cd{
    long double a;
    long double b;
    cd operator+(const cd y){
        cd z;
        z.a = this->a + y.a;
        z.b = this->b + y.b;
        return z;
    }
    cd operator*(const cd y){
        cd z;
        z.a = this->a * y.a - this->b * y.b;
        z.b = this->b * y.a + this->a * y.b;
        return z;
    }
};
typedef vector<cd> vcd;


vcd roots(long long n){ // n is next higher power of two

    vcd root;
    root.reserve(n);
    cd z;
    for(long long i=0;i<n;i++){
         z.a = cos((2*PI*i)/n);
         z.b= sin((2*PI*i)/n);
         root.push_back(z);
    }
    return root;
}
vcd fft(vcd coff,vcd val){
    if(coff.size()==1){
        return coff;
    }

    vcd even,odd,newvalues;
    long long n = coff.size();
    for(long long i=0;i<n;i++){
        if(i%2 == 0){
            even.push_back(coff[i]);

        }
        else{
            odd.push_back(coff[i]);
        }
    }

    for(long long i=0;i<n/2;i++){
        newvalues.push_back(val[i]*val[i]);
    }
    vcd coff1 = fft(even,newvalues);
    vcd coff2 = fft(odd,newvalues);
    vcd toreturn;
    toreturn.reserve(n);
    for(long long i=0;i<n;i++){
        if(i<n/2){
            toreturn[i] = coff1[i] + val[i]*coff2[i];
        }
        else{
            toreturn[i] = coff1[i-n/2] +val[i]*coff2[i-n/2];
        }

    }
    return toreturn;

}
vector<long long> interpolate(vcd coff1,vcd coff2){
    long long  n = max(coff1.size(),coff2.size());
    long long near2n = 1;
    while(near2n<n)near2n *= 2;
    n = near2n;
    n *= 2;
    //cout<<"n"<<n<<endl;
    cd z;z.a = 0;z.b = 0;
    for(long long j=coff1.size();j<n;j++){
        coff1.push_back(z);
    }
    for(long long k=coff2.size();k<n;k++){
        coff2.push_back(z);
    }
    /*for(long long i=0;i<n;i++){
        cout<<coff1[i].a<<" "<<coff1[i].b<<" "<<coff2[i].a<<" "<<coff2[i].b<<endl;
    }*/
    vcd r = roots(n);
    vcd r1 = fft(coff1,r);vcd r2 = fft(coff2,r);
    vcd r3;
    cd r4;
    for(long long i=0;i<n;i++)
    {
            //cout<<r1[i].a<<" "<<r2[i].a<<endl;
            r4 = r1[i]*r2[i];
            r4.b = -1 * r4.b;
            r3.push_back(r4);
    }
    //cout<<r3.size()<<" "<<r.size()<<endl;
    vcd ans = fft(r3,r);
    //cout<<"Hello"<<endl;
    vector<long long> vp;
    for(long long i=0;i<n;i++){
        //cout<<ans[i].a<<" ";
        vp.push_back((long long)roundl((ans[i].a)/n));
    }
    //cout<<"\n";

    return vp;

}





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t,n;
    vcd coff1,coff2;
    cd z;
    cin>>t;
    while(t--){
        cin>>n;
        for(long long i=0;i<=n;i++){
            cin>>z.a;
            z.b = 0;
            coff1.push_back(z);
        }
        reverse(coff1.begin(),coff1.end());

        for(long long i=0;i<=n;i++){
            cin>>z.a;
            z.b = 0;
            coff2.push_back(z);
        }
        reverse(coff2.begin(),coff2.end());
        //cout<<"Hello"<<endl;
        vector<long long> ans = interpolate(coff1,coff2);
        reverse(ans.begin(),ans.begin()+2*n+1);
        //cout<<endl;
        for(long long i=0;i<2*n+1;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        coff1.clear();
        coff2.clear();
        ans.clear();
    }
    return 0;
}
