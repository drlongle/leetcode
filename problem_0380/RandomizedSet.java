/*
380. Insert Delete GetRandom O(1)

    Total Accepted: 1366
    Total Submissions: 3999
    Difficulty: Medium

Design a data structure that supports all following operations in average O(1) time.

    insert(val): Inserts an item val to the set if not already present.
    remove(val): Removes an item val from the set if present.
    getRandom: Returns a random element from current set of elements.
               Each element must have the same probability of being returned.

Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 1 is the only number in the set, getRandom always return 1.
randomSet.getRandom();
*/

import java.io.*;
import java.util.*;

public class RandomizedSet {

    /** Initialize your data structure here. */
    public RandomizedSet() {
        m_entries = new ArrayList<>();
        m_lookup = new HashMap<>();
        m_random = new Random();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (m_lookup.containsKey(val)) return false;
        m_entries.add(val);
        m_lookup.put(val, m_entries.size()-1);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!m_lookup.containsKey(val)) return false;
        int index1 = m_lookup.get(val);
        int index2 = m_entries.size()-1;
        if (index1 < index2) {
            int val2 = m_entries.get(index2);
            m_entries.set(index1, val2);
            m_lookup.put(val2, index1);
        }
        m_lookup.remove(val);
        m_entries.remove(index2);
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        int array_size = m_entries.size();
        if (array_size == 0) return 0;
        int index = Math.abs(m_random.nextInt()) % array_size;
        return m_entries.get(index);
    }

    List<Integer> m_entries;
    HashMap<Integer, Integer> m_lookup;
    Random m_random;

    public static void main(String[] args) {
    	RandomizedSet randomSet = new RandomizedSet();
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
