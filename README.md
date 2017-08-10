# ntk_vector2f
Nova's toolkit, 2d vector library.

# What's this?
This is a very small C++ library (liscensed under the good old LGPL) that will give you a very small and robust vector manipulation object, for usage with whatever
you please.

This is not meant to be a standalone program. This is simply a *very* small library for working with 2 dimensional vectors.
The two files, vector2f.hpp and vector2f.cpp, are dependant on one another.

# Using with your own code
If you use this with a modern IDE, just include the two files, and make sure you `#include "vector2f.hpp"` and everything 
should work from there. Otherwise (CLI compiled-program) make sure you both include the header _and_ compile **vector2f.cpp**
with your program.

# Easy to use
The `vector2f` object is very versatile. You can construct it from the start given an `x` and `y` component, or leave it undefined 
and just do it later.

Each member function has both static and non-static variants, allowing you to use the functions in whatever style desired, e.g:
```
vector2f v1(10, 20);
vector2f v2 = v1.Normal();
```
and
```
vector2f v1(10, 20);
vector2f v2 = vector2f::Normal(v1);
```
give the same result, for instance.

# Vector maths
vector2f comes with a complete math library for adding, subtracting, multiplying, and dividing vectors, both by other vectors 
and by scalars. It also has vector operations like cross product and dot product, tangent, normalisation, vector rotation, and
both length and length^2 computation. 

