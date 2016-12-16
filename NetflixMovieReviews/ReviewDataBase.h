#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Movie.h"
#include "Review.h"

using namespace std;

class ReviewDataBase {

public:	
	vector<Review> reviewVec;	// vector to store all the reviews

	void inputReviews(vector<Movie> &movieVec);	// class function to parse reviews from the input file

	ReviewDataBase() {}	// default constructor
};