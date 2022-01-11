/**
    The answer should be represented as #XYZ, so the origin string should be #XXYYZZ
    All those string are as follows:
      1. 0x00 = 0                0*17
      2. 0x11 = 1 + 16 = 17      1*17
      3. 0x22 = 2 + 32 = 34      2*17
      4. 0x33 = 3 + 48 = 51      3*17
      5. 0x44 = 4 + 64 = 68      4*17
      6. 0x55 = 5 + 80 = 85      5*17
      ..........
      15. 0xff = 15 + 15*16 = 255 = 15*17

      we can calculate the origin number and divided 17, the answer should
      between the above formulas.
      for example if it is between 2 and 3, the next step is that we should decide
      whether we should choose 2 or 3
      for every formula:
        we need to find out the min diff between 2 and 3
*/

class Solution {
public:
    string similarRGB(string c)
    {
        string out{"#"};

        for(auto i{1}; i<size(c); i+=2)
        {
            auto [q, r] = div(stoi(c.substr(i,2), nullptr, 16), 17);
            out.append(2, (q += r>8) < 10 ? '0'+q : 'a'+q-10);
        };

        return out;
    }
};
