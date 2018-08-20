#ifndef PRIORITY_QUEUE_HEAP_H
#define PRIORITY_QUEUE_HEAP_H

template <class T>
class priority_queue_heap {
public:
	
	static const int CAPACITY = 30;
	
    priority_queue_heap(){ used = 0; }
	
	
    bool is_empty() const{ return (used == 0); }

    bool is_full() const{ return (used == 30); }

    /**
     * Remove the largest value from this priority queue and return it.
     *
     * Precondition: priority queue is not empty.
     */
    T remove();
	
    /**
     * Inserts the 'value' into the priority queue.
     *
     * Precondition: priority queue is not full
     */
    void insert(const T& value);
	
	void print();
	
private:
    T data[CAPACITY];
	int used;
};

#include "priority_queue_heap.template"


#endif // PRIORITY_QUEUE_HEAP_H
