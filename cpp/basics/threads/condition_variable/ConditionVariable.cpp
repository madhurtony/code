// ConditionVariable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>
#include<thread>
#include<mutex>

using namespace std;

mutex m{};

condition_variable cv{};
bool startDeque{ false };
bool processingComplete{ false };

void dowork(queue<int>& q) 
{
	cout << "dowork started and waiting for data" << endl;
	{
		// mutex is locked below
		std::unique_lock<mutex> lk{ m };

		// Worker thread starts, unlocks the mutex and starts waiting for other thread to notify
		// When main thread notifies by executing cv.notify(), thread will lock mutex, check the condition, exit the wait and start processing further
		cv.wait(lk, []() {return startDeque; });

		cout << "startDeque is true, starting dequeue now" << endl;

		while (!q.empty()) {
			cout << q.front() << endl;
			q.pop();
		}

		// mutex will be unlocked now after lk goes out of scope
	}
	
	{
		// mutex is locked now
		std::unique_lock<mutex> lk(m);
		processingComplete = true;
		// main thread is notified
		cv.notify_one();
	}
}

int main()
{
	queue<int> q{};
	thread workerthread{ dowork , std::ref(q)};

	// Main thread will add elements to queue and then notify the worker thread to start dequeuing
	for (int count = 0; count < 10; ++count) {
		cout << count << endl;
		q.emplace(count);
		this_thread::sleep_for(std::chrono::seconds(1));
	}
	{
		std::lock_guard<mutex> lk(m);
		startDeque = true;
	}
	// notifying the worker thread to start dequeue process
	cv.notify_one();

	{
		std::unique_lock<mutex> lk(m);
		cv.wait(lk, []() {return processingComplete; });

		if (q.empty()) cout << "Queue is empty now, processing was completed by worker thread" << endl;
		else cout << "Queue is not empty, worker thread did not complete the work" << endl;
	}

	workerthread.join();
}

