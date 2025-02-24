#!/bin/bash

echo "Compiling program..."
make clean
make

if [ ! -f output ]; then
    echo "Compilation failed. Exiting..."
    exit 1
fi

run_test() {
    input="$1"
    expected="$2"
    output=$(./output $input 2>&1)

    echo "Test: ./output $input"
    echo "Expected: $expected"
    echo "Got: $output"

    if [[ "$output" == "$expected" ]]; then
        echo "Test passed!"
    else
        echo "Test failed!"
    fi
    echo "--------------------------------"
}

run_test "5" "Fibonacci of 5 is 5
Fibonacci of 4 is 3
Fibonacci of 3 is 2
Fibonacci of 2 is 1
Fibonacci of 1 is 1
Fibonacci of 0 is 0
Fibonacci of 1 is 1
Fibonacci of 2 is 1
Fibonacci of 3 is 2
Fibonacci of 4 is 3"

run_test "0" "Fibonacci of 0 is 0"

run_test "-3" "Error: Please enter a value greater than or equal to zero."

run_test "" "Error: Missing value. Try again."

make clean
echo "All tests completed!"
