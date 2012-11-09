#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;


int main ()
{
    int n, m;
    cin >> n >> m;
    
    int edge[m][2];
    for (int i = 0; i < m; i ++) {
        cin >> edge[i][0] >> edge[i][1];
    }
    
    int vCount[n+1];
    for (int i = 1; i <= n; i ++) {
        vCount[i] = 1;
    }
    
    for (int i = 0; i < m; i ++) {
        vCount[ edge[i][1] ] = 0;
    }
    
    queue<int> pq;
    
    for (int i = n; i >= 1; i --) {
        if (vCount[i] == 0) {
            pq.push(i);
            int total = 0;
            
            while (!pq.empty()) {
                int first = pq.front();
                pq.pop();
                
                bool flag = false;
                if (vCount[first] > 0) {
                    total += vCount[first];
                    flag = true;
                } else {
                    total ++;
                }
                
                if (flag == false) {
                    for (int ii = 0; ii < m;  ii ++) {
                        if (edge[ii][1] == first) {
                            pq.push(edge[ii][0]);
                        }
                    }
                }
            }
            
            vCount[i] = total;
        }
    }
    
    int ans = 0;
    for (int i = 2; i <= n; i ++) {
        if (vCount[i] % 2 == 0) {
            ans ++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}