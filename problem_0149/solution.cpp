/*
149. Max Points on a Line
  
Total Accepted: 55462 Total Submissions: 390314 Difficulty: Hard

Given n points on a 2D plane, find the maximum number of points that
lie on the same straight line.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct MyPoint
{
    MyPoint(const Point& p, int i) : id(i)
    {
        point.x = p.x;
        point.y = p.y;
    }

    Point point;
    int id;
};

class Line
{
public:
    static int gcd(int A, int B)
    {
        if (A < 0) A = -A;
        if (B < 0) B = -B;
        if (!A || !B) return 1;
        if (B < A) swap(A, B);
        if (A == 1 || A == B || B%A == 0) return A;
        return gcd(A, B %A);
    }

    static Line get_canonical_line(Point& a, Point& b)
    {
        pair<int,int> slope;
        pair<int,int> y_intercept;
        int diff_x = b.x - a.x;
        int diff_y = b.y - a.y;
        if (diff_x < 0)
        {
            diff_x = - diff_x;
            diff_y = - diff_y;
        }
      
        if (diff_x != 0)
        {
            int divisor = gcd(diff_x, diff_y);
            diff_x /= divisor;
            diff_y /= divisor;
            if (diff_y) {
                slope = make_pair(diff_y, diff_x);
                y_intercept = make_pair(a.y*b.x - a.x*b.y, b.x - a.x);
                if (y_intercept.second < 0)
                {
                    y_intercept.first = - y_intercept.first;
                    y_intercept.second = - y_intercept.second;
                }
                if (y_intercept.first == 0)
                    y_intercept.second = 1;
                divisor = gcd(y_intercept.first, y_intercept.second);
                y_intercept.first /= divisor;
                y_intercept.second /= divisor;
            }
            else {
                slope = make_pair(0, 1);
                y_intercept = make_pair(0, b.y);
            }
        }
        else
        {
            slope = make_pair(1.0, 0.0);
            y_intercept = make_pair(0.0, a.x);
        }
        return Line(slope, y_intercept);
    }
   
    Line(const pair<int,int>& s, const pair<int,int>& intercept) :
        slope(s),
        y_intercept(intercept)
    {

    }
        
    pair<int,int> slope;
    pair<int,int> y_intercept;
};

class HashLine
{
public:
    int operator()(const Line& line) const
    {
        return hash<int>()(line.slope.first) ^ hash<int>()(line.slope.second)
            ^ hash<int>()(line.y_intercept.first)
            ^ hash<int>()(line.y_intercept.second);
    }
};

class CompareLine
{
public:
    bool operator()(const Line& lhs, const Line& rhs) const
    {
        return lhs.slope == rhs.slope && lhs.y_intercept == rhs.y_intercept;
    }
};

class HashMyPoint
{
public:
    int operator()(const MyPoint& mypoint) const
    {
        return hash<int>()(mypoint.point.x) ^
            hash<int>()(mypoint.point.y) ^ hash<int>()(mypoint.id);
    }
};

class ComparePoint
{
public:
    bool operator()(const Point& lhs, const Point& rhs) const
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

class CompareMyPoint
{
public:
    bool operator()(const MyPoint& lhs, const MyPoint& rhs) const
    {
        return lhs.point.x == rhs.point.x &&
            lhs.point.y == rhs.point.y && lhs.id == rhs.id;
    }
};
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<Line, unordered_set<MyPoint, HashMyPoint, CompareMyPoint>,
            HashLine, CompareLine> lines;

        size_t result = 0;
        ComparePoint cpoint;

        if (points.size() == 1) return 1;

        if (points.size() == 2 && cpoint(points[0], Point(0,0))
            && cpoint(points[1], Point(0,0)))
            return 2;

        for (int i = 0; i < static_cast<int>(points.size()); ++i)
        {
            for (int j = i+1; j < static_cast<int>(points.size()); ++j)
            {
                Line line = Line::get_canonical_line(points[i], points[j]);
                lines[line].emplace(points[i],i);
                lines[line].emplace(points[j],j);
                if (lines[line].size() > result)
                    result = lines[line].size();
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<Point> points;
    int result;
  
    //Expected: 3
    points = {{2,3},{3,3},{-5,3}}; 
    result = sol.maxPoints(points);
    cout << "Result: " << result << endl;
  
    return 0;
}

