/*
1169. Invalid Transactions
Medium

A transaction is possibly invalid if:
- the amount exceeds $1000, or;
- if it occurs within (and including) 60 minutes of another transaction
  with the same name in a different city.

Each transaction string transactions[i] consists of comma separated values
representing the name, time (in minutes), amount, and city of the transaction.

Given a list of transactions, return a list of transactions that are possibly invalid.
You may return the answer in any order.

Example 1:
Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs
within a difference of 60 minutes, have the same name and is in a different city.
Similarly the second one is invalid too.

Example 2:
Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
Output: ["alice,50,1200,mtv"]

Example 3:
Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
Output: ["bob,50,1200,mtv"]
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

struct Transaction {
    int time, amount;
    string city;
    bool included;
};

struct Record {
    vector<Transaction> trans;
};

class Solution {
public:
    void insert(const string& name, Transaction& tr)
    {
        tr.included = true;
        ostringstream ss;
        ss << name << "," << tr.time << "," << tr.amount << "," << tr.city;
        res.emplace_back(ss.str());
    }

    void process_record(const string& name, Record& record)
    {
        sort(begin(record.trans), end(record.trans), [](auto& tr1, auto& tr2) { return tr1.time < tr2.time; });
        map<string, int> cities;
        for (int head = 0, tail = 0; head < static_cast<int>(record.trans.size()); ++head) {
            while (tail < head && record.trans[head].time - record.trans[tail].time > 60) {
                const string& city = record.trans[tail].city;
                if (--cities[city] == 0)
                    cities.erase(city);
                ++tail;
            }
            auto& tran = record.trans[head];
            if (tran.amount > 1000)
                insert(name, tran);
            ++cities[tran.city];
            if (cities.size() > 1) {
                for (int i = tail; i <= head; ++i) {
                    auto& tr = record.trans[i];
                    if (!tr.included) {
                        insert(name, tr);
                    }
                }
            }
        }
    }

    vector<string> invalidTransactions(vector<string>& transactions)
    {
        records.clear();
        res.clear();
        string name, temp, city;
        int time, amount;
        for (auto& tr : transactions) {
            istringstream ss(tr);
            getline(ss, name, ',');
            getline(ss, temp, ',');
            time = stoi(temp);
            getline(ss, temp, ',');
            amount = stoi(temp);
            getline(ss, city, ',');
            records[name].trans.emplace_back(Transaction{time, amount, city, false});
        }

        for (auto& p : records)
            process_record(p.first, p.second);

        return res;
    }

    map<string, Record> records;
    vector<string> res;
};

int main()
{
    Solution sol;
    vector<string> transactions, res;

    // Output: ["alice,20,800,mtv","alice,50,100,beijing"]
    transactions = {"alice,20,800,mtv", "alice,50,100,beijing"};

    // Output: ["alice,50,1200,mtv"]
    // transactions = {"alice,20,800,mtv","alice,50,1200,mtv"};

    // Output: ["bob,50,1200,mtv"]
    // transactions = {"alice,20,800,mtv","bob,50,1200,mtv"};

    // Output: []
    // transactions = {"alice,0,800,mtv","alice,0,800,mtv","alice,0,800,mtv","alice,0,800,mtv"};

    // Output: []
    // transactions = {"alice,0,800,mtv","alice,1,800,mtv","alice,2,800,mtv","alice,60,800,mtv","alice,61,800,mtv"};

    // Output:
    // ["alice,0,800,berlin","alice,0,800,berlin","alice,1,800,paris","alice,2,800,london","alice,60,800,newyork","alice,61,800,chicago"]
    // transactions =
    // {"alice,0,800,berlin","alice,0,800,berlin","alice,1,800,paris","alice,2,800,london","alice,60,800,newyork","alice,61,800,chicago"};

    // Output: ["bob,656,1366,bangkok","alex,596,1390,amsterdam"]
    transactions = {"alex,676,260,bangkok", "bob,656,1366,bangkok", "alex,393,616,bangkok", "bob,820,990,amsterdam",
            "alex,596,1390,amsterdam"};

    res = sol.invalidTransactions(transactions);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
