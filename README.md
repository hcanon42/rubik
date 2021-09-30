# Rubik
A rubik's cube solver in less than 21 moves !

## Table of Content

* [Technologies](#technologies)
* [Description](#description)
* [Installation](#installation)
* [Usage](#usage)
* [Contributing](#contributing)

## Technologies

Project is created with:
* clang++ version: 10.0.0

## Description

description of rubik and shuffle

## Installation

To install, just clone the repository and run :
```sh
make
```
Two binaries should then be available to you: "rubik" and "shuffle"

## Usage

```sh
./rubik				(listens to std_in)
./rubik "R L' B2"	(moves to shuffle the cube)
./suffle 20 		(0 < number_of_moves < 1000)
```
or the most used:
```sh
./suffle [0 < number_of_moves < 1000] | ./rubik
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.\
Please make sure to update tests as appropriate.