/*
I think that we first need to reduce K. Obviously, if K is large, we would move all zeros, ones, and so on to the front.
We can get positions of a given number in one scan, and we do it for each digit '0' - '9'. Note that we need to quit
as soon as the next smallest character cannot be moved to the front, and do brute-force for reduced K.
*/

class Solution
{
public:
    string minInteger(string num, int k)
    {
        string pre;
        preprocess(pre, num, k);
        while (k > 0 && !num.empty())
        {
            auto pos = 0;
            for (auto i = 1; i < num.size() && i <= k; ++i)
                if (num[i] < num[pos])
                    pos = i;
            pre += num[pos];
            k -= pos;
            num = num.substr(0, pos) + num.substr(pos + 1);
        }
        return pre + num;
    }
    void preprocess(string &pre, string &num, int &k)
    {
        for (auto n = '0'; n < '9'; ++n)
        {
            vector<int> pos;
            for (auto i = 0; i < num.size(); ++i)
                if (num[i] == n)
                    pos.push_back(i);
            if (!pos.empty() && k < pos[0])
                break;
            int cnt = 0;
            for (auto i = 0; i < pos.size() && pos[i] <= k + cnt; ++i)
            {
                k -= pos[i] - cnt;
                ++cnt;
            }
            pre += string(cnt, n);
            string num1;
            for (auto ch : num)
            {
                if (ch == n && cnt > 0)
                    --cnt;
                else
                    num1 += ch;
            }
            swap(num, num1);
        }
    }
};