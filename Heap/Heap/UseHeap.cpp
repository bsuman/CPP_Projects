#include"MinHeap.h"
#include"MaxHeap.h"
#include<iostream>
#include<iterator>

void dummy_use_check()
{
	MinHeap<int> minH;
	minH.push(10);
	minH.push(12);
	minH.push(3);
	minH.push(30);
	minH.push(20);
	minH.push(1);
	int tmp_i = minH.pop();
	while (tmp_i != -1)
	{
		cout << "Popped Element " << tmp_i << endl;
		tmp_i = minH.pop();
	}
	cout << "===========MinHeap=============" << endl;
	MinHeap<double> minH_d;
	minH_d.push(1.2);
	minH_d.push(22.2);
	minH_d.push(3.1);
	minH_d.push(31.4);
	minH_d.push(2.1);
	minH_d.push(0);
	double tmp_d = minH_d.pop();
	while (tmp_d != -1)
	{
		cout << "Popped Element " << tmp_d << endl;
		tmp_d = minH_d.pop();
	}
	cout << "===========MaxHeap=============" << endl;
	MaxHeap<int> maxH;
	maxH.push(10);
	maxH.push(12);
	maxH.push(3);
	maxH.push(30);
	maxH.push(20);
	maxH.push(1);
	int tmp = maxH.pop();
	while (tmp != -1)
	{
		cout << "Popped Element " << tmp << endl;
		tmp = maxH.pop();
	}

}




/*
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi],
return the minimum number of conference rooms required.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Example 2:
Input: intervals = [[7,10],[2,4]]
Output: 1

*/


int minMeetingRooms(vector<vector<int>>& intervals)
{	
	MinHeap<int> start_time_minHeap, end_time_minHeap;
	auto it = begin(intervals);
	auto end_it = end(intervals);
	//Step 1: room allocation happens in the ascending order of the start time.
	// create a minHeap based on the start time.
	// create another minHeap based on the end time.

	while (it != end_it) {
		vector<int> meeting_times = *it;
		start_time_minHeap.push(meeting_times[0]);
		end_time_minHeap.push(meeting_times[1]);
		++it;
	}

	//Step 2:
	// for each element at the root of start_time_minHeap:
		// check if meeting_room available:
			//meeting room is availabel when : 
				// current meeting from the start_time_minHeap is starting later than the root of the end_time_minHeap

		// if meeting_room available: 
			// allocate the meeting room 
		// else: 
			// create meeting room and allocate the meeting room 
		

		// corner case: 
		// first meeting: always need to increment the needed room number by 1
		// last meeting: 
				// the arrival time is updated only when it's is not last the meeting
		        // for the last meeting, the arrival time is not updated
	
	int num_min_room(0), num_avail_room(0);
	int arrival_time = start_time_minHeap.pop();
	bool roomneeded(true);
	while (end_time_minHeap.peek() != -1) {
		if (arrival_time > -1 && arrival_time >= end_time_minHeap.peek()) {
			num_avail_room++;
			end_time_minHeap.pop();

		}
		else if (arrival_time == -1) {
			end_time_minHeap.pop();
			roomneeded = false;
		}
		if(roomneeded)
		{
			if (num_avail_room > 0) {
				num_avail_room--;
			}
			else {
				num_min_room++;
			}
			arrival_time = start_time_minHeap.pop();
		}
	}
	return num_min_room;
}

int main() {
	//vector<vector<int>> intervals{ {0,30}, {5, 10 },{15, 20} };
	vector<vector<int>> intervals{ {7, 10}, { 2, 4 },{3,6} };
	cout << "Minimum number of meeting rooms required are: " << minMeetingRooms(intervals) << endl;
	return 0;
}