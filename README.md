libfindindent
=============

![CI](https://github.com/ribbons/libfindindent/workflows/CI/badge.svg?branch=master)

libfindindent is a portable C++ library to automatically determine the indent style from a text file.

Compile
-------

You'll need the following in addition to a C++ compiler:

* [CMake](https://cmake.org/) in your PATH
* The [Boost](http://boost.org/) C++ library

First, open a shell in the root of the project and then run the following to generate the build files:

``` sh
mkdir build
cd build
cmake ..
```

If CMake can't find your installation of Boost, you might need to set the `BOOST_ROOT` environment variable.

Finally, you can open `build\libfindindent.sln` (Windows) or run `make` (Linux) to build the library and run the tests.

Contribute
----------

Please feel free to send pull requests to fix bugs, add enhancements or add documentation.
If you could include additional unit tests for bug fixes and enhancements that would be greatly appreciated.
