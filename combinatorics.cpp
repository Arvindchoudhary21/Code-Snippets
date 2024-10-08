//(combinatorics with mod)
int inverse(int x){return powerwithmod(x , M-2);}
int mod(int x){return ((x%M + M)%M);}
int add(int a, int b){return mod(mod(a)+mod(b));}
int sub(int a, int b){return mod(mod(a)-mod(b));}
int mul(int a, int b){return mod(mod(a)*mod(b));}
int divm(int a , int b){return mul(a , inverse(b));}
int fact[10000000];
void calculate_factorial(){fact[0] = 1;
    for(int i=1; i<10000000; i++){fact[i] = mul(fact[i-1],i);}}
int ncr(int n , int r){return mul(mul(fact[n] , inverse(fact[r])) , inverse(fact[n-r]));}
