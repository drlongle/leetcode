class Solution {
public:
	vector<string> findWords(vector<string>& words) {

		std::unordered_set<char>  dict1 = { 'q','w','e','r','t','y','u','i','o','p' };
		std::unordered_set<char>  dict2 = { 'a','s','d','f','g','h','j','k','l'};
		std::unordered_set<char>  dict3 = { 'z','x','c','v','b','n','m'};

		vector<string> res;

		for (auto &word : words)
		{
			bool d1 = true, d2 = true, d3 = true;

			for (auto ch : word)
			{
                ch = tolower(ch);
                unordered_set<char>::const_iterator it;
                it = dict1.find(ch);
				if (it == dict1.end()) d1 = false;
                
                it = dict2.find(ch);
				if (it == dict2.end()) d2 = false;
                
				it = dict3.find(ch);
				if (it == dict3.end()) d3 = false;
			}

			if (d1 || d2 || d3) res.push_back(word);
		}

		return res;
	}
};
