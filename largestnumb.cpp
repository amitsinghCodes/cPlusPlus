/*
 * largestnumb.cpp
 *
 *  Created on: May 24, 2025
 *      Author: 333am
 */

#include<iostream>

using namespace std;

int main(){
	
	int arr[5] = {1,2,3,6,8};
	int largest = arr[0];
	
	for(int i = 1; i<sizeof(arr); i++){
		if(arr[i]>=largest){
			largest = arr[i];
		}
	}
    cout << "The largest number is: " << largest << endl;
    return 0;
}


