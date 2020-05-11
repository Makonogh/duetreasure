#pragma once
#include <cmath>

template<class T> class Vector2Template
{
public:
	Vector2Template();
	Vector2Template(T x, T y);
	~Vector2Template();
	T x;
	T y;
	
	// ������Z�q
	Vector2Template& operator = (const Vector2Template& vec);
	
	// �Y�������Z�q
	int& operator[](T i);

	// ��r���Z�q
	bool operator == (const Vector2Template& vec)const;
	bool operator != (const Vector2Template& vec)const;
	bool operator > (const Vector2Template& vec)const;
	bool operator >= (const Vector2Template& vec)const;

	// �P�����Z�q
	Vector2Template& operator += (const Vector2Template& vec);

	Vector2Template& operator -= (const Vector2Template& vec);

	Vector2Template& operator *= (T k);

	Vector2Template& operator /= (T k);

	Vector2Template operator + () const;

	Vector2Template operator - ()const;
};

// �޸�ق̉��Z

// Vector2 + Vector2 
template<class T>
Vector2Template<T> operator + (const Vector2Template<T> & u, const Vector2Template<T> & v);

// Vector2 - Vector2
template<class T>
Vector2Template<T> operator - (const Vector2Template<T> & u, const Vector2Template<T> & v);

// Vector2 * Vector2
template<class T>
Vector2Template<T> operator * (const Vector2Template<T> & u, const Vector2Template<T> & v);

// Vector2 / Vector2
template<class T>
Vector2Template<T> operator / (const Vector2Template<T> & u, const Vector2Template<T> & v);

// Vector2 % Vector2
template<class T>
Vector2Template<T> operator % (const Vector2Template<T> & u, const Vector2Template<T> & v);

// Vector2 + int 
template<class T>
Vector2Template<T> operator + (const Vector2Template<T> & v, T k);

// Vector2 - int 
template<class T>
Vector2Template<T> operator - (const Vector2Template<T> & v, T k);

// Vector2 % int
template<class T>
Vector2Template<T> operator % (const Vector2Template<T> & v, T k);

// Vector2 * int 
template<class T>
Vector2Template<T> operator * (const Vector2Template<T> & v, T k);

// int * Vector2
template<class T>
Vector2Template<T> operator * (T k,const Vector2Template<T> & v);

// Vector2 / int 
template<class T>
Vector2Template<T> operator / (const Vector2Template<T> & v, T k);


// Vector2 �̐�Βl���Ƃ�
template<class T>
Vector2Template<T> abs (const Vector2Template<T> & v);

#include "./detail/Vector2b.h"

using Vector2 = Vector2Template<int>;
using Vector2Dbl = Vector2Template<double>;