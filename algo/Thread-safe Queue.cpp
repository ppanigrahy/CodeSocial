/*
Implement a circular queue of integers of user-specified size using a
simple array. Provide routines to initialize(), enqueue() and dequeue() the queue. Make
it thread safe. Please implement this with your own code and do not use any class
libraries or library calls.
*/

// link to test : http://ideone.com/G8JmXa

#include<iostream>
#include<pthread.h>
 
#define DEF_SIZE 100
 
class circularQueue{
 private:
    int *m_queue;
    int p_head;
    int p_tail;
    int m_cap;
    int size;
    pthread_mutex_t mp = PTHREAD_MUTEX_INITIALIZER; 
 
 public:
        circularQueue(int sz)
        {
            size = sz;
            // in case a user passes size as a -ve num
            if(size<0)
                size = DEF_SIZE ;
            
            m_queue = new int[size];
            p_head = 0;
            p_tail = -1;
            m_cap = 0;
            pthread_mutex_init(&mp,NULL);
        }
    
        bool enqueue(int x)
        {
            bool res = false;
            pthread_mutex_lock(&mp);
            if(m_cap < size)
            {
                m_queue[(++p_tail)%size] = x;
                ++m_cap;
                res = true;
            }
            pthread_mutex_unlock(&mp);
            return res;
        }
        
        int dequeue()
        {
            int top;
            pthread_mutex_lock(&mp);
            /*empty queue*/
            if(m_cap == 0)
            {   
                pthread_mutex_unlock(&mp);
                throw("empty queue!");
            }
            else{
                top = m_queue[p_head];    
                p_head = (p_head+1)%size;
                                --m_cap;
            }
            pthread_mutex_unlock(&mp);
            return top;
        }    
        virtual ~circularQueue()
        {
            delete[] m_queue;
            m_queue = NULL;
            pthread_mutex_destroy(&mp);
        }
};
