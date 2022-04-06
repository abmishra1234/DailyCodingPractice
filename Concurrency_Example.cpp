/*
	Concurrency Example using Multi Threading
*/
#define FORREF
#ifndef FORREF
using namespace std;

#include<iostream>
#include<vector>
#include<thread>


volatile int counter = 0;
int loops;

void worker(int loops) {
	cout << "Enter : worker with loops = " << loops << endl;
	int i;
	for (int i = 0; i < loops; ++i) {
		counter++;
	}
	cout  <<  "Exit from worker!!" << endl;
}

// Driver code
int main() {
	loops = 100;
	cout << "Pre----->Value of counter = " << counter << endl;
	thread t1(worker, loops);
	thread t2(worker, loops);
	t1.join();
	t2.join();
	cout << "Post--->Value of counter = " << counter << endl;
}

#endif // !FORREF




