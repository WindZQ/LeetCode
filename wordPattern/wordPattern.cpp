#include <unordered_map>
#include <string>
#include <vector>

#define method1 1
#define method2 0

class Solution
{
public:
#if method1
	bool wordPattern(std::string pattern, std::string s)
	{
		std::unordered_map<char, std::string> hash_ps;
		std::unordered_map<std::string, char> hash_sp;
		
		int n = s.size();
		int start = 0;
		
		for (auto ch : pattern)
		{
			if (start >= n) return false;
			
			int end = start;
			while (end < n && s[end] != ' ') ++end;
			std::string word = s.substr(start, end - start);
			if (hash_ps.count(ch) && hash_sp[word] != ch) return false;
			if (hash_sp.count(word) && hash_ps[ch] != word)  return false;
			
			hash_ps[ch] = word;
			hash_sp[word] = ch;
			start = end + 1;
		}
		
		return start >= n;
	}
#endif

#if method2
	bool wordPattern(std::string pattern, std::string s)
	{
		std::vector<std::string> str;
		std::stringstream iss(s);
		std::string word;
		while (iss >> word) str.push_back(word);
		if (str.size() != pattern.size()) return false;
		
		std::unordered_map<char, std::string> hash_ps;
		std::unordered_map<std::string, char> hash_sp;
		
		for (int i = 0; i < pattern.size(); ++i)
		{
			auto a = pattern[i];
			auto b = str[i];
			if (hash_ps.count(a) && hash_ps[a] != b) return false;
			hash_ps[a] = b;
			if (hash_sp.count(b) && hash_sp[b] != a) return false;
			hash_sp[b] = a;
		}
		
		return true;
	}
#endif
};