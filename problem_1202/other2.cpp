class Solution {
public:
    
    using graph = vector<vector<int>>;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
	const int n = size(s);
	graph g(n);
	for (const auto& vec : pairs)
	{
            g[vec.front()].push_back(vec.back());
            g[vec.back()].push_back(vec.front());
	}
	vector<int> component;
	vector<bool> processed(n, false);
	function<void(int)> dfs;
	dfs = [&](int v)
              {
                  component.push_back(v);
                  processed[v] = true;
                  for (int vertex : g[v])
                      if (!processed[vertex])
                          dfs(vertex);
              };
	for (int i = 0; i < n; ++i)
	{
            if (!processed[i])
            {
                component.clear();
                dfs(i);
                sort(begin(component), end(component));
                string s_part;
                for (int idx : component)
                    s_part += s[idx];
                sort(begin(s_part), end(s_part));
                for (int j = 0; j < size(s_part); ++j)
                    s[component[j]] = s_part[j];
            }
	}
	return s;
    }
};
