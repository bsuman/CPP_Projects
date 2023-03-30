/*
You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks,
where tasks[i] = [enqueueTimei, processingTimei] means that
the i​​​​​​th​​​​ task will be available to process at enqueueTimei
and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time
and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks,
the CPU will choose the one with the shortest processing time.
If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <array>
#include <algorithm>
using namespace std;

vector<int> getOrder(vector<vector<int>>& tasks) {
	// output list with correct order of task execution
	vector<int> output_order = {};
	// each entry in the list is an array of [enquetime_i,processingtime_i,index_i] for ith task
	vector<array<int, 3>> task_info;

	auto it = begin(tasks);
	auto end_it = end(tasks);
	int index = 0;
	while (it != end_it) {
		vector<int> task(*it);
		array<int, 3> tmp{ task[0],task[1], index };
		task_info.push_back(tmp);
		index++;
		it++ ;
	}
	// sort the tasks based on the enqueue time 
	sort(task_info.begin(), task_info.end());
	// heap to store the processing time and index of the tasks in an ascending order
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> heap_tasks;
	// starting with the task which arrives first
	int currTaskInd = 0;
	long int currTime = 0;
	// do until all tasks are processed 
	while (currTaskInd < tasks.size()|| !heap_tasks.empty())
	{
		// if no available tasks and current time is less than the next task to be executed
		if (heap_tasks.empty() && currTime< task_info[currTaskInd][0]) {
			// jump to the time when the task becomes available
			currTime = task_info[currTaskInd][0];
			
		}
		// for all tasks that arrive before the current time, 
		// enqueue the tasks in ascending order of the processing time in the heap 
		while (currTaskInd < task_info.size() && currTime>= task_info[currTaskInd][0])
		{
			heap_tasks.push({ task_info[currTaskInd][1],task_info[currTaskInd][2] });
			currTaskInd++;
		}
		// pop the first task available with the minimum processing time 
		pair<int, int> nextTask = heap_tasks.top();
		// update the current time to include the processing time of the chosen task
		currTime += nextTask.first;
		// add the index of the task which was processed to the output list
		output_order.push_back(nextTask.second);
		// remove the task from the heap as it has been processed 
		heap_tasks.pop();
	}
	return output_order;
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
