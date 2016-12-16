#include "MovieDataBase.h"

void  MovieDataBase:: inputMovies() {	// class function to parse the movies from the input file

	string movieID, line, pubYear, movieName;
	/*
		initialize all class variables that you won't be using in this function to 0
	*/
	double avgRating = 0;
	int counter = 0; 
	int sum = 0;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0; 
	int num4 = 0;
	int num5 = 0;

	ifstream file("movies.csv");

	if (!file.good()) {
		cout << "cannot open file" << endl;
		return;
	}

	getline(file, line);
	Movie movie(0, 0, "sas", avgRating, sum, 1, num1, num2, num3, num4, num5);
	this->movieVec.push_back(movie);

	while (getline(file, line)) {
		stringstream ss(line);

		//parse every line
		getline(ss, movieID, ',');
		getline(ss, movieName, ',');
		getline(ss, pubYear, ',');

		// make a movie object and push it into the vector containing all the movies
		Movie movie(stoi(movieID), stoi(pubYear), movieName, avgRating, sum, counter, num1, num2, num3, num4, num5);
		this->movieVec.push_back(movie);
	}
}

	void MovieDataBase:: calcAvgReview() {	// class function to calculate average rating for each movie
		for (auto &c : this->movieVec) {	// go through all the movies
			c.avgRating = ((double)(c.sum)) / c.counter;	// calculate average rating
	}

}