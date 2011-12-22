CC=g++


all: sample

sample: RoboteqDevice.o sample.o
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) -c $<

clean:
	rm *.o
