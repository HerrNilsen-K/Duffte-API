cc = clang++
appName = program.exe

sources = $(wildcard */*/*/*/*.cpp) $(wildcard */*/*/*.cpp) $(wildcard */*/*.cpp) $(wildcard */*.cpp) $(wildcard *.cpp)
#sources = $(shell find -name *.cpp)
objects = $(patsubst %.cpp, %.o, $(notdir $(sources)))

flags = -g -Wall -std=c++17
libPath = -L"C:\\Users\\Karl\\Desktop\\c++\\libraries\\GLFW\\lib-vc2019" \
		-L"C:\\Users\\Karl\\Desktop\\c++\\libraries\\GLEW\\lib\\Release\\x64" 
libs = -lglew32 -lglfw3 -lopengl32 -lglu32 -lShell33 -lmsvcrt -lgdi32 -lUser32 -lkernel32

all: compile clean run

compile: $(objects)
	$(cc) -o $(appName) $(objects) $(libPath) $(libs)
  
$(objects):
	$(cc) $(flags) -c $(sources)
  
clean:
	del *.o
  
run:
	./$(appName)