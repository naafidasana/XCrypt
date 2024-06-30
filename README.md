# Xcrypt
<div align="center">
    <img src = "assets/encryption_in_ancient_egypt.jpg">
</div>

XCrypt is a personal project aimed exploring and implementing various cryptographic algorithms and techniques in C++.
This repo is intended solely for learning purposes and experimentation, and not to build a library to be used in applications.

## Current Algorithms/Encryption Schemes Supported
- Shamir's Secret Sharing Scheme: This algorithm splits a key into `k` multiple shards (shares) such that `n` subset of these shards can be used to reconstruct the original secret.
NB: My implementation at present only works with integers. Next step would be generalize it to work with strings.
For further reading, see https://en.wikipedia.org/wiki/Shamir%27s_secret_sharing

## Getting Started
### Prerequisites
- C++ Compiler (supporting C++ 11 or later)

## Installation
1. Clone the repository
```bash
git clone https://github.com/naafidasana/XCrypt
cd XCrypt
```
## Building and Running
### 1. Building
NB: At present, I am simply building the project with a simple shell script. Will migrate to a build tool (Premake or CMake) as the project grows.
- Grant execute permission to `build.sh` and run it.
```bash
chmod +x build.sh
./build.sh
```
### 2. Running
If the above runs successfully, the generated executable `xcrypt.o` would've been placed in the `bin` directory.
- Run the program by executing the following command:
```bash
./bin/xcrypt.o
```

## Contributing
All are welcome to contribute to XCrypt in the form of bug fixes, enhancements, or implementation of additional cryptographic algorithms. I would also greatly appreciate corrections to wrong implementation logic on my part, and feel free to point me to resources you believe might be helpful.

## License
