#ifndef VECTOR2_HPP
#define VECTOR2_HPP

namespace mlg
{

template <typename T>
struct Vector2
{
    Vector2();
    Vector2(T _x, T _y);
    Vector2<T> operator-(const Vector2<T>& right);
    ////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////
    T x;
    T y;
};

typedef Vector2<int>      Vector2i;
typedef Vector2<unsigned> Vector2u;
typedef Vector2<float>    Vector2f;

////////////////////////////////////////////////////////
// Realization
////////////////////////////////////////////////////////
template <typename T>
inline Vector2<T>::Vector2() : x(0), y (0)
{}

template <typename T>
inline Vector2<T>::Vector2(T _x, T _y) : x(_x), y (_y)
{}

template<typename T>
inline Vector2<T> Vector2<T>::operator-(const Vector2<T>& right)
{
	return Vector2<T>(-right.x, -right.y);
}

template <typename T>
inline Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x - right.x, left.y - right.y);
}

template <typename T>
inline Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
{
    return Vector2<T>(left.x + right.x, left.y + right.y);
}

template <typename T>
inline Vector2<T> operator/(const Vector2<T>& left, T right)
{
    return Vector2<T>(left.x / right, left.y / right);
}

template <typename T>
inline Vector2<T> operator*(const Vector2<T>& left, T right)
{
    return Vector2<T>(left.x * right, left.y * right);
}

template <typename T>
inline Vector2<T> operator*(T left, const Vector2<T>& right)
{
    return Vector2<T>(right.x * left, right.y * left);
}

template <typename T>
inline Vector2<T>& operator*=(Vector2<T>& left, T right)
{
    left.x *= right;
    left.y *= right;

    return left;
}

template <typename T>
inline bool operator==(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x == right.x) && (left.y == right.y);
}

template <typename T>
inline bool operator!=(const Vector2<T>& left, const Vector2<T>& right)
{
    return (left.x != right.x) || (left.y != right.y);
}

} // namespace mlg

#endif // VECTOR2_HPP
