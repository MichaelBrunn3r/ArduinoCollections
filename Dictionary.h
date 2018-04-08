#ifndef Dictionary_HEADER
#define Dictionary_HEADER

#include "Arduino.h"

template <typename T_KEY, typename T_VAL>
class Dictionary {
	public:
		Dictionary() : Dictionary(15) {};
		explicit Dictionary(int capacity) : mCapacity(capacity), mSize(0) {
			T_KEY* keys = new T_KEY[mCapacity];
			T_VAL* values = new T_VAL[mCapacity];

			mKeys = keys;
			mValues = values;
		};
		size_t size() {
			return mSize;
		}
		bool isEmpty() {
			return size() == 0;
		};
		bool isFull() {
			return size() == mCapacity;
		};
		bool hasKey(T_KEY key) {
			for(int i=0; i<size(); i++) {
				if(mKeys[i] == key) return true;
			}
			return false;
		};
		T_KEY* keys() {
			return mKeys;
		};
		T_VAL* values() {
			return mValues;
		};
		void put(T_KEY key, T_VAL val) {

			// Override old value if it exists
			int i=0;
			for(i; i<size(); i++) {
				if(mKeys[i] == key) {
					mValues[i] = val;
					return;
				}
			}

			// Add new Key-Value pair
			if(isFull()) resize();
			mKeys[i] = key;
			mValues[i] = val;
			mSize++;
		};
		T_VAL* get(T_KEY key) {
			for(int i=0; i<size(); i++) {
				if(mKeys[i] == key) {
					return &mValues[i];
				}
			}
			return NULL;
		};
	private:
		size_t mSize;
		size_t mCapacity;
		T_KEY* mKeys;
		T_VAL* mValues;
		void resize() {
			size_t newCapacity = mCapacity * 2;
			T_KEY* newKeys = new T_KEY[newCapacity];
			T_VAL* newValues = new T_VAL[newCapacity];

			memcpy(newKeys, mKeys, mCapacity * sizeof(T_KEY));
			memcpy(newValues, mValues, mCapacity * sizeof(T_VAL));

			mCapacity = newCapacity;
			delete[] mKeys;
			delete[] mValues;

			mKeys = newKeys;
			mValues = newValues;
		};
};

#endif