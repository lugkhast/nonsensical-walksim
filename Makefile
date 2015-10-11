# NOTE: Makefiles MUST be indented with tabs

#OBJS specifies which files to compile as part of the project
OBJS = main.cpp Movable.cpp MovementHandler.cpp SDLApp.cpp

#CC specifies which compiler we're using
CC = clang++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -Wno-c++11-extensions suppresses warnings for C++11 extension usage
COMPILER_FLAGS = -Wno-c++11-extensions

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
