CC := g++ -pg
LIBDIR :=
LIB :=
IDIR :=
STD := -std=c++11 -g
DEFINES := -DTEST
DEF += #$(DEFINES)

src := $(wildcard ./src/*.cpp)
obj := $(patsubst %.cpp,%.o,$(src))

.PHONY : all
all : maze

maze:$(obj)
	$(CC) $^ $(LIBDIR) -o $@ $(LIB)
%.o:%.cpp
	$(CC) -c $^ $(IDIR)  -o $@ $(DEF) $(STD)

.PHONY:clean
clean:
	rm ./src/*.o 
	rm ./maze
