#include "template.h"

/*


*/


//// MUST INCLUDE ////
#include <map>



//// INT VERSION ////

const int mask = 1 << 31;

struct compare{
	bool operator()(pair<int, int>&left, pair<int, int>& right)
	{
		if (!(left.first & mask) && !(left.second & mask)) // left is at 1st-quadrant
		{
			if (right.first & mask || right.second & mask) return true;
			else return (ll)left.second * right.first < (ll)left.first * right.second;
		}
		else if ((left.first & mask) && !(left.second & mask)) // left is at 2nd-quadrant
		{
			if (!(right.first & mask) && !(right.second & mask)) return false;
			else if ((right.first & mask) && !(right.second & mask)) return (ll)left.second * right.first < (ll)left.first * right.second;
			else return true;
		}
		else if (left.first & mask) // left is at 3rd-quadrant
		{
			if (!(right.second & mask)) return false;
			else if (right.first & mask) return (ll)left.second * right.first < (ll)left.first * right.second;
			else return true;
		}
		else
		{
			if (!(right.second & mask)) return false;
			else if (right.first & mask) return false;
			else return (ll)left.second * right.first < (ll)left.first * right.second;
		}
	}
};

map<pair<int, int>, int, compare> vec;


//// LONG LONG VERSION ////


const ll mask = 1LL << 63;

struct compare {
	bool operator()(pair<ll, ll>& left, pair<ll, ll>& right)
	{
		if (!(left.first & mask) && !(left.second & mask)) // left is at 1st-quadrant
		{
			if (right.first & mask || right.second & mask) return true;
			else return (ll)left.second * right.first < (ll)left.first * right.second;
		}
		else if ((left.first & mask) && !(left.second & mask)) // left is at 2nd-quadrant
		{
			if (!(right.first & mask) && !(right.second & mask)) return false;
			else if ((right.first & mask) && !(right.second & mask)) return (ll)left.second * right.first < (ll)left.first * right.second;
			else return true;
		}
		else if (left.first & mask) // left is at 3rd-quadrant
		{
			if (!(right.second & mask)) return false;
			else if (right.first & mask) return (ll)left.second * right.first < (ll)left.first * right.second;
			else return true;
		}
		else
		{
			if (!(right.second & mask)) return false;
			else if (right.first & mask) return false;
			else return (ll)left.second * right.first < (ll)left.first * right.second;
		}
	}
};

