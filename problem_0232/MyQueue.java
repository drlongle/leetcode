/*
232. Implement Queue using Stacks

Implement the following operations of a queue using stacks.
    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.

Notes:
    You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
    You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

import java.io.*;
import java.util.*;

class MyQueue {
    MyQueue() {
        m_front = new ArrayDeque<>();
        m_back = new ArrayDeque<>();
    }

    // Push element x to the back of queue.
    public void push(int x) {
        m_back.addLast(x); 
    }

    // Removes the element from in front of queue.
    public void pop() {
        if (m_front.isEmpty()) {
            while (!m_back.isEmpty())
                m_front.addLast(m_back.removeLast());
        }
        m_front.removeLast();
    }

    // Get the front element.
    public int peek() {
        if (m_front.isEmpty()) {
            while (!m_back.isEmpty())
                m_front.addLast(m_back.removeLast());
        }
        return m_front.peekLast();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return m_front.isEmpty() && m_back.isEmpty();
    }

    Deque<Integer> m_front;
    Deque<Integer> m_back;
}

