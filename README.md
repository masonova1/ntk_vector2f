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
