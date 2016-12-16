//
// Netflix Movie Review Analysis
//
// Rohit Nambiar
// U. of Illinois, Chicago

#include "MovieDataBase.h"
#include "ReviewDataBase.h"
#include "UserDataBase.h"

bool sortMovieID(Movie movieA, Movie movieB) {	// helper function to sort movie vector in according to movieID in ascending order
	return movieA.movieID < movieB.movieID;
}

bool sortAvgRating(Movie movieA, Movie movieB) {	// helper function to sort movie vector according to average rating and then movieName in ascending order
	if (movieA.avgRating == movieB.avgRating) {
		return movieA.movieName < movieB.movieName;
	}
	else 
		return movieA.avgRating > movieB.avgRating;
}

bool sortUserID(Review reviewA, Review reviewB) {	// helper function to sort review vector in according to userID in ascending order
	return reviewA.userID < reviewB.userID;
}

bool sortReviews(User userA, User userB) {	// helper function to sort user vector according to no of reviews and then userID in ascending order
	if (userA.reviews == userB.reviews) {
		return userA.userID < userB.userID;
	}
	else
	{
		return userA.reviews > userB.reviews;
	}
}

void printInfo(vector<Movie> movieVec, vector<Review> reviewVec) {	// function that prints no of movies and no of reviews
	cout << "** Netflix Movie Review **" << endl;
	cout << endl;
	cout << ">> Reading movies... " << movieVec.size()-1 << endl;
	cout << ">> Reading reviews... " << reviewVec.size() << endl;
	cout << "\n";
}

void printTopMovies(vector<Movie> movieVec) {	// function that prints top 10 movies
	cout << ">> Top-10 Movies <<" << "\n" << endl;
	cout << "Rank";
	cout << "	" << "ID";
	cout << "	" << "Reviews";	
	cout << "	" << "Avg";	
	cout << "	" << "Name" << endl;

	for (int i = 1; i < 11; i++) {
		cout << i << ".";
		cout << "	" << movieVec[i].movieID;
		cout << "	" << movieVec[i].counter;
		cout << "	" << movieVec[i].avgRating;
		cout << "	" << movieVec[i].movieName << endl;
	}
}

void printTopUsers(vector<User> userVec) {	// function that prints top 10 users
	cout << "\n";
	cout << ">> Top-10 Users <<" << "\n" << endl;
	cout << "Rank";
	cout << "	" << "ID";
	cout << "	" << "Reviews" << endl;

	for (int i = 0; i < 10; i++) {
		cout << i+1 << ".";
		cout << "	" << userVec[i].userID;
		cout << "	" << userVec[i].reviews << endl; 
	}
}

void userInteractiveLoop(vector<Movie> movieVec) {	// interactive loop
	
	int userInput = -1;	// initialize to a value that isn't 0 
	
	cout << "\n" << ">> Movie Information <<" << endl;
	
	while (userInput != 0) {
		cout << "Please enter a movie ID [1.." << movieVec.size() - 1 << "], 0 to stop: ";
		cin >> userInput;	// get input from user

		if (userInput == 0) {
			cout << "\n";
			cout << "** Done! **";
			cout << "\n";
			break;
		}
		else if (userInput > 0 && userInput < movieVec.size()) {	// if input is in range
			cout << "\n";
			cout << "Movie:" << "		" << "'" << movieVec[userInput].movieName << "'" << endl;
			cout << "Year:" << "		" << movieVec[userInput].pubYear << endl;
			cout << "Avg rating:" << "	" << movieVec[userInput].avgRating << endl;
			cout << "Num reviews:" << "	" << movieVec[userInput].counter << endl;
			cout << "Num 1's:" << "	" << movieVec[userInput].num1 << endl;
			cout << "Num 2's:" << "	" << movieVec[userInput].num2 << endl;
			cout << "Num 3's:" << "	" << movieVec[userInput].num3 << endl;
			cout << "Num 4's:" << "	" << movieVec[userInput].num4 << endl;
			cout << "Num 5's:" << "	" << movieVec[userInput].num5 << endl;
			cout << "\n";
		}
		else	// if input is neither 0 nor in range 
		{
			cout << "** Invalid movie id, please try again..." << endl;
			continue;
		}

	}

}


int main() {

	MovieDataBase movieDataBase;	// default constructor for MovieDataBase
	ReviewDataBase reviewDataBase;	// default constructor for ReviewDataBase
	UserDataBase userDataBase;	// default constructor for UserDataBase

	movieDataBase.inputMovies();	// parse all the movies

	sort(movieDataBase.movieVec.begin()+1, movieDataBase.movieVec.end(), sortMovieID);	// sort all movies according to movieID

	reviewDataBase.inputReviews(movieDataBase.movieVec);	// read in all the reviews

	movieDataBase.calcAvgReview();	// calculate average rating for each movie

	sort(movieDataBase.movieVec.begin()+1, movieDataBase.movieVec.end(), sortAvgRating); // sort all movies according to average rating

	printInfo(movieDataBase.movieVec, reviewDataBase.reviewVec);	// print no of reviews and movies read in

	printTopMovies(movieDataBase.movieVec);	// print top 10 movies

	sort(reviewDataBase.reviewVec.begin(), reviewDataBase.reviewVec.end(), sortUserID);	// sort all reviews according to userID in ascending order

	userDataBase.inputUsers(reviewDataBase.reviewVec);	// find unique users and no of reviews for each one

	sort(userDataBase.userVec.begin(), userDataBase.userVec.end(), sortReviews);	// sort all users according to no of reviews

	printTopUsers(userDataBase.userVec);	// print top 10 users

	sort(movieDataBase.movieVec.begin() + 1, movieDataBase.movieVec.end(), sortMovieID);	// sort all movies according to movieID

	userInteractiveLoop(movieDataBase.movieVec);	// interactive loop - part 3

	return 0;
}