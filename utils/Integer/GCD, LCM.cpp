

template <class T>
inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template <class T>
inline T lcm(T a, T b) { return a / gcd(a, b) * b; }