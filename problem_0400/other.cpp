int findNthDigit(int n)
    {
        if (n < 10)
            return n;
	// determine which group the digit is in
	//Group 1: 1~9, group 2: 10~99,  group 3: 100~999, ...
        int powTen = 1;
        while (n > 9 * pow(10, powTen - 1) * powTen)
        {
            n -= 9 * pow(10, powTen - 1) * powTen;
            ++powTen;
        }
	//determine which number the digit in is
        int num = (n - 1) /powTen + pow(10, powTen - 1);
        string s = to_string(num);
	//return the digit we want
        return s[(n - 1) % powTen]- '0';
    }


