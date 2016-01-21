#include <iostream>
#include <fstream>
#include <vector>
#include <cfloat>
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

double basicHelper(vector<Point> input, int size) {

	if (input.size() <= 3) {
		return bruteForce(input);
	}

	int middle = input.size() / 2;
	
	return 0;


}

void optimalMethod(vector<Point> input) {

}


int main(int argc, char *argv[]) {

	int i, n;
    vector<Point> p;

    cout << "Enter the no of points." << endl;
    cin >> n;
    if (n == 1)
       cout << "Enter at least 2 points." << endl;
    else
    {
    cout << "Enter the points." << endl;

    for(i = 0; i < n; i++ ) {
        Point val;
        cin >> val.x >> val.y;
        p.push_back(val);
    }
	}
	
	int size = p.size();
	double closestBruteDistance = bruteForce(p);
	cout << "closest pair distance: " << closestBruteDistance << endl;
	// for(vector<Point>::iterator itr = p.begin(); itr != p.end(); ++itr) {
 //     	cout << "X value: " << itr->x << endl;
 //     	cout << "Y value: " << itr->y << endl;
	// }


	return 0;
}

