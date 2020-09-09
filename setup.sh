#!/bin/bash

func_name=mkdir_atcoder
if type $func_name >/dev/null 2>&1; then
    echo "function $func_name already defined"
else
    echo -ne "
function $func_name () {
    mkdir \$PWD/\$1
    cp $PWD/templates/A.cpp \$PWD/\$1/A.cpp
    cp $PWD/templates/A.cpp \$PWD/\$1/B.cpp
    cp $PWD/templates/A.cpp \$PWD/\$1/C.cpp
    cp $PWD/templates/A.cpp \$PWD/\$1/D.cpp
    cp $PWD/templates/A.cpp \$PWD/\$1/E.cpp
    cp $PWD/templates/A.cpp \$PWD/\$1/F.cpp
}
" >> ~/.bashrc
    exec bash
fi
