
VPATH += src

cc = g++
target = main


objects = main.o

$(target) : $(objects)
	$(cc) -o $(target) $(objects)

main.o: src/main.cpp macroConfig.h array.h list.h stack.h bstree.h
		$(cc) -g -c src/main.cpp

.PHONY : clean
clean : 
		-rm -rf $(target) $(objects)

