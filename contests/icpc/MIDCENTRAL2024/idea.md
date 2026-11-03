-std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -o solution
./solutoin < .in > b.out

 What I'd use

  Let make's built-in rule handle compiling, so the whole makefile is one line:

  CXXFLAGS = -std=c++17 -Wall -Wextra -Wshadow -g -fsanitize=address,undefined -D_GLIBCXX_DEBUG

  Then for each problem:

  make A && ./A < A.in        # builds A from A.cpp, only when A.cpp has changed

  That fits your directory, which already has an X.cpp source next to an X binary for each problem. It's also easy to retype from memory on the
  contest machine.

  Checking against samples. Save the samples as A1.in/A1.ans, A2.in/A2.ans, and so on, then run:

  for f in A*.in; do ./A < $f > o.txt; diff -bq o.txt ${f%.in}.ans >/dev/null && echo "ok $f" || { echo "FAIL $f"; diff -b o.txt ${f%.in}.ans; };
  done

  Checking speed. _GLIBCXX_DEBUG and the sanitizers can make your code 10x slower or more. Before you decide a solution is too slow, time a build
  that's closer to what the judge runs:

  g++ -std=c++17 -O2 A.cpp -o A_fast && time ./A_fast < big.in