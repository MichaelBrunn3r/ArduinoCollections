/*
	A Dictionary optimised ASCII characters
*/
#ifndef CharDictionary_HEADER
#define CharDictionary_HEADER

#if defined CharDictionary_TEST
	#include <cstring>
	typedef unsigned char byte;
#endif

template <typename T_VAL>
class MinCharDictionary {
	public:
		byte mSize;
		char* mKeys;
		T_VAL* mValues;
		explicit MinCharDictionary(const byte entryc, char keys[], T_VAL values[]) {
			mSize = entryc;

			mKeys = new char[entryc];
			mValues = new T_VAL[entryc];
			
			#ifndef CharDictionary_TEST
				std::memcpy(mKeys, keys, entryc * sizeof(char));
				std::memcpy(mValues, values, entryc * sizeof(T_VAL));
			#else
				memcpy(mKeys, keys, entryc * sizeof(char));
				memcpy(mValues, values, entryc * sizeof(T_VAL));
			#endif
		}
		bool hasKey(const char key) {
			for(int i=0; i<mSize; i++) {
				if(mKeys[i] == key) return true;
			}
			return false;
		}
		T_VAL* get(const char key) {
			for(int i=0; i<mSize; i++) {
				if(mKeys[i] == key) return &mValues[i];
			}
			return NULL;
		};

		~MinCharDictionary() {
			delete[] mKeys;
			delete[] mValues;
		}
};

#endif