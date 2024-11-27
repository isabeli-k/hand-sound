CXX = g++
CXXFLAGS = -Wall -O2 `pkg-config --cflags opencv4`
MODULES=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

#Links OpenCV libaries
LDFLAGS = `pkg-config --libs opencv4`

#Define target and source files
TARGET = test_webcam
SRC = main.cpp, sound.cpp

#Rule to build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

#Deletes compiled executable / rebuilding from scratch
clean:
	rm -f $(TARGET)
