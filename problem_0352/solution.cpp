/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: longb
 *
 * Created on 25. November 2018, 11:27
 */

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/*
Problem 352. Data Stream as Disjoint Intervals
Difficulty: Hard

Given a data stream input of non-negative integers a1, a2, ..., an, ...,
summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ...,
then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small
compared to the data stream's size?
*/

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Node {
    static constexpr size_t max_children = 8;
    Node(int s, int e, bool r = false): start(s), end(e), is_root(r) {}

    void split() {
        Node* left = new Node(start, end);
        Node* right = new Node(start, end);
        for (size_t i = 0; i < children.size(); ++i) {
            if (i < (max_children >> 1))
                left->children.push_back(children[i]);
            else
                right->children.push_back(children[i]);
        }
        left->end = left->children.back()->end;
        right->start = right->children.front()->start;
        children.resize(0);
        children.push_back(left);
        children.push_back(right);
    }

    void merge() {
        auto it = children.begin();
        int i = 0;
        while (i < children.size() -1) {
            auto& curr = children[i];
            auto& next = children[i+1];
            if (curr->end + 1 == next->start) {
                if (curr->children.empty() && next->children.empty()) {
                    next->start = curr->start;
                    children.erase(children.begin()+i);
                } else {
                    vector<Node*> temp;
                    for (int j = 0; j < 2; ++j) {
                        auto& node = children[i];
                        if (node->children.empty()) {
                            temp.push_back(new Node(node->start, node->end));
                        } else {
                            temp.insert(temp.end(), node->children.begin(),
                                node->children.end());
                        }
                        children.erase(children.begin()+i);
                    }
                    children.insert(children.begin()+i, temp.begin(), temp.end());
                }
            } else
                ++i;
        }
    }
    void addNum(int val) {
        if (!is_root && children.empty())
            return;
        if (is_root) {
            if (val < start)
                start = val;
            if (val > end)
                end = val;
        }

        bool inserted = false;
        for (auto it = children.begin(); it != children.end(); ++it) {
            auto& child = *it;
            if (val < child->start) {
                children.insert(it, new Node(val, val));
                inserted = true;
                break;
            } else if (child->start <= val && child->end >= val) {
                child->addNum(val);
                inserted = true;
                break;
            }
	}
        if (!inserted)
            children.push_back(new Node(val, val));
        merge();
    	if (children.size() > max_children) {
            split();
	}
    }

    void getIntervals(vector<Interval>& intervals) {
        if (children.empty()) {
            intervals.emplace_back(start, end);
        } else {
            for (auto& child: children) {
                child->getIntervals(intervals);
            }
        }
    }

    // Invariant that we have for a node:
    // If a nodes does not have a child, then the node covers the
    // entire range [start, end]. Otherwise, a node must have some
    // children.
    int start, end;
    bool is_root;
    vector<Node*> children;
};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() : root(Node(numeric_limits<int>::max(), numeric_limits<int>::min(), true)) {

    }

    void addNum(int val) {
        root.addNum(val);
    }

    vector<Interval> getIntervals() {
        vector<Interval> res;
        root.getIntervals(res);
        return res;
    }

    Node root;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

void print_vector(const vector<Interval>& intervals)
{
    for (auto& interval: intervals)
        cout << "[ " << interval.start << ", " << interval.end << " ]" << endl; 
}

void test_case_1()
{
    SummaryRanges sr;
    cout << "Execuging test case 1" << endl;
    
    sr.addNum(1);
    print_vector(sr.getIntervals());
    cout << "----" << endl;

    sr.addNum(3);
    print_vector(sr.getIntervals());
    cout << "----" << endl;

    sr.addNum(7);
    print_vector(sr.getIntervals());
    cout << "----" << endl;

    sr.addNum(2);
    print_vector(sr.getIntervals());
    cout << "----" << endl;

    sr.addNum(6);
    print_vector(sr.getIntervals());
}

void test_case_2()
{
    vector<int> nums{49,97,53,5,33,65,62,51,100,38,61,45,74,27,64,17,36,17,96,
            12,79,32,68,90,77,18,39,12,93,9,87,42,60,71,12,45,55,40,78,81,26,70,
            61,56,66,33,7,70,1,11,92,51,90,100,85,80,0,78,63,42,31,93,41,90,8,24,
            72,28,30,18,69,57,11,10,40,65,62,13,38,70,37,90,15,70,42,69,26,77,
            70,75,36,56,11,76,49,40,73,30,37,23,};
    SummaryRanges sr;
    for (auto& n: nums)
        sr.addNum(n);
}

void test_case_3()
{
    vector<int> nums {6,6,0,4,8,7,6,4,7,5};
    SummaryRanges sr;
    for (auto& n: nums)
        sr.addNum(n);
    print_vector(sr.getIntervals());
}

void test_case_4()
{
    vector<int> nums{49,97,53,5,33,65,62,51,100,38,61,45,74,27,64,17,36,17,96,12,79,32,68,90,77,18,39,12,93,9,87,42,60,71,12,45,55,40,78,81,26,70,61,56,66,33,7,70,1,11,92,51,90,100,85,80,0,78,63,42,31,93,41,90,8,24,72,28,30,18,69,57,11,10,40,65,62,13,38,70,37,90,15,70,42,69,26,77,70,75,36,56,11,76,49,40,73,30,37,23,};
    SummaryRanges sr;
    for (auto& n: nums) {
        sr.addNum(n);
        cout << "--------------- adding " << n << endl;
        print_vector(sr.getIntervals());
    }
    print_vector(sr.getIntervals());
}

int main(int argc, char** argv) {

    test_case_5();

    return 0;
}

