#ifndef Dictionary_HEADER
#define Dictionary_HEADER

#include "Arduino.h"

template <typename T_KEY, typename T_VAL>
class Dictionary {
	private:
		size_t mSize;
		size_t mCapacity;
		T_KEY* mKeys;
		T_VAL* mValues;
		void resize() {
			resizeTo(mCapacity * 2);
		};
		void resizeTo(int newCapacity) {
			if(newCapacity != mCapacity) {
				T_KEY* newKeys = new T_KEY[newCapacity];
				T_VAL* newValues = new T_VAL[newCapacity];

				memcpy(newKeys, mKeys, newCapacity > mCapacity ? mCapacity * sizeof(T_KEY) : newCapacity * sizeof(T_KEY));
				memcpy(newValues, mValues,  newCapacity > mCapacity ? mCapacity * sizeof(T_KEY) : newCapacity * sizeof(T_KEY));

				mCapacity = newCapacity;
				delete[] mKeys;
				delete[] mValues;

				mKeys = newKeys;
				mValues = newValues;
			}
		}
	public:
		Dictionary() : Dictionary(15) {};
		explicit Dictionary(const size_t capacity) : mCapacity(capacity), mSize(0) {
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
		bool hasKey(const T_KEY key) {
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
		void put(const T_KEY key, const T_VAL val) {
			// Override old value if it exists
			for(int i=0; i<size(); i++) {
				if(mKeys[i] == key) {
					mValues[i] = val;
					return;
				}
			}

			// Add new Key-Value pair
			if(isFull()) resize();
			mKeys[size()] = key;
			mValues[size()] = val;
			mSize++;
		};
		void putAll(const int entryc, T_KEY keys[], T_VAL values[], bool fit) {
			if(fit) {
				
			} else {
				int newCapacity = mCapacity;
				int overflow = mCapacity - (mSize + entryc);
				while(overflow > 0) {
					newCapacity *= 2;
					overflow = newCapacity - (mSize + entryc);
				}
				if(newCapacity > mCapacity) resizeTo(newCapacity);
			}

			for(int i=0; i<entryc; i++) {
				put(keys[i], values[i]);
			}
		}
		T_VAL* get(const T_KEY key) {
			for(int i=0; i<size(); i++) {
				if(mKeys[i] == key) {
					return &mValues[i];
				}
			}
			return NULL;
		};
};

#endif