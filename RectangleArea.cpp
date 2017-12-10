class Solution {
    public:
        int computeRectArena(int A, int B, int C, int D) {
            if (C < A || D < B) return 0;
            return (C - A) * (D - B);
        }
        int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
            int sum = 0;
            sum = computeRectArena(A, B, C, D) + computeRectArena(E, F, G, H);
            sum -= computeRectArena(max(A, E), max(B, F), min(C, G), min(D, H));
            return sum;      
        }
};
