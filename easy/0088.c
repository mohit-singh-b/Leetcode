void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1, j = m + n - 1, k = n - 1;
    while (j >= 0) {
        if ((i >= 0) && (k >= 0)) {
            if (nums1[i] > nums2[k]) {
                nums1[j] = nums1[i];
                j--;
                i--;
            } else {
                nums1[j] = nums2[k];
                j--;
                k--;
            }
        } else if (i == -1) {
            
                nums1[j] = nums2[k];
                k--;
                j--;
        
        } else  {
            break;
        }
    }
}