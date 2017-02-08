/*
 432. All O`one Data structure

    Difficulty: Hard

Implement a data structure supporting the following operations:

    Inc(Key) - inserts a new key with value 1. Or increments an existing key by 1.
    Dec(Key) - decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
    GetMaxKey() - returns one of the keys with maximal value.
    GetMinKey() - returns one of the keys with minimal value.

Challenge: Perform all these in O(1) time complexity.
*/

import java.io.*;
import java.util.*;

public class AllOne {

    /** Initialize your data structure here. */
    public AllOne() {
        lookup = new HashMap<>();
        reverseLookup = new TreeMap<>();
    }

    Map<String, Integer> lookup;
    TreeMap<Integer, Set<String>> reverseLookup;
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    public void inc(String key) {
        boolean newKey = !lookup.containsKey(key);
        int val;
        if (newKey)
        {
            lookup.put(key, 1);
            val = 1;
        }
        else
        {
            val = lookup.get(key);
            Set<String> oldSet = reverseLookup.get(val);
            oldSet.remove(key);
            if (oldSet.isEmpty())
                reverseLookup.remove(val);
            lookup.put(key, ++val);
        }
        if (!reverseLookup.containsKey(val))
            reverseLookup.put(val, new HashSet<String>());
        reverseLookup.get(val).add(key);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    public void dec(String key) {
        if (!lookup.containsKey(key))
            return;
        int val = lookup.get(key);
        Set<String> oldSet = reverseLookup.get(val);
        oldSet.remove(key);
        if (oldSet.isEmpty())
            reverseLookup.remove(val);
        if (--val == 0)
            lookup.remove(key);
        else
        {
            if (!reverseLookup.containsKey(val))
                reverseLookup.put(val, new HashSet<String>());
            reverseLookup.get(val).add(key);
            lookup.put(key, val);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    public String getMaxKey() {
        if (reverseLookup.isEmpty())
            return new String();
        Set<String> values = reverseLookup.lastEntry().getValue();
        if (values.isEmpty())
            return new String();
        return values.iterator().next();
    }
    
    /** Returns one of the keys with Minimal value. */
    public String getMinKey() {
        if (reverseLookup.isEmpty())
            return new String();
        Set<String> values = reverseLookup.firstEntry().getValue();
        if (values.isEmpty())
            return new String();
        return values.iterator().next();
    }

    public static void main(String[] args) {
        AllOne obj = new AllOne();
        obj.inc("hello");
        obj.inc("world");
        obj.inc("hello");
        obj.dec("world");
        obj.inc("hello");
        obj.inc("leet");
        System.out.println("max: " + obj.getMaxKey());
        obj.dec("hello");
        obj.dec("hello");
        obj.dec("hello");
        System.out.println("max: " + obj.getMaxKey());
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */


