class Solution {
public:
    /*
    @param buf Destination buffer
    @param n   Number of characters to read
    @return    The number of actual characters read
    */
    class ReadIt
    {
    private:
        char buf[4];
        int index;
        int n;
    public:
        ReadIt()
        {
            index=0;
            n=0;
        }
        char next()
        {
            return buf[index++];
        }

        bool hasNext()
        {
            if(index==n)
            {
                n = read4(buf);
                index=0;
                return n!=0;
            }
            return index!=n;
        }
    };

    ReadIt it;

    int read(char* buf, int n)
    {
        int count = 0;
        while(count<n && it.hasNext())
        {
            buf[count++] = it.next();
        }
        return count;
    }
};
