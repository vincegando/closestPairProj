#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cfloat>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <algorithm>
#include "Pair.h"

using namespace std;


struct sort_by_y
{
    inline bool operator() (const Point first, const Point second)
    {
        if(first.y < second.y) {
        	return true;
        }
        else if(first.y == second.y) {
        	if(first.x < second.x) {
        		return true;
        	}
        	else {
        		return false;
        	}
        }
        else {
        	return false;
        }
    }
};

vector<Pair> minPoints;

double dist(Point a, Point b)
{
    return (sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
}

double returnMinimum(double x, double y) {
	if (x <= y) {
		return x;
	}
	else {
		return y;
	}
}

bool isDuplicate(vector<Point> input, Point p) {
	for (int i =0; i < input.size(); i++) {
		if (input[i].x == p.x && input[i].y == p.y) {
			return true;
		}
	}
	return false;
}

double bruteForce(vector<Point> input) {
	
	double minDistance = DBL_MAX;
	//vector<Point> minPoints;
	if (input.size() < 2) {
		//error
		return 0;
	} 
	else {
		for(long int itr = 0; itr < input.size(); ++itr) {

			for(long int i = itr + 1; i < input.size(); ++i) {
				if (dist(input[itr], input[i]) < minDistance) {
					minDistance = dist(input[itr],input[i]);
					minPoints.clear();
					Point newPoint1;
					newPoint1.x = input[itr].x;
					newPoint1.y = input[itr].y;
					Point newPoint2;
					newPoint2.x = input[i].x;
					newPoint2.y = input[i].y;	
					Pair newPair;
					newPair.first = newPoint1;
					newPair.second = newPoint2;
					minPoints.push_back(newPair);
				}
				else if (dist(input[itr],input[i]) == minDistance) {
					Point newPoint1;
					newPoint1.x = input[itr].x;
					newPoint1.y = input[itr].y;
					Point newPoint2;
					newPoint2.x = input[i].x;
					newPoint2.y = input[i].y;	
					Pair newPair;
					newPair.first = newPoint1;
					newPair.second = newPoint2;
					minPoints.push_back(newPair);

				}

				//cout << "Distance: " << dist(*itr,*i) << endl;
			}
	
		}
	}
	//cout << "closest pair distance: " << minDistance << endl; 
	//sort(minPoints.begin(), minPoints.end());
	//minPoints.erase( unique( minPoints.begin(), minPoints.end() ), minPoints.end() );
	//for(vector<Point>::iterator j = minPoints.begin(); j != minPoints.end(); ++j) {
	//	cout << "(" << j->x << ", " << j->y << ") ";
	//}
	//cout << "\n"; //NEED TO PRINT OUT TWO POINTS PER LINE, NEED TO PRINT CORRECTLY
	return minDistance;

}

double stripFunction(vector<Point> input, double d) {
	double minDistance = d;
	sort(input.begin(), input.end(), sort_by_y());

	for(long int i = 0;i < input.size(); ++i) {
		for(long int j = i + 1; j < input.size() && (input[j].y - input[i].y) < minDistance; ++j) {
			if(dist(input[i], input[j]) < minDistance) {
				minDistance = dist(input[i], input[j]);
				minPoints.clear();
				Point newPoint1;
				newPoint1.x = input[i].x;
				newPoint1.y = input[i].y;
				Point newPoint2;
				newPoint2.x = input[j].x;
				newPoint2.y = input[j].y;
				Pair newPair;
				newPair.first = newPoint1;
				newPair.second = newPoint2;
				minPoints.push_back(newPair);
			}
			else if(dist(input[i], input[j]) == minDistance) {
				Point newPoint1;
				newPoint1.x = input[i].x;
				newPoint1.y = input[i].y;
				Point newPoint2;
				newPoint2.x = input[j].x;
				newPoint2.y = input[j].y;	
				Pair newPair;
				newPair.first = newPoint1;
				newPair.second = newPoint2;
				minPoints.push_back(newPair);

			}
		}
	}

	return minDistance;
}

double stripFunctionOptimal(vector<Point> input, double d) {
	double minDistance = d;

	for(int i = 0;i < input.size(); ++i) {
		for(int j = i + 1; j < input.size() && (input[j].y - input[i].y) < minDistance; ++j) {
			if(dist(input[i], input[j]) < minDistance)
				minDistance = dist(input[i], input[j]);
				
		}
	}

	return minDistance;
}

double basic(vector<Point> input) {

	if (input.size() <= 3) {
		return bruteForce(input);
	}

	int half = input.size() / 2;
	Point mid = input[half];
	vector<Point> firstHalf = vector<Point>(input.begin(), input.begin() + half);
	vector<Point> secondHalf = vector<Point>(input.begin() + half, input.end());
	
	double left = basic(firstHalf);
	double right = basic(secondHalf);

	double d = returnMinimum(left, right);

	vector<Point> stripOfPoints;
	for (int i = 0; i < input.size(); i++) {
		if (abs(input[i].x - mid.x) < d) {
			stripOfPoints.push_back(input[i]);
		}
	}

	int minValue = returnMinimum(d, stripFunction(stripOfPoints, d))
	if (minValue == d) {
		minPoints.clear();
		for(int )
	}

	return minValue;


}


double optimalHelper(vector<Point> x, vector<Point> y) {

	if (y.size() <= 3) {
		return bruteForce(x);
	}

	int half = y.size() / 2;
	Point middle = x[half];

	vector<Point> leftSide;
	vector<Point> rightSide;
	for (int i = 0;i < y.size(); i++) {
		if (y[i].x <= middle.x) {
			leftSide.push_back(y[i]);
		}
		else {
			rightSide.push_back(y[i]);
		}
	}
	vector<Point> temp = vector<Point>(x.begin() + half, x.end());
	double left = optimalHelper(x, leftSide);
	double right = optimalHelper(temp,rightSide);

	double d = returnMinimum(left, right);

	vector<Point> stripOfPoints;
	for (int h = 0; h < y.size(); h++) {
		if (abs(y[h].x - middle.x) < d) {
			stripOfPoints.push_back(y[h]);
		}
	}

	return returnMinimum(d, stripFunctionOptimal(stripOfPoints, d));
}

double optimal(vector<Point> input) {

	vector<Point> xPoints;
	vector<Point> yPoints;

	for(int j = 0; j < input.size(); j++) {
		xPoints.push_back(input[j]);
		yPoints.push_back(input[j]);
	}

	sort(xPoints.begin(), xPoints.end());
	sort(yPoints.begin(), yPoints.end(), sort_by_y());

	return optimalHelper(xPoints, yPoints);
}


int main(int argc, char *argv[]) {

	//int i, n;
    vector<Point> p;
    string type = argv[1];
    // cout << "Enter the no of points." << endl;
    // cin >> n;
    // if (n == 1)
    //    cout << "Enter at least 2 points." << endl;
    // else
    // {
    // cout << "Enter the points." << endl;
    string line;
    double first;
    double second;
    int count;
    while(getline(cin,line)) {
    	count = 0;
    	string num;
    	istringstream iss(line);
    	while(iss >> num) {

    		count++;
    		    	
    	}
    	if (count > 2) {
    			continue;
    	}


    	istringstream iss2(line);
    	iss2 >> first >> second;
    	if (!iss2) {
    		iss2.clear();
    		continue;
    	}
    	Point newPoint;
    	newPoint.x = first;
    	newPoint.y = second;
    	if (isDuplicate(p, newPoint)) {
    		continue;
    	}
    	else {
    	p.push_back(newPoint);
    	}
    }
    
    // for (int i = 0; i < p.size(); i++) {
    // 	cout << p[i].x << " " << p[i].y << endl;
    // }
    

    // for(i = 0; i < n; i++ ) {
    //     Point val;
    //     cin >> val.x >> val.y;
    //     p.push_back(val);
    // }
	
	if (argc < 2) {

	}
	if (type == "brute"){
		double closestBruteDistance = bruteForce(p);
		cout << "closest pair distance: " << closestBruteDistance << endl;

		for(long int i = 0; i < minPoints.size(); i++){
			if(minPoints[i].first < minPoints[i].second){
				continue;
			} else {
				Point temp = minPoints[i].second;
				minPoints[i].second = minPoints[i].first;
				minPoints[i].first = temp;
			}
		}

		sort(minPoints.begin(), minPoints.end());
		minPoints.erase( unique( minPoints.begin(), minPoints.end() ), minPoints.end() );
		for(int j = 0; j < minPoints.size(); j++) {
			minPoints[j].printPairs();
		}
		
	}
	else if(type == "basic") {
		sort(p.begin(), p.end());
		double basicDistance = basic(p);
		cout << "closest pair distance: " << basicDistance << endl;
		for(long int i = 0; i < minPoints.size(); i++){
			if(minPoints[i].first < minPoints[i].second){
				continue;
			} else {
				Point temp = minPoints[i].second;
				minPoints[i].second = minPoints[i].first;
				minPoints[i].first = temp;
			}
		}
		sort(minPoints.begin(), minPoints.end());
		minPoints.erase( unique( minPoints.begin(), minPoints.end() ), minPoints.end() );
		for(int j = 0; j < minPoints.size(); j++) {
			minPoints[j].printPairs();
		}
	
	}
	else if(type == "optimal") {
		double optimalDistance = optimal(p);
		cout << "closest pair distance: " << optimalDistance << endl;
	}
	else {
		cout << "Error. Invalid input" << endl;
		exit(0);
	}

	int size = p.size();
	
	// for(vector<Point>::iterator itr = p.begin(); itr != p.end(); ++itr) {
 //     	cout << "X value: " << itr->x << endl;
 //     	cout << "Y value: " << itr->y << endl;
	// }


	return 0;
}

