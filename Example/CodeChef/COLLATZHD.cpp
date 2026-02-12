// https://www.codechef.com/problems/COLLATZHD

int fun(int n){
    if(n <= 6){
        switch(n){
            case 1: return 0;
            case 2: return 1;
            case 3: return 1;
            case 4: return 2;
            case 5: return -1;
            case 6: return 2;
        }
    }
    else if(n%4 != 0) return -1;
    else if(n % 8 == 0 || n <= 12) return 1 + fun(n/2);
    else return 1 + fun((n ^ 3) + 1);
}

void solve(){
    int n;
    cin>>n;
    cout<<fun(n)<<endl;
}
