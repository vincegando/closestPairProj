#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cfloat>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Point
{
	double x;
	double y;

	bool operator < (const Point& p) const
    {
        if (x < p.x) {
        	return true;
        }
        else if (x == p.x) {
        	if (y < p.y) {
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

    bool operator== (const Point& p) const {
    	if (x == p.x && y == p.y) {
    		return true;
    	}
    	else {
    		return false;
    	}
    }

};

double dist(Point a, Point b)
{
    return (sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
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
	vector<Point> minPoints;
	if (input.size() < 2) {
		//error
		return 0;
	} 
	else {
		for(vector<Point>::iterator itr = input.begin(); itr != input.end(); ++itr) {

			for(vector<Point>::iterator i = itr + 1; i != input.end(); ++i) {
				if (dist(*itr,*i) < minDistance) {
					minDistance = dist(*itr,*i);
					minPoints.clear();
					minPoints.push_back(*itr);
					minPoints.push_back(*i);
				}
				else if (dist(*itr,*i) == minDistance) {
					minPoints.push_back(*itr);
					minPoints.push_back(*i);
				}

				//cout << "Distance: " << dist(*itr,*i) << endl;
			}
	
		}
	}
	//cout << "closest pair distance: " << minDistance << endl; 
	sort(minPoints.begin(), minPoints.end());
	minPoints.erase( unique( minPoints.begin(), minPoints.end() ), minPoints.end() );
	//for(vector<Point>::iterator j = minPoints.begin(); j != minPoints.end(); ++j) {
	//	cout << "(" << j->x << ", " << j->y << ") ";
	//}
	//cout << "\n"; //NEED TO PRINT OUT TWO POINTS PER LINE, NEED TO PRINT CORRECTLY
	return minDistance;

}

double stripFunction(vector<Point> input, int size, double d) {
	double minDistance = d;

	return 0;
}

double basicHelper(vector<Point> input, int size) {

	if (input.size() <= 3) {
		return bruteForce(input);
	}

	int half = input.size() / 2;
	Point mid = input[half];

	double left = basicHelper(input, half);
	//double right = basicHelper(input + half, size - half);

	//double d = min(left, right);

	vector<Point> stripOfPoints;
	int i = 0;
	for (int j = 0; j <size; j++) {
		//if (abs(input[j].x - mid.x) < d) {
		//	stripOfPoints[i] = input[j];
		//	i++;
		//}
	}

	return 0;//min(d, stripFunction(stripOfPoints, i, d));


}

void optimalMethod(vector<Point> input) {

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
		//NEED TO PRINT OUT POINTS
	}
	else if(type == "basic") {
		cout << "basic" << endl;
	}
	else if(type == "optimal") {
		cout << "optimal" << endl;
	}
	else {
		cout << "Error. Invalid input" << endl;
	}

	int size = p.size();
	
	// for(vector<Point>::iterator itr = p.begin(); itr != p.end(); ++itr) {
 //     	cout << "X value: " << itr->x << endl;
 //     	cout << "Y value: " << itr->y << endl;
	// }


	return 0;
}

