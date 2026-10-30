#!/bin/bash
set -e  # stop on compile errors

g++ -std=c++17 -O2 fast.cpp -o fast
g++ -std=c++17 -O2 brute.cpp -o brute

for((i=1;i<=100;i++)); do
    python3 gen.py > input.txt

    ./fast
    mv fast_out.txt out1.txt

    ./brute
    mv brute_out.txt out2.txt

    if diff -q out1.txt out2.txt >/dev/null; then
        echo "✅ Test $i passed"
    else
        echo "❌ Found difference on test $i!"
        echo "Input:"
        cat input.txt
        echo "Fast output:"
        cat out1.txt
        echo "Brute output:"
        cat out2.txt
        break
    fi
done
