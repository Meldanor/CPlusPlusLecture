#include <string>
#include "bitarray.hpp"
#include <iostream>

namespace BiA {
/// \brief Creates a bitarray with at least enough space for numElements
/// bits.
/// \details You have to delete the BitArray with delete!
///
///		 Create sets all bits to 0.
BitArray BiA::create(int numElements) {
	// 1 - size variable
	// numElements/32 - number of uint32_t for all bits rounded down
	// round up:  (numElements+31)/32
	int numInts = 1 + ((numElements + 31) / 32);
	BitArray theNewOne = new uint32_t[numInts];
	theNewOne[0] = numElements;
	memset(theNewOne + 1, 0, numInts * 4 - 4);
	return theNewOne;
}

/// \brief Returns the number of elements in the array.
///
int BiA::getSize(const BitArray& array) {
	return array[0];
}

/// \brief Check if the bit is set to 1.
///
bool BiA::get(const BitArray& array, int index) {
	// First index is the number of the array
	// index / 32 = position in the array == index >> 5
	int arrayPos = (index >> 5) + 1;
	int bitPos = (index % 32);

	// Select the single bit at the position
	return (array[arrayPos] & (1 << bitPos));
}

/// \brief Set a bit to a value (true=1/false=0)
///
void BiA::set(BitArray& array, int index, bool value) {
	// First index is the number of the array
	// index / 32 = position in the array == index >> 5
	int arrayPos = (index >> 5) + 1;
	int bitPos = (index % 32);
	// Set the bit at the position
	if (value)
		array[arrayPos] |= (1 << bitPos);
	else
		array[arrayPos] &= ~(1 << bitPos);
}

/// \brief Invert the bit at index.
///
void BiA::toggle(BitArray& array, int index) {
	BiA::set(array, index, !(BiA::get(array, index)));
}

/// \brief Create a new array containing all elements of the two arrays
///		from input.
BitArray BiA::concatenate(const BitArray& array1, const BitArray& array2) {
	// 1 - size variable
	// numElements/32 - number of uint32_t for all bits rounded down
	// round up:  (numElements+31)/32
	int numElements = BiA::getSize(array1) + BiA::getSize(array2);
	BitArray theNewOne = BiA::create(numElements);
	int k = 0;
	// Very dirty - but steady as she go!
	for (int i = 0; i < BiA::getSize(array1); ++i, ++k)
		BiA::set(theNewOne, k, BiA::get(array1, i));
	for (int i = 0; i < BiA::getSize(array2); ++i, ++k)
		BiA::set(theNewOne, k, BiA::get(array2, i));
	return theNewOne;
}

/// \brief Combine two arrays with a logically or.
/// \details If the arrays have a different size use the larger one as
///		reference. The smaller array is continued with zeros.
///
///		The result has to be written into array1. If array 1 is the smaller
///		one you must replace its memory. Make sure there is no memory
///		leak or access voilation.
///
///		Remark: this function is bad software design. Returning a new array
///		would be a better choice, but the exercise gain is higher in that
///		way.
void BiA::logicalOr(BitArray& array1, const BitArray& array2) {
	// Resize array 1
	if (BiA::getSize(array1) < BiA::getSize(array2)) {
		// Create bigger array
		BitArray temp = BiA::create(BiA::getSize(array2));
		// Copy values to from array 1 to temp array
		for (int i = 1; i < BiA::getSize(array1); ++i) {
			temp[i] = array1[i];
		}
		delete[] array1;
		array1 = temp;
	}

	// DO THE OR
	int arraySize = BiA::getSize(array1) / 32 + 1;
	for (int i = 1; i < arraySize; ++i) {
		array1[i] |= array2[i];
	}
}
}
;
