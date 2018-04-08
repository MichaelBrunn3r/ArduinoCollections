testDictionary: testDictionary.cpp ../Dictionary.h
	g++ -o testDictionary testDictionary.cpp -I/usr/lib/catch2 --std=c++11

testFixedASCIIDictionary: testFixedASCIIDictionary.cpp ../FixedASCIIDictionary.h ./testUtils.h
	g++ -o testFixedASCIIDictionary testFixedASCIIDictionary.cpp -I/usr/lib/catch2 --std=c++11

clean:
	-rm testFixedASCIIDictionary
	-rm testDictionary