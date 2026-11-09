libfindindent
=============

A portable C++ library to automatically determine the indent style from a text file.

Compile
-------

You'll need the following in addition to a C++ compiler:

* CMake in your PATH
* The Boost C++ library

First, open a shell in the root of the project and then run the following to generate the build files:

``` sh
mkdir build
cd build
cmake ..
```

If CMake can't find your installation of Boost, you might need to set the `BOOST_ROOT` environment variable.

Finally, you can open `build\libfindindent.sln` (Windows) or run `make` (Linux) to build the library and run the tests.
