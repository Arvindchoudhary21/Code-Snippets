//Sieve -> this works only for 1e7 and bool wala array 1e8 tak chal jayega 
// this code works for both to find prime and to find prime factorizations
const int N = 10000000;
int sieve[N+1];
void createSieve(){
    for (int i = 2; i <= N; i++){
        sieve[i] = i;
    }
    for (int i = 2; i * i <= N; i++){
        if (sieve[i] == i){
            for (int j = i * i; j <= N; j += i){
                if(sieve[j] == j)
                sieve[j] = i;
            }
        }
    }
}
