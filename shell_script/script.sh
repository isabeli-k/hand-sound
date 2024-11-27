#!/bin/bash

SOURCE_CPP="$HOME/Desktop/C/C++/theremin/sound.cpp"
OBJECT_FILE="$HOME/Desktop/C/C++/theremin/sound.o"
OUTPUT_FILE="sfml-app"

COMPILER="g++"
FLAGS="-Wall -Iinclude"
LINK_FLAGS="-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio"

echo "Compiling $SOURCE_CPP..."
$COMPILER -c $SOURCE_CPP -o $OBJECT_FILE $FLAGS

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Linking to create $OUTPUT_FILE..."
$COMPILER $OBJECT_FILE -o $OUTPUT_FILE $LINK_FLAGS

if [ $? -eq 0 ]; then
    echo "Build successful. Running the program..."
    ./$OUTPUT_FILE
else
    echo "Linking failed."
    exit 1
fi

