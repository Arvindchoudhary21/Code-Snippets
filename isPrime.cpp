bool isPrime(int n){
    // Corner cases
    if (n <= 1)
    return false;
    //so if a no. is prime then it can be check by numbers smaller than square root of the n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
