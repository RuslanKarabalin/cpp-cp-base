TESTNUM = 01

run:
	g++-14 -O2 -lm -fno-stack-limit -std=c++23 -x c++ $(PROG)/$(PROG).cpp -o $(PROG).x && \
		./$(PROG).x < $(PROG)/in$(TESTNUM).txt && rm $(PROG).x

generate:
	mkdir -p $(PROG) && cp template/template.cpp $(PROG)/$(PROG).cpp && cp template/in01.txt $(PROG)/in01.txt

