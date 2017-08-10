#include "vector2f.hpp"
#include <cmath>
#include <algorithm>
//Copyright (C) 2017 Mason Watmough

/*
    This file is part of vector2f.

    vector2f is free software: you can redistribute it and/or modify
    it under the terms of the Lesser GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    vector2f is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    Lesser GNU General Public License for more details.

    You should have received a copy of the Lesser GNU General Public License
    along with vector2f. If not, see <http://www.gnu.org/licenses/>.
*/

vector2f::vector2f(void){}

#ifdef VECTOR2F_USE_CUSTOM_SQRT
float v2fSqrt(float x)
{
    float y = x;
    float xover2 = x * 0.5;
    int i = *(int*)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(float*)&i;
    x = x*(1.5f-(xover2*x*x));
    x = x*(1.5f-(xover2*x*x));
    return x * y;
}
#else
float v2fSqrt(float x)
{
    return std::sqrt(x);
}
#endif

vector2f::vector2f(float x, float y)
{
    this->x = x;
    this->y = y;
}

vector2f vector2f::operator+(vector2f rhs)
{
    return vector2f(this->x + rhs.x, this->y + rhs.y);
}

vector2f vector2f::operator+(float rhs)
{
    return vector2f(this->x + rhs, this->y + rhs);
}

vector2f vector2f::operator-(vector2f rhs)
{
    return vector2f(this->x - rhs.x, this->y - rhs.y);
}

vector2f vector2f::operator-(float rhs)
{
    return vector2f(this->x - rhs, this->y - rhs);
}

vector2f vector2f::operator*(vector2f rhs)
{
    return vector2f(this->x * rhs.x, this->y * rhs.y);
}

vector2f vector2f::operator*(float rhs)
{
    return vector2f(this->x * rhs, this->y * rhs);
}

vector2f vector2f::operator/(vector2f rhs)
{
    return vector2f(this->x / rhs.x, this->y / rhs.y);
}

vector2f vector2f::operator/(float rhs)
{
    return vector2f(this->x / rhs, this->y / rhs);
}

vector2f vector2f::operator-(void)
{
    return vector2f(-this->x, -this->y);
}

void vector2f::operator+=(vector2f rhs)
{
    *this = *this + rhs;
}

void vector2f::operator+=(float rhs)
{
    *this = *this + rhs;
}

void vector2f::operator-=(vector2f rhs)
{
    *this = *this - rhs;
}

void vector2f::operator-=(float rhs)
{
    *this = *this - rhs;
}

void vector2f::operator*=(vector2f rhs)
{
    *this = *this * rhs;
}

void vector2f::operator*=(float rhs)
{
    *this = *this * rhs;
}

void vector2f::operator/=(vector2f rhs)
{
    *this = *this / rhs;
}

void vector2f::operator/=(float rhs)
{
    *this = *this / rhs;
}

bool vector2f::operator==(vector2f rhs)
{
    return (this->x == rhs.x) && (this->y == rhs.y);
}

bool vector2f::operator!=(vector2f rhs)
{
    return (this->x != rhs.x) || (this->y != rhs.y);
}

float vector2f::Length(vector2f v)
{
    //return std::sqrt(v.x * v.x + v.y * v.y);
    return std::hypot(v.x, v.y);
}

float vector2f::Length()
{
    return vector2f::Length(*this);
}

float vector2f::LengthSq(vector2f v)
{
    return v.x * v.x + v.y * v.y;
}

float vector2f::LengthSq(void)
{
    return vector2f::LengthSq(*this);
}

float vector2f::Dot(vector2f v1, vector2f v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

float vector2f::Dot(vector2f v)
{
    return vector2f::Dot(*this, v);
}

float vector2f::Cross(vector2f v1, vector2f v2)
{
    return v1.x * v2.y - v1.x * v2.y;
}

float vector2f::Cross(vector2f v)
{
    return vector2f::Cross(*this, v);
}

vector2f vector2f::Normal(vector2f v)
{
    return vector2f(v.x / v.Length(), v.y / v.Length());
}

vector2f vector2f::Normal(void)
{
    return vector2f::Normal(*this);
}

float vector2f::Distance(vector2f v1, vector2f v2)
{
    return (v2 - v1).Length();
}

float vector2f::Distance(vector2f v)
{
    return (*this - v).Length();
}

float vector2f::DistanceSq(vector2f v1, vector2f v2)
{
    return (v2 - v1).LengthSq();
}

float vector2f::DistanceSq(vector2f v)
{
    return (*this - v).LengthSq();
}

vector2f vector2f::Project(vector2f v1, vector2f v2)
{
    vector2f p;
    p.x = (vector2f::Dot(v1, v2) / vector2f::LengthSq(v2)) * v2.x;
    p.y = (vector2f::Dot(v1, v2) / vector2f::LengthSq(v2)) * v2.y;
    return p;
}

vector2f vector2f::Project(vector2f v)
{
    return vector2f::Project(*this, v);
}

vector2f vector2f::TangentL(vector2f v)
{
    std::swap(v.x, v.y);
    v.y = -v.y;
    return v;
}

vector2f vector2f::TangentL(void)
{
    return vector2f::TangentL(*this);
}

vector2f vector2f::TangentR(vector2f v)
{
    return -vector2f::TangentL(v);
}

vector2f vector2f::TangentR(void)
{
    return vector2f::TangentR(*this);
}

vector2f vector2f::Rotation(vector2f v, float t)
{
    float s = std::sin(t);
    float c = std::sqrt(1 - s * s);
    vector2f p(v.x * c - v.y * s, v.x * s + v.y * c);
    return p;
}

vector2f vector2f::Rotation(float t)
{
    return vector2f::Rotation(*this, t);
}
