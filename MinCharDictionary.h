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
	private:
		void populate(const byte entryc, char keys[], T_VAL values[]) {
			char* tmpKeys = new char[entryc];
			T_VAL* tmpVals = new T_VAL[entryc];
			byte tmpSize = 0;

			for(int i=0; i<entryc; i++) {
				short l = 0;
				short r = tmpSize-1;
				short m = l + (r-l)/2;

				// Search the position where to put the entry
				while(l <= r) {
					m = l + (r-l)/2;
					if(keys[i] > tmpKeys[m]){
						l = m+1;
					} else if(keys[i] < tmpKeys[m]) {
						r = m-1;
					} else if(keys[i] == tmpKeys[m]) {
						break;
					}
				}

				// Insert the entry
				if(keys[i] == tmpKeys[m]) {
					// Replace the old value
					tmpVals[m] == values[i];
				} else {
					memmove(tmpKeys+l+1, tmpKeys+l, (tmpSize-l) * sizeof(char));
					memmove(tmpVals+l+1, tmpVals+l, (tmpSize-l) * sizeof(T_VAL));
					tmpKeys[l] = keys[i];
					tmpVals[l] = values[i];
					tmpSize++;
				}
			}

			mSize = tmpSize;
			mKeys = new char[mSize];
			mValues = new T_VAL[mSize];

			memcpy(mKeys, tmpKeys, tmpSize * sizeof(char));
			memcpy(mValues, tmpVals, tmpSize * sizeof(T_VAL));

			delete[] tmpKeys;
			delete[] tmpVals;
		}
	public:
		byte mSize = 0;
		char* mKeys;
		T_VAL* mValues;
		explicit MinCharDictionary(const byte entryc, char keys[], T_VAL values[]) {
			populate(entryc, keys, values);
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