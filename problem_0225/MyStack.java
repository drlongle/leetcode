/*
225. Implement Stack using Queues

 Implement the following operations of a stack using queues.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.

Notes:
    You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
    Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
    You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

import java.io.*;
import java.util.*;

class MyStack {

    MyStack() {
        m_queue = new LinkedList<>();
        m_temp_queue = new LinkedList<>();
    }

    // Push element x onto stack.
    public void push(int x) {
        m_queue.add(x);
    }

    // Removes the element on top of the stack.
    public void pop() {
        while (m_queue.size() > 1)
            m_temp_queue.add(m_queue.remove());
        m_queue.remove();
        Queue<Integer> temp = m_temp_queue;
        m_temp_queue = m_queue;
        m_queue = temp;
    }

    // Get the top element.
    public int top() {
        while (m_queue.size() > 1)
            m_temp_queue.add(m_queue.remove());
        int result = m_queue.element();
        if (!m_temp_queue.isEmpty()) {
            m_temp_queue.add(m_queue.remove());
            Queue<Integer> temp = m_temp_queue;
            m_temp_queue = m_queue;
            m_queue = temp;
        }
        return result;
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return m_queue.isEmpty();
    }

    Queue<Integer> m_queue;
    Queue<Integer> m_temp_queue;
}

