class Solution {
public:
    double findKth(vector<int> *nums1, int L1, int R1, vector<int> *nums2, int L2, int R2, int k) {
        if (L1 > R1) return (*nums2)[L2 + k - 1];
        if (L2 > R2) return (*nums1)[L1 + k - 1];
        int M1 = (L1 + R1) / 2;
        int M2 = (L2 + R2) / 2;
        if ((*nums1)[M1] >= (*nums2)[M2]) {
            swap(nums1, nums2);
            swap(L1, L2);
            swap(R1, R2);
            swap(M1, M2);
        }
        int cnt = M1 - L1 + 1 + M2 - L2 + 1;
        if (k >= cnt) {
            return findKth(nums1, M1 + 1, R1, nums2, L2, R2, k -= M1 - L1 + 1);
        } else {
            return findKth(nums1, L1, R1, nums2, L2, M2 - 1, k);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum_len = nums1.size() + nums2.size();
        if (sum_len == 0) return 0.0;
        double ans = 0.0;
        if (sum_len % 2 == 1) {
            ans = findKth(&nums1, 0, nums1.size() - 1, &nums2, 0, nums2.size() - 1, sum_len / 2 + 1);
        } else {
            ans = findKth(&nums1, 0, nums1.size() - 1, &nums2, 0, nums2.size() - 1, sum_len / 2);
            ans += findKth(&nums1, 0, nums1.size() - 1, &nums2, 0, nums2.size() - 1, sum_len / 2 + 1);
            ans /= 2.0;
        }
        return ans;
    }
};