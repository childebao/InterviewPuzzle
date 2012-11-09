#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) 
{
    while (1) {
        a = a % b;
        if (a == 0) {
            return b;
        }
        
        b = b % a;
        if (b == 0) {
            return a;
        }
    }
}

template <typename T>
set<T> theDifference(const set<T> &set1, const set<T> &set2) {
    set<T> difference;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), insert_iterator< set<T> > (difference, difference.begin()));
    return difference;
}

void getFactors(unsigned long long int x, set<unsigned long long int> & s)
{
    unsigned long long int sqrtX = sqrt((double)x);
    
    for (int i = 1; i < sqrtX; i ++) {
        if (x % i == 0) {
            s.insert(i);
            s.insert(x/i);
        }
    }
}

int main ()
{
    int n;
    unsigned long long int k;
    cin >> n >> k;
    
    vector<unsigned long long int> unfriendlyNums(n);
    
    for (int i = 0; i < n; i ++) {
        cin >> unfriendlyNums[i];
    }
    
    set<unsigned long long int> friendlyFactors;
    getFactors(k, friendlyFactors);
    
    set<unsigned long long int> unfriendlyFactors;
    for (int i = 0; i < n; i ++) {
        unsigned long long int unfriendly = unfriendlyNums[i];
        unsigned long long int g = gcd(unfriendly, k);
        unfriendlyFactors.insert(g);
        getFactors(g, unfriendlyFactors);
    }
    
    set<unsigned long long int> differenctFactors = theDifference(friendlyFactors, unfriendlyFactors);
    cout << differenctFactors.size() << endl;
    
    return 0;
}
