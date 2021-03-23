class Solution {
public:
    bool checkIsPalindromePermutePossible(map<char,int> &mapOfAllCharacter)
    {
        int countOfOdd = 0;
        for_each(mapOfAllCharacter.begin(),mapOfAllCharacter.end(),[&](auto element) mutable {if(element.second%2 == 1){countOfOdd++;}});
        return (countOfOdd < 2);
    }

    vector<string> getFirstHalf(map<char,int> &mapOfAllCharacter)
    {
        vector<string> v;
        string initialPermutation = "";
        for_each(mapOfAllCharacter.begin(),mapOfAllCharacter.end(),[&](auto element) mutable{
            string ans = "";
            int kTimes = element.second/2;
            while(kTimes--)
            {
                ans += element.first;
            }
            initialPermutation += ans;
        });
        do {
            v.push_back(initialPermutation);
        } while ( std::next_permutation(initialPermutation.begin(),initialPermutation.end()) );
        return v;
    }

    char getOddElement(map<char,int> &mapOfAllCharacter)
    {
        char result = ' ';
        for_each(mapOfAllCharacter.begin(),mapOfAllCharacter.end(),[&](auto element) mutable {if(element.second%2 == 1){result = element.first;}});
        return (result);
    }

    vector<string> generatePalindromes(string s) {
        map<char,int> mapOfAllCharacter;
        for_each(s.begin(),s.end(),[&](char a) mutable { mapOfAllCharacter[a]++; });
        if(!checkIsPalindromePermutePossible(mapOfAllCharacter))
            return vector<string>();
        if(s.size()% 2 == 0)
        {
            vector<string> firstHalf = getFirstHalf(mapOfAllCharacter);
            transform(firstHalf.begin(),firstHalf.end(),firstHalf.begin(),[](string a ) {
                string reverseString = a;
                reverse(reverseString.begin(),reverseString.end());
                return a+reverseString;});
            return firstHalf;
        }
        else
        {
            char oddElement = getOddElement(mapOfAllCharacter);
            vector<string> firstHalf = getFirstHalf(mapOfAllCharacter);
            transform(firstHalf.begin(),firstHalf.end(),firstHalf.begin(),[=](string a ) { string reverseString = a;
                reverse(reverseString.begin(),reverseString.end());
                return a+oddElement+reverseString;});
            return firstHalf;
        }

    }
};
