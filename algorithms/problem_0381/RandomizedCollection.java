/*
381. Insert Delete GetRandom O(1) - Duplicates allowed

    Total Accepted: 850
    Total Submissions: 2657
    Difficulty: Hard

Design a data structure that supports all following operations in average O(1)
time. Note: Duplicate elements are allowed.

    insert(val): Inserts an item val to the collection.
    remove(val): Removes an item val from the collection if present.
    getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.

Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();

*/

import java.io.*;
import java.util.*;

public class RandomizedCollection {

    /** Initialize your data structure here. */
    public RandomizedCollection() {
        m_entries = new ArrayList<>();
        m_lookup = new HashMap<>();
        m_random = new Random();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        boolean res = (m_lookup.containsKey(val) == false);
        NavigableSet<Integer> set;
        if (res) {
            set = new TreeSet<Integer>();
            m_lookup.put(val, set);
        } else
            set = m_lookup.get(val);
        set.add(m_entries.size());
        m_entries.add(val);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        if (!m_lookup.containsKey(val))
            return false;
        NavigableSet<Integer> set1 = m_lookup.get(val);
        int index1 = set1.pollLast();
        int index2 = m_entries.size()-1;
        if (index1 != index2) {
            int val2 = m_entries.get(index2);
            NavigableSet<Integer> set2 = m_lookup.get(val2);
            set2.pollLast();
            m_entries.set(index1, val2); // Line 33: java.lang.IndexOutOfBoundsException: Index: 4, Size: 3
            set2.add(index1);
        }
        m_entries.remove(index2);
        if (set1.isEmpty())
            m_lookup.remove(val);
        return true;
    }
    
    /** Get a random element from the collection. */
    public int getRandom() {
        int array_size = m_entries.size();
        if (array_size == 0) return 0;
        int index = Math.abs(m_random.nextInt()) % array_size;
        return m_entries.get(index);
    }

    List<Integer> m_entries;
    HashMap<Integer, NavigableSet<Integer>> m_lookup;
    Random m_random;

    public static void main(String[] args) {
        NavigableSet<Integer> set = new TreeSet<>();
        set.add(2);
        set.add(3);
        set.add(1);
        set.add(2);
        System.out.println("pollLast: " + set.pollLast());
        System.out.println("pollLast: " + set.pollLast());
        System.out.println("pollLast: " + set.pollLast());
        System.out.println("size: " + set.size());
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

