
class Solution {
public:
  int distinctEchoSubstrings(string const& text) {
    SSIDStore ssids = constructSubstringIdentifiers(text);
    return distinctEchoSubstrings(text, ssids);
  }

private:
  /////////// Types ///////////
  
  struct Trie {
    array<Trie*, 26> children_ {};
    Trie* append(char c) { return children_[c-'a'] ? children_[c-'a'] : (children_[c-'a'] = new Trie); }
    // ~Trie() { for (Trie* child : children_) delete child; } // cleaning up adds about 350ms to the runtime
  };
  
  using SSID      = uint64_t;             // Substring ID
  using SSIDStore = vector<vector<SSID>>; // index → length → id
  
  /////////// Functions ///////////
  
  /* For every relevant substring, assign a unique number derived from a Trie address: O(n²) */
  static SSIDStore constructSubstringIdentifiers(string const& text) {
    int const N = text.size();
    SSIDStore result(N, vector<SSID>(N/2+1));
    Trie root;
    for (int l = 0; l < N; ++l) {
      Trie* node = &root;
      int const maxLen = max(min(l, N-l), (N-l)/2);
      for (int len = 1; len <= maxLen; ++len) {
        node = node->append(text[l+len-1]);
        result[l][len] = (SSID)node; // interpret memory address as integer
      }
    }
    return result;
  }
  
  /* Count the number of distinct echo substrings: O(n²) */
  static int distinctEchoSubstrings(string const& text, SSIDStore const& ssids) {
    int const N = text.size();
    unordered_set<SSID> found;
    for (int l = 0; l < N; ++l)
      for (int len = 1; len <= (N-l)/2; ++len)
        if (ssids[l][len] == ssids[l+len][len])
          found.insert(ssids[l][len]);
    return found.size();
  }
};
