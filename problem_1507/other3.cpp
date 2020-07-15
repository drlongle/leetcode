class Solution
{
public:
	string reformatDate(string date);
};

string Solution :: reformatDate(string date)
{
	stringstream ss(date);

	int date_num;
    string waste, month, year;
	ss >> date_num >> waste >> month >> year;

	vector<string> m_coll = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

	int ind = find(m_coll.begin(), m_coll.end(), month) - m_coll.begin() + 1;

	string res = year;
	res += "-";

	if(ind < 10)
		res += "0";

	res += to_string(ind);

	res += "-";
	if(date_num < 10)
		res += "0";

	res += to_string(date_num);

	return res;
}