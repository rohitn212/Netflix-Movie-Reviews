#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "Movie.h"

using namespace std;

class MovieDataBase {

public:
	vector<Movie> movieVec;	// vector to store all the movies

	void inputMovies();	// class function to parse the movies from the input file
	void calcAvgReview();	// class function to calculate the average review

	MovieDataBase() {}	// default constructor

};