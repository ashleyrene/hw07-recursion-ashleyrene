# Compiler settings
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

# Source and object files
SRCS = main.c grid_traversal.c
OBJS = $(SRCS:%.c=%.o)

# Executable name
hw07: $(OBJS)
	$(GCC) $(OBJS) -o hw07

# Rule for compiling .c files to .o
.c.o:
	$(GCC) -c $< -o $@

# Test rules
testall: test0 test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11 test12

test0: hw07
	./hw07 inputs/test0.txt > output0.txt
	diff output0.txt expected/expected0.txt

test1: hw07
	./hw07 inputs/test1.txt > output1.txt
	diff output1.txt expected/expected1.txt

test2: hw07
	./hw07 inputs/test2.txt > output2.txt
	diff output2.txt expected/expected2.txt

test3: hw07
	./hw07 inputs/test3.txt > output3.txt
	diff output3.txt expected/expected3.txt

test4: hw07
	./hw07 inputs/test4.txt > output4.txt
	diff output4.txt expected/expected4.txt

test5: hw07
	./hw07 inputs/test5.txt > output5.txt
	diff output5.txt expected/expected5.txt

test6: hw07
	./hw07 inputs/test6.txt > output6.txt
	diff output6.txt expected/expected6.txt

test7: hw07
	./hw07 inputs/test7.txt > output7.txt
	diff output7.txt expected/expected7.txt

test8: hw07
	./hw07 inputs/test8.txt > output8.txt
	diff output8.txt expected/expected8.txt

test9: hw07
	./hw07 inputs/test9.txt > output9.txt
	diff output9.txt expected/expected9.txt

test10: hw07
	./hw07 inputs/test10.txt > output10.txt
	diff output10.txt expected/expected10.txt

test11: hw07
	./hw07 inputs/test11.txt > output11.txt
	diff output11.txt expected/expected11.txt

test12: hw07
	./hw07 inputs/test12.txt > output12.txt
	diff output12.txt expected/expected12.txt

# Cleanup rule
clean:
	rm -f hw07 *.o *.txt output*
