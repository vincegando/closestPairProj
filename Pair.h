#include <iostream>

using namespace std;

#ifndef Pair_h
#define Pair_h

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

class Pair {
public:

	Point first;
	Point second;

	void printPairs() {
		cout << "(" << first.x << ", " << first.y << ") " << "(" << second.x << ", " << second.y << ")" << endl;
		
	};

    bool operator < (const Pair& p) const
    {
        if (first < p.first) {
            return true;
        }
        else if (first == p.first) {
            if (second < p.second) {
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

    // ascending x
    // if 
    Pair sortPair(Pair p){
        Pair out;
        if(p.first < p.second) {
            return p;
        } else { 
            Pair newPair;
            Point temp = p.first;
            newPair.first = p.second;
            newPair.second = temp;
            return newPair;
        }
    }
};

#endif