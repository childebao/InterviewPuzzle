/*
 
 There are two int arrays, a[], b[], and a constant value C,
 find all pairs numbers that a[i] + b[j] = C
 
 1. In fun solve1(): 
 Time complexity: O(lenA * log(lenB)) if lenA <= lenB
 or O(lenB * log(lenA)) if lenA > lenB
 
 2. In fun solve2():
 Time complexity: O(lenA + lenB). So that it is O(lenB) if lenA <= lenB
 or O(lenA) if lenA > lenB
 
 So, if lenA and lenB is more or less the same and they are large enough,
 solve1() is poorer than solve2();
 On the other side, solve1() is more efficient than solve2()
 
 If there are too many duplicates in those two arrays, we could use solve3()
 and do some modification to solve2() to make it run.
 
 */


int lowerBound(int a[], int length, int target)
{
  int l = 0, r = length - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (a[mid] >= target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  
  if (a[l] == target) {
    return l;
  }
  
  return -1;
}

// O(lenA * log(lenB))
int solve1(int a[], int b[], int lenA, int lenB, int C)
{
  if (lenA > lenB) {
    return solve1(b, a, lenB, lenA, C);
  }
  
  int ans = 0;
  for (int i = 0; i < lenA; i ++) {
    int target = C - a[i];
    
    if (target > b[lenB - 1]) continue;
    if (target < b[0]) break;
    
    if (lowerBound(b, lenB, target) >= 0) ans ++;
  }
  
  return ans;
}

// O(n) - worst case: a[] = 1 2 3 4 5 6 100   b[] = 1 2 3 4 5 6 7 8 ... 50 100  C: 99
int solve2(int a[], int b[], int lenA, int lenB, int C)
{
  int ans = 0;
  int head = 0, tail = lenB - 1;
  
  while (head < lenA && tail >= 0) {
    if (a[head] + b[tail] > C) {
      tail --;
    } else if (a[head] + b[tail] < C) {
      head ++;
    } else {
      ans ++, head ++, tail --;
    }
  }
  return ans;
}


int upperBound(int a[], int length, int target)
{
  int l = 0, r = length - 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (a[mid] > target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  
  if (l > 0 && a[l - 1] == target) {
    return l - 1;
  } 
  
  return -1;
}

int solve3(int a[], int b[], int lenA, int lenB, int C)
{
  int ans = 0;
  for (int i = 0; i < lenA; i ++) {
    int target = C - a[i];
    
    int low = lowerBound(b, lenB, target);
    if (low != -1) {
      int up = upperBound(b, lenB, target);
      ans += (up - low + 1);
    }
  }
  
  return ans;
}
