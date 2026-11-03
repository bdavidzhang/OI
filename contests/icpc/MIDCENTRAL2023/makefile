# usage:
#   make A            debug build of A.cpp -> ./A (sanitizers + STL debug)
#   make run P=A      ./A < .in
#   make test P=A     run ./A on every A*.in, diff against matching .ans
#   make A.fast       -O2 build for checking speed -> ./A.fast
#   make A SAN=       build without sanitizers (if libasan is missing)

CXX      = g++
STD      = -std=c++17
SAN      = -fsanitize=address,undefined
CXXFLAGS = $(STD) -Wall -Wextra -Wshadow -g $(SAN) -D_GLIBCXX_DEBUG

%.fast: %.cpp
	$(CXX) $(STD) -O2 -o $@ $<

run: $(P)
	./$(P) < .in

test: $(P)
	@for f in $(P)*.in; do \
	  [ -f "$$f" ] || continue; \
	  a=$${f%.in}.ans; \
	  ./$(P) < $$f > $${f%.in}.out; \
	  if [ ! -f $$a ]; then echo "---- $$f (no .ans)"; cat $${f%.in}.out; \
	  elif diff -bq $${f%.in}.out $$a > /dev/null; then echo "ok   $$f"; \
	  else echo "FAIL $$f"; diff -b $${f%.in}.out $$a; fi; \
	done

.PHONY: run test
