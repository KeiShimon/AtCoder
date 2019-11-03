#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

const unsigned identity = ~0U;

template< class T >
struct Matrix {
private:
	size_t height, width;

public:
	vector< vector< T > > A;

	Matrix() {}
	Matrix(size_t n, size_t m) : A(n, vector< T >(m, 0)), height{ n }, width{ m } {}
	Matrix(size_t n) : A(n, vector< T >(n, 0)), height{ n }, width{ n } {};

	size_t getH() const { return height; }
	size_t getW() const { return width; }

	inline const vector< T >& operator[](int k) const { return (A.at(k)); }
	inline vector< T >& operator[](int k) { return (A.at(k)); }
	inline T& at(int i, int j) { return A[i][j]; }
	inline const T& at(int i, int j) const { return A[i][j]; }

	static Matrix I(size_t n) {
		Matrix mat(n);
		for (int i = 0; i < n; i++) mat[i][i] = identity;
		return (mat);
	}

	Matrix& operator*=(const Matrix& B) {
		size_t n = getH(), m = B.getW(), p = getW();
		assert(p == B.getH());
		vector< vector< T > > C(n, vector< T >(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				T x = 0;
				for (int k = 0; k < p; k++)
					x ^= at(i, k) & B.at(k, j);
				C[i][j] = x;
			}
		A.swap(C);
		return (*this);
	}

	Matrix& operator^=(long long k) {
		Matrix B = Matrix::I(getH());
		while (k) {
			if (k & 1) B *= *this;
			*this *= *this;
			k >>= 1LL;
		}
		A.swap(B.A);
		return (*this);
	}

	Matrix operator*(const Matrix& B) const { return (Matrix(*this) *= B); }
	Matrix operator^(const long long k) const { return (Matrix(*this) ^= k); }

};

unsigned va[100], vc[100];
int K, M;

int main()
{
	cin >> K >> M;
	REP(i, K) cin >> va[i];
	REP(i, K) cin >> vc[i];

	Matrix<unsigned> A(K, K), v(1, K);
	REP(i, K) v.at(0, i) = va[i];
	REP(i, K) A.at(i, K - 1) = vc[K - 1 - i];
	REP(i, K - 1) A.at(i + 1, i) = identity;

	A = A ^ (M - 1);
	v *= A;

	unsigned ans = v.at(0, 0);
	cout << ans << endl;
}
