# Bistro-Matic ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)

First big project of first year at Epitech at the end of the pool.

Creation of a calculator able to display the result of the evaluation of an arithmetic expression composed of integers of infinite size expressed in any base.
## Usage
```
./calc base operators size_read

- base: all the symbols of the base
- operators: the symbols for the parentheses and the 5 operators
- size_read: number of characters to be read
```

## Build and Run
```
make
```
## Example to use the program
```
echo '3+6' | ./calc 0123456789 '()+-*/%' 3
9
```
```
echo ‘-(12-(4*32))’ | ./calc 0123456789 ‘()+-*/%’ 12
116
```
## Made with
- [Dorian MOY](https://github.com/Croos3r)
- [Daniel KOMOE](https://github.com/dankyle6700)

