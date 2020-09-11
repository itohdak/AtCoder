#!/bin/bash

func_name=mkdir_atcoder
if type $func_name >/dev/null 2>&1; then
    echo "function $func_name already defined. skipped"
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
    echo "defined $func_name function in .bashrc"
fi

if [[ ":${CPATH}:" == *:"$PWD/include":* ]]; then
    echo "CPATH already includes $PWD/include. skipped"
else
    echo -ne "
# AtCoder
export CPATH=\$CPATH:$PWD/include
" >> ~/.bashrc
    echo "added $PWD/include to \$CPATH in .bashrc"
fi
