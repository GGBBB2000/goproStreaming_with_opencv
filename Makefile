gopro: goproStreaming.cpp
	c++ -o gopro -DVERBOSE goproStreaming.cpp $(shell pkg-config --cflags --libs opencv)
clean:
	rm -f gopro
