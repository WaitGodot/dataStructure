
VPATH = src

cc = g++
target = main


objects = main.o

$(target) : $(objects)
	$(cc) -o $(target) $(objects)

main.o: main.cpp macroConfig.h array.h list.h stack.h 

.PHONY : clean
clean : 
		-rm -rf $(target) $(objects)

