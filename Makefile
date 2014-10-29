
cc = g++
target = main


objects = main.o

$(target) : $(objects)
	$(cc) -o $(target) $(objects)

main.o : src/main.cpp
		$(cc) -c src/main.cpp

.PHONY : clean
clean : 
		-rm -rf $(target) $(objects)

