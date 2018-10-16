#ifndef VECTOR3_HPP
#define VECTOR3_HPP

namespace mlg
{

template <typename T>
struct Vector3
{
	Vector3();
	Vector3(T _x, T _y, T _z);
    template <typename U>
    explicit Vector3(const Vector3<U>& vector);
	Vector3<T> operator-(const Vector3<T>& right);
	////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////
	T x;
	T y;
	T z;
};

typedef Vector3<int>      Vector3i;
typedef Vector3<unsigned> Vector3u;
typedef Vector3<float>    Vector3f;

////////////////////////////////////////////////////////
// Realization
////////////////////////////////////////////////////////
template <typename T>
inline Vector3<T>::Vector3() : x(0), y(0), z(0)
{}

template <typename T>
inline Vector3<T>::Vector3(T _x, T _y, T _z) : x(_x), y(_y), z(_z)
{}

template <typename T>
template <typename U>
inline Vector3<T>::Vector3(const Vector3<U>& vector)
    : x(static_cast<T>(vector.x))
    , y(static_cast<T>(vector.y))
    , z(static_cast<T>(vector.z))
{
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-(const Vector3<T>& right)
{
    return Vector3<T>(-right.x, -right.y, -right.z);
}

template <typename T>
inline Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right)
{
	return Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z);
}

template <typename T>
inline Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right)
{
	return Vector3<T>(left.x + right.x, left.y + right.y, left.z + right.z);
}

template <typename T>
inline Vector3<T> operator/(const Vector3<T>& left, T right)
{
	return Vector3<T>(left.x / right, left.y / right, left.z / right);
}

template <typename T>
inline Vector3<T> operator*(const Vector3<T>& left, T right)
{
	return Vector3<T>(left.x * right, left.y * right, left.z * right);
}

template <typename T>
inline Vector3<T> operator*(T left, const Vector3<T>& right)
{
	return Vector3<T>(right.x * left, right.y * left, right.z * left);
}

template <typename T>
inline Vector3<T>& operator*=(Vector3<T>& left, T right)
{
	left.x *= right;
	left.y *= right;
	left.z *= right;

	return left;
}

template <typename T>
inline bool operator==(const Vector3<T>& left, const Vector3<T>& right)
{
	return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
}

template <typename T>
inline bool operator!=(const Vector3<T>& left, const Vector3<T>& right)
{
	return (left.x != right.x) || (left.y != right.y) || (left.z != right.z);
}


} // namespace mlg

#endif // VECTOR3_HPP
