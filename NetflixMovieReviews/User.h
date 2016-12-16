#pragma once

#include "UserDatabase.h"

class User {	// class to store a single user

public:
	int userID;		
	int reviews;	// to store the number of reviews a user has uploaded

	User(int userID, int reviews) : userID(userID), reviews(reviews)	{}
};