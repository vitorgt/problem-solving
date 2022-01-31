class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        for (int i = 0; i < 16; i++) {
            bool most = n & (1 << (31 - i));
            bool least = n & (1 << i);
            if (most != least) {
                n = n ^ ((1 << (31 - i)) | (1 << i));
            }
        }
        return n;
    }
};
