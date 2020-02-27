#!/usr/bin/env bash

g++ -O2 -fno-strict-aliasing -march=native test-array.cc obl_primitives.h -o array-test;
