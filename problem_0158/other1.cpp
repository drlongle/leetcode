class Solution {
public:
    char buf4[4];
    int buf4_ct{0};
    int buf4_fp{0};
    int read(char *buf, int n) {
        int bytes_read = 0;
        if(n == 0) return bytes_read;

        int fp = 0;
        while(n >= 0) {
            while(buf4_ct > buf4_fp && n > 0) {
                buf[fp++] = buf4[buf4_fp++];
                bytes_read++;
                n--;
            }
            if(n == 0) break;
            buf4_ct = read4(buf4);
            if(buf4_ct == 0) break;
            buf4_fp = 0;
        }

        return bytes_read;
    }
};
