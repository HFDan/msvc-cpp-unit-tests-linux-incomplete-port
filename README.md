# MSVC Cpp Unit test framework reimplementation for CMake

## Build Prerequisites

- A C++23 capable compiler (with `std::println` support)
- CMake
- The header `cxxabi.h` available to include. (Will be optional in the future)

## Linkage

1. Clone the repo to a subdirectory
2. `add_subdirectory(<path to where you downloaded>)`
3. `add_executable(<target name> <source code>)`
4. `declare_msvc_test(<target name>)`

## Usage

The library has the exact same API as the Microsoft one

## Contribution

> [!WARNING]
> All contributors must agree to the CLA
> available [here](https://gist.github.com/HFDan/788cc784319e14b21ec71cf0365757ce)

### Why? 
I’m sure this is the question on everybody’s lips. You don’t like legalese, neither do I. But I’m young, broke, and not interested in the 0.00001% chance of legal action coming to bite me later.

To my knowledge, this CLA does not take away a contributor’s copyright. Instead, it grants me (the repository owner) a perpetual, irrevocable, transferable license to use, modify, edit, distribute, and otherwise manage your contributions as part of the project.

In short: the CLA exists purely because I don’t want to get sued and I don’t want to lose creative control over my work.

**I have no intention of ever making this project closed-source or commercial. I have no reason to, and I’m pretty sure MS would vaporize me on the spot if I tried.**

Thank you for being interested in contributing, and thank you for using this project (even if it's a very niche use case)