#include "UserDatabase.h"

void UserDataBase::inputUsers(vector<Review> reviewVec) {	// class function to parse reviews from input file
	int temp = reviewVec.begin()->userID;	// keep track of the last unique userID
	int counter = 0; // to keep track of the number of reviews for each user
	for (auto c : reviewVec) {	// for all reviews
		if (temp != c.userID) {	// check if unique userID
			User user(temp, counter);	//	create new user object
			this->userVec.push_back(user);	// push it into the vector of users
			counter = 1; // reset the counter
			temp = c.userID;	// reset the last unique userID 
		}
		else
		{
			counter++;	// increment the no of reviews for each user
		}
	}
	User user(reviewVec.end()->userID, counter);	// create the last user
	this->userVec.push_back(user);	// push the last user into the vector of users
}