//solution 1: find_kth by discarding half of (one of) the array(s) in each step

double find_kth(int * a, int n1, int * b, int n2, int k){
    if(n1 == 0)
        return b[k-1];
    if(n2 == 0)
        return a[k-1];
    if(k == 1)
        return a[0]<b[0]?a[0]:b[0];
    int amid = n1 / 2;
    int bmid = n2 / 2;
    if(a[amid] <= b[bmid]){
        if(amid + bmid + 1 >= k)
            return find_kth(a, n1, b, bmid, k);
        return find_kth(a+amid+1, n1-amid-1, b, n2, k-amid-1);
    }
    return find_kth(b, n2, a, n1, k);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int all = nums1Size + nums2Size;
    int k = all / 2 + 1;
    double ans = find_kth(nums1, nums1Size, nums2, nums2Size, k);
    if(all % 2)
        return ans;
    return (ans + find_kth(nums1, nums1Size, nums2, nums2Size, k-1)) / 2;
}



//Solution 2: find_kth by another smart idea
int inf = 0x7fffffff, ninf = 0x80000000;

double find_kth(int * a, int n, int * b, int m, int k){
    // basically that's the solution code.
    // I just copy and paste
    // This code is genius!
    #define A(i) (i < 1 ? ninf : (i > n ? inf : a[i - 1]))
    #define B(i) (i < 1 ? ninf : (i > m ? inf : b[i - 1]))
    int l = 0, r = n + 1, x;
    while(l <= r){
        x = (l + r) >> 1;
        if(A(x) > B(k - x + 1)) 
            r = x - 1;
        else{
            if(B(k - x) > A(x + 1)) 
                l = x + 1;
            else 
                return A(x) > B(k - x) ? A(x) : B(k - x);
        }
    }
    return 0;   //never execute , just to hide the warning :)
    #undef A
    #undef B
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int all = nums1Size + nums2Size;
    int k = all / 2 + 1;
    double ans = find_kth(nums1, nums1Size, nums2, nums2Size, k);
    if(all % 2)
        return ans;
    return (ans + find_kth(nums1, nums1Size, nums2, nums2Size, k-1)) / 2;
}