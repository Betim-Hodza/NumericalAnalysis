CC=       	g++
CFLAGS= 	-std=c++11
TARGET=		numAnalysis
SRCS = numericalAnalysis.cpp MathApproximator.cpp
OBJS = $(SRCS:.cpp=.o)
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)