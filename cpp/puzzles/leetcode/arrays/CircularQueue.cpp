//https://leetcode.com/problems/design-circular-queue/description/ 
// Medium
/*

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language.



Example 1:

Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4


Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.

*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class MyCircularQueue {
    private:
        int* queue{ nullptr };
        int rear{ -1 };
        int front{ 0 };
        int count_of_elements{ 0 };
        int queue_size{ 0 };
    public:
        MyCircularQueue(int k) {
            queue = new int[k];
            queue_size = k;
        }

        bool enQueue(int value) {
            if (count_of_elements == queue_size) return false;
            if (rear == queue_size - 1) rear = 0;
            else ++rear;
            queue[rear] = value;
            ++count_of_elements;
            return true;
        }

        bool deQueue() {
            if (count_of_elements == 0) return false;
            if (front == queue_size - 1) front = 0;
            else ++front;
            --count_of_elements;

            // Not really required but better to start from 0 if queue has become empty
            if (count_of_elements == 0) {
                rear = -1;
                front = 0;
            }
            return true;
        }

        int Front() {
            return (count_of_elements == 0 ? -1 : queue[front]);
        }

        int Rear() {
            return (count_of_elements == 0 ? -1 : queue[rear]);
        }

        bool isEmpty() {
            return count_of_elements == 0;
        }

        bool isFull() {
            return count_of_elements == queue_size;
        }
    };

    /**
     * Your MyCircularQueue object will be instantiated and called as such:
     * MyCircularQueue* obj = new MyCircularQueue(k);
     * bool param_1 = obj->enQueue(value);
     * bool param_2 = obj->deQueue();
     * int param_3 = obj->Front();
     * int param_4 = obj->Rear();
     * bool param_5 = obj->isEmpty();
     * bool param_6 = obj->isFull();
     */



int main()
{
    MyCircularQueue* myCircularQueue = new MyCircularQueue(3);
    assert(myCircularQueue->enQueue(1) == true); // return True
    assert(myCircularQueue->enQueue(2) == true); // return True
    assert(myCircularQueue->enQueue(3) == true); // return True
    assert(myCircularQueue->enQueue(4) == false); // return False
    assert(myCircularQueue->Rear() == 3);     // return 3
    assert(myCircularQueue->Rear() == 3);     // return 3

    assert(myCircularQueue->isFull() == true);   // return True
    assert(myCircularQueue->deQueue() == true);  // return True
    assert(myCircularQueue->enQueue(4) == true); // return True
    assert(myCircularQueue->enQueue(4) == false); // return True
    assert(myCircularQueue->Rear() == 4);     // return 4
}

