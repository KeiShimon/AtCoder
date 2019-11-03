#include "template.h"

template <class T>
inline double eucladian(T ax, T ay, T bx, T by) { return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)); }

template <class T>
inline ll eucladianSquare(T ax, T ay, T bx, T by) { return (ll)((ax - bx) * (ax - bx) + (ay - by) * (ay - by)); }


template<class T>
inline T manhattan(T ax, T ay, T bx, T by) { return abs(ax - bx) + abs(ay - by); }
