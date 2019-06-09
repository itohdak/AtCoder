#!/bin/bash

function mkdir_atcoder () {
    mkdir $PWD/$1
    cp $(dirname $0)/000/A.cpp $PWD/$1/A.cpp
    cp $(dirname $0)/000/A.cpp $PWD/$1/B.cpp
    cp $(dirname $0)/000/A.cpp $PWD/$1/C.cpp
    cp $(dirname $0)/000/A.cpp $PWD/$1/D.cpp
    cp $(dirname $0)/000/A.cpp $PWD/$1/E.cpp
    cp $(dirname $0)/000/A.cpp $PWD/$1/F.cpp
}

if [ $# -ne 0 ]; then
    mkdir_atcoder $1
fi
