#ifndef VECTOR2F_HPP_INCLUDED
#define VECTOR2F_HPP_INCLUDED
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

//#define VECTOR2F_USE_CUSTOM_SQRT //Uncomment this line to use custom sqrt function. May be faster on *some* hardware.

struct vector2f
{
    float x, y;

    vector2f(void);
    vector2f(float, float);

    vector2f operator+(vector2f);
    vector2f operator+(float);
    vector2f operator-(vector2f);
    vector2f operator-(float);
    vector2f operator*(vector2f);
    vector2f operator*(float);
    vector2f operator/(vector2f);
    vector2f operator/(float);

    vector2f operator-(void);

    void operator+=(vector2f);
    void operator+=(float);
    void operator-=(vector2f);
    void operator-=(float);
    void operator*=(vector2f);
    void operator*=(float);
    void operator/=(vector2f);
    void operator/=(float);

    bool operator==(vector2f);
    bool operator!=(vector2f);

    static float Length(vector2f);
    float Length(void);

    static float LengthSq(vector2f);
    float LengthSq(void);

    static float Dot(vector2f, vector2f);
    float Dot(vector2f);

    static float Cross(vector2f, vector2f);
    float Cross(vector2f);

    static vector2f Normal(vector2f);
    vector2f Normal(void);

    static float Distance(vector2f, vector2f);
    float Distance(vector2f);

    static float DistanceSq(vector2f, vector2f);
    float DistanceSq(vector2f);

    static vector2f Project(vector2f, vector2f);
    vector2f Project(vector2f);

    static vector2f TangentL(vector2f);
    vector2f TangentL(void);

    static vector2f TangentR(vector2f);
    vector2f TangentR(void);

    static vector2f Rotation(vector2f, float);
    vector2f Rotation(float);
};

#endif // VECTOR2F_HPP_INCLUDED
