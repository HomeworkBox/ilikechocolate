all: test perftest

testdir = tests
basefiles = sorting.cpp $(testdir)/tests_base.cpp
gxxpaths = -I$(testdir)/gtest-1.7.0/include -L$(testdir)/gtest-1.7.0
gxxargs = $(gxxpaths) $(basefiles)
libs = -lgtest -lpthread

test: $(basefiles) $(testdir)/sorting_tests.cpp
	g++ -g -O0 $(gxxargs) $(testdir)/sorting_tests.cpp -o sorting_tests $(libs)

perftest: $(basefiles) $(testdir)/sorting_perftests.cpp
	g++ -O3 $(gxxargs) $(testdir)/sorting_perftests.cpp -o sorting_perftests $(libs)

profile: $(basefiles) $(testdir)/sorting_perftests.cpp
	g++ -p -O3 $(gxxargs) $(testdir)/sorting_perftests.cpp -o sorting_perftests $(libs)
	./sorting_perftests
	gprof ./sorting_perftests > gprof.out
	rm -f gmon.out

leaks: test
	valgrind --tool=memcheck --leak-check=full ./sorting_tests

bounds: test
	valgrind --tool=exp-sgcheck ./sorting_tests

gtest:
	cd $(testdir);\
	unzip -o ./gtest-1.7.0.zip;\
	cd ./gtest-1.7.0;\
	./configure;\
	make;\
	cmake .;\
	g++ -I./include -I./ -c ./src/gtest-all.cc;\
	ar -rv libgtest.a gtest-all.o

clean:
	rm -f ./sorting_tests ./sorting_perftests ./gmon.out ./gprof.out
