#pragma once

using namespace std;

class Review {
public:
	int movieID, userID, rating;
	string reviewDate;

	Review(int movieID, int userID, int rating, string reviewDate) :
		movieID(movieID), userID(userID), rating(rating), reviewDate(reviewDate) {}
};