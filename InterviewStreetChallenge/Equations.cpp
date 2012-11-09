#include <string>
#include <iostream>

using namespace std;

static int mod = 1000007;
int s[500005];
static int primeCount = 0;
int primes[500000];

void cal()
{
    int n = 1000000;
    int num = n / 2;
    
    s[0] = 0;
    
    for (int i = 1; i < num; i ++) {
        s[i] = 2 * i + 1;
    }
    
    for (int i = 1; i <= num; i ++) {
        if (s[i] != 0) {
            for (int j = i + s[i]; j <= num; j += s[i]) {
                s[j] = 0;
            }
        }
    }
    
    primeCount = 0;
    primes[primeCount ++] = 2;
    for (int i = 1; i <= num; i ++) {
        if (s[i] != 0) {
            primes[primeCount ++] = s[i];
        }
    }
    
}

int main ()
{
    cal();
    
    int n;
    long long sum = 1;
    while (cin >> n) {
        sum = 1;
        for(int i = 0; i < primeCount; i++){
            long long tmp = primes[i];
            if (n < tmp) {
                break;
            }
            
            int count = 0;
            while (n >= tmp) {
                count += (n / tmp);
                tmp *= primes[i];
            }
            sum = (sum * (2 * count + 1)) % mod;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}