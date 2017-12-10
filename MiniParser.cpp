/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    public:
        NestedInteger deserialize(string s) {
            int pos = 0;
            return deserialize(s, pos);
        }
        NestedInteger deserialize(string s, int &pos) {
            // number
            if (s[pos] == '-' || isdigit(s[pos])) {
                int start = pos;
                while (s[pos] == '-' || isdigit(s[pos])) pos++;
                return NestedInteger(stoi(s.substr(start, pos - start)));
            }
            // list
            pos++; // skip [
            NestedInteger ret;
            while (s[pos] != ']') {
                if (s[pos] == ',') pos++;
                ret.add(deserialize(s, pos));
            }
            pos++; // skip ]
            return ret;
        }
};
