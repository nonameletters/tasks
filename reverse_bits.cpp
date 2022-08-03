class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t left = 0x80000000;
        uint32_t right = 0x00000001;
        size_t s = sizeof(n) * 8;
        
        for (size_t i = 0; i < s /2; i++)
        {
            uint32_t lval = n & left;
            uint32_t rval = n & right;
            n = n & (~left) & (~right);          
            lval = lval >> (s - (2*i) - 1); // Be carefull. i is multiplying by two to get the right position.
            rval = rval << (s - (2*i) - 1);
            n = n | lval | rval;
            left >>= 1;
            right <<= 1;
            // printf("// --------\n");
        }
        return n;
    }
};
