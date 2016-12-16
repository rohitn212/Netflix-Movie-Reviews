#pragma once

using namespace std;

class Movie {

public:
	// sum stores the sum total ratings for each movie
	// each num stores the total number of 1, 2, 3, 4, 5 ratings respectively for each movie
	int movieID, pubYear, sum, counter, num1, num2, num3, num4, num5; 
	double avgRating;	// to store the average rating for each movie
	string movieName;	

	Movie(int movieID, int pubYear, string movieName, double avgRating, int sum, int counter, int num1, int num2, int num3, int num4, int num5) :
		movieID(movieID), pubYear(pubYear), movieName(movieName), avgRating(avgRating), sum(sum), counter(counter), num1(num1), num2(num2), 
		num3(num3), num4(num4), num5(num5) {}
};
