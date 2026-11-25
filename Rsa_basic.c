#include<stdio.h>
int gcd(int n1, int n2) {
    if (n1 < n2) {
        int temp = 0;
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    if (n2 == 0) {
        return n1;
    }
    if (n1%n2 == 0) {
        return n2;
    }
    else {
        return gcd(n2,n1%n2);
    }
}
long long pow_expo(long long x, long long n, long long M) {
    long long res = 1;
    for(int i = 1; i <= n; i++) {
        res = (res * x) % M;
    }
    return res;
}
int main() {
    printf("Hello ^[`~`]\n");
    printf("Enter two prime numbers:-\n");
    int p0,p1;
    scanf("%d %d",&p0,&p1);
    int e_t = (p0-1)*(p1-1);
    int i;
    for (i = 2; i<e_t; i++) {
        if (gcd(i,e_t) == 1) {
            break;
        }
    }
    int pub_k = i;
    for (i = 2; i<e_t; i++) {
        if ((pub_k)*(i)%e_t == 1) {
            break;
        }
    }
    int n = p0*p1;
    printf("--Note-0<=message<=%d--\n",n-1);
    int pri_k = i;
    printf("Enter your message in the numeral form\n");
    long long int message;
    scanf("%lld",&message);
    long long int encyrypted = pow_expo(message,pub_k,n);
    long long int decryption = pow_expo(encyrypted,pri_k,n);
    printf("Encrypted text=%lld\n",encyrypted);
    printf("Private key=%d\n",pri_k);
    printf("Public key=%d",pub_k);
    printf("\nEnding my shell life |^~^|");
    return 0;
}
