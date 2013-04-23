class Solution {
public:
    int getRainDropFromLeftToRight(int A[], int n) {
        if (n < 3) return 0;
        
        vector<int> sequence;
        sequence.push_back(0);
        int curr = A[0];
        
        for (int i = 1; i < n; i ++) {
            if (curr <= A[i]) {
                curr = A[i];
                sequence.push_back(i);
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < sequence.size() - 1; i ++) {
            int rainDrop = 0;
            for (int j = sequence[i] + 1; j < sequence[i + 1]; j ++) {
                rainDrop += A[sequence[i]] - A[j];
            }
            
            ans += rainDrop;
        }
        
        return ans;
    }
    
    int getTopRainDrop(int A[], int n) {
        if (n < 3) return 0;
        
        int maxHeight = -1, b = 0, e = n - 1;
        bool hasTop = false;
        for (int i = 0; i < n; i ++) {
            if (maxHeight < A[i]) {
                hasTop = false;
                maxHeight = A[i];
                b = i;
            } else if (maxHeight == A[i]) {
                hasTop = true;
                e = i;
            }
        } 
        
        int ans = 0;
        if (hasTop) {
            for (int i = b + 1; i < e; i ++) {
                ans += maxHeight - A[i];
            }
        }
        
        return ans;
    }
    
    void reverse(int A[], int n) {
        int b = 0, e = n - 1;
        while (b < e) swap(A[b ++], A[e --]);
    }
    
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int ans = getRainDropFromLeftToRight(A, n);
        reverse(A, n);
        ans += getRainDropFromLeftToRight(A, n);
        ans -= getTopRainDrop(A, n);
        
        return ans;
    }
};