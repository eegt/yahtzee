#!/bin/bash
echo "---------------------"
echo "Building Yahtzee..."
make
#([ $? -eq 0 ] && echo "success!") || echo "failure!"

if [ $? -eq 0 ]
then
    echo "   success!"
    echo "---------------------"
    echo "Building tests..."
    cd ../YahtzeeTests
    ./copyFilesUnderTest.sh
    make
    if [ $? -eq 0 ]
    then
        echo "   success!"
        echo "---------------------"
        echo "Running tests..."
        ./yahtzeetests
    fi
else
    echo "Build failed... not attempting tests."
fi
echo ""
