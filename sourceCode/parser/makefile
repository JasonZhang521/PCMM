CCfile := $(wildcard *.cpp)
Objects = $(CCfile:%.cpp=%.o)
EXCEPTIONINCLUDE = ../exception
INCLUDEFLAG = -I $(EXCEPTIONINCLUDE)
.PHONY: target
target : $(Objects)
%.o : %.cpp
	g++ $(INCLUDEFLAG) -c $< -o $@ 

	echo "build successfully!"

# backup the cc file
$(foreach v, $(CCfile), $(shell cp $(v) .$(v).bak))
#	cp $(CCfile) $(CCfile:%.cpp=.%.cpp.bak)
.PHONY: clean
clean:
	-rm $(TARGET) $(Objects)
