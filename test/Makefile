testDictionary: testDictionary.cpp ../Dictionary.h
	g++ -o testDictionary testDictionary.cpp --std=c++11

testConstASCIIMap: testConstASCIIMap.cpp ../ConstASCIIMap.h ./testUtils.h
	g++ -o testConstASCIIMap testConstASCIIMap.cpp --std=c++11

clean:
	-rm testConstASCIIMap
	-rm testDictionary