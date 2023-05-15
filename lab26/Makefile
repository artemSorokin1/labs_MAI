GPP = g++

GPPFLAGS = -Wall -pedantic -o
run:
	$(GPP) $(GPPFLAGS) main.out List.cpp main.cpp
	./main.out

var:
	$(GPP) $(GPPFLAGS) variant.out variant.cpp
	./variant.out


clean:
	rm ./variant.out
	rm ./main.out
