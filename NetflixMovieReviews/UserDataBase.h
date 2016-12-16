#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "User.h"
#include "ReviewDataBase.h"

using namespace std;

class UserDataBase {
public:
	vector<User> userVec;

	void inputUsers(vector<Review> reviewVec);
};