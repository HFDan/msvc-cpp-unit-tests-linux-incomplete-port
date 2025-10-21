# MSVC Cpp Unit test framework reimplementation for CMake

## Build Prerequisites

- A C++23 capable compiler (with `std::println` support)
- CMake

## Linkage

1. Clone the repo to a subdirectory
2. `add_subdirectory(<path to where you downloaded>)`
3. `target_link_libraries(<target> PRIVATE msvctest::msvctest)`

## Usage

The library has the exact same API as the Microsoft one

## Contribution

> [!WARNING]
> All contributors must agree to the CLA
> available [here](https://gist.github.com/HFDan/788cc784319e14b21ec71cf0365757ce)