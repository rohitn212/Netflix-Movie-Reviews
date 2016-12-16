#include "ReviewDataBase.h"

void ReviewDataBase:: inputReviews(vector<Movie> &movieVec) {	// class function to parse reviews from the input file

	string line, reviewDate, movieID, userID, rating;

	ifstream file("reviews.csv");

	if (!file.good()) {
		cout << "cannot open file" << endl;
		return;
	}

	getline(file, line);

	while (getline(file, line)) {
		stringstream ss(line);

		//parse every line
		getline(ss, movieID, ',');
		getline(ss, userID, ',');
		getline(ss, rating, ',');
		getline(ss, reviewDate, ',');
		
		/*
			if rating read in for a review is x, increment numx variable of movieVec at that review's movieID
		*/

		if (stoi(rating) == 1) { 
			movieVec[stoi(movieID)].num1++;
		}
		else if (stoi(rating) == 2) {
			movieVec[stoi(movieID)].num2++;
		}
		else if (stoi(rating) == 3) {
			movieVec[stoi(movieID)].num3++;
		}
		else if (stoi(rating) == 4) {
			movieVec[stoi(movieID)].num4++;
		}
		else
		{
			movieVec[stoi(movieID)].num5++;
		}

		movieVec[stoi(movieID)].sum += stoi(rating);	// add to the sum total of ratings for that movie
		movieVec[stoi(movieID)].counter++;	// increment no of reviews for that movie

		Review review(stoi(movieID), stoi(userID), stoi(rating), reviewDate);	// create a review object
		this->reviewVec.push_back(review);	// push it into the vector of reviews
	}
}