class Solution {
public:
    string similarRGB(string color) {
        for(int i = 0 ; i < 3 ;i++){ // split the string into 3 pieces
            string segment = color.substr(1+i*2,2);
            int digit = isdigit(segment[0])?(segment[0]-'0'):(segment[0]-'a'+10); // get 0~15
            int min_val = INT_MAX, target_ascii = 0;
            for(int j = -1 ; j <= 1 ; j++){ // only offset -1, 0, +1 matters
                int current_digit = digit+j;
                if(current_digit > 15 || current_digit < 0) continue;
                int diff = abs(stoi(segment,nullptr,16)-(current_digit*17)); // current_digit*16 + current_digit
                if(diff < min_val)
                    target_ascii = current_digit, min_val = diff;
            }
            color[1+2*i] = color[1+2*i+1] = target_ascii+((target_ascii < 10)?'0':('a'-10)); // in-place change
        }
        return color;
    }
};
