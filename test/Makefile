CPP_SRC_DIR=../src

TestConstASCIIMap: TestConstASCIIMap.cpp $(CPP_SRC_DIR)/ConstASCIIMap.h  ./TestUtils.h
	g++ -o TestConstASCIIMap TestConstASCIIMap.cpp --std=c++11 -I$(CPP_SRC_DIR)

clean:
	-rm TestConstASCIIMap