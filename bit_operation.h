/*
 * bit_operation.h
 *
 *  Created on: Aug 19, 2025
 *      Author: MohsenCha
 *      Version: 1.0
 */

#ifndef BIT_OPERATION_H_
#define BIT_OPERATION_H_

#ifdef __cplusplus
extern "C" {
#endif

// Set a specific bit to 1
// Example: data = 0b00000000; BIT_SET(data, 1 << 2); // data = 0b00000100 (4)
#define BIT_SET(data,bit)	 ( (data) |= (bit) )

// Clear a specific bit to 0
// Example: data = 0b00000100; BIT_CLR(data, 1 << 2); // data = 0b00000000 (0)
#define BIT_CLR(data,bit)	 ( (data) &= ~(bit) )

// Check if a specific bit is set (returns true/false)
// Example: data = 0b00000100; BIT_CHK(data, 1 << 2); // returns true
#define BIT_CHK(data,bit)	 ( ((data) & (bit)) != 0 )

// Toggle a specific bit (0 to 1, 1 to 0)
// Example: data = 0b00000100; BIT_TOG(data, 1 << 2); // data = 0b00000000 (0)
#define BIT_TOG(data, bit)          ((data) ^= (bit))

// Set a specific bit to a given value (0 or 1)
// Example: data = 0b00000000; BIT_SET_VALUE(data, 1 << 3, 1); // data = 0b00001000 (8)
#define BIT_SET_VALUE(data, bit, value) ((data) = ((data) & ~(bit)) | ((value) ? (bit) : 0))

// Flip all bits in the variable
// Example: data = 0b00001111; BIT_FLIP(data); // data = 0b11110000 (240)
#define BIT_FLIP(data)              ((data) = ~(data))

// Set multiple bits specified by a mask to 1
// Example: data = 0b00000000; BIT_SET_MASK(data, 0b00001001); // data = 0b00001001 (9)
#define BIT_SET_MASK(data, mask)    ((data) |= (mask))

// Clear multiple bits specified by a mask to 0
// Example: data = 0b00001111; BIT_CLR_MASK(data, 0b00001100); // data = 0b00000011 (3)
#define BIT_CLR_MASK(data, mask)    ((data) &= ~(mask))

// Check if all bits specified by a mask are set
// Example: data = 0b00001101; BIT_CHK_MASK(data, 0b00001100); // returns true
#define BIT_CHK_MASK(data, mask)    (((data) & (mask)) == (mask))

// Get the value (0 or 1) of a bit at a specific position
// Example: data = 0b00001000; BIT_GET(data, 3); // returns 1
#define BIT_GET(data, pos)          (((data) >> (pos)) & 1)

// Set a range of bits to a specific value
// Example: data = 0b00000000; BIT_SET_RANGE(data, 2, 3, 0b101); // data = 0b00010100 (20)
#define BIT_SET_RANGE(data, start, width, value) ((data) = ((data) & ~(((1ULL << (width)) - 1) << (start))) | ((value) << (start)))

// Rotate bits left by shift positions within a size-bit field
// Example: data = 0b00000011; BIT_ROT_LEFT(data, 2, 8); // data = 0b00001100 (12)
#define BIT_ROT_LEFT(data, shift, size)  ((data) = (((data) << (shift)) | ((data) >> ((size) - (shift)))) & ((1ULL << (size)) - 1))

// Rotate bits right by shift positions within a size-bit field
// Example: data = 0b11000000; BIT_ROT_RIGHT(data, 2, 8); // data = 0b00110000 (48)
#define BIT_ROT_RIGHT(data, shift, size) ((data) = (((data) >> (shift)) | ((data) << ((size) - (shift)))) & ((1ULL << (size)) - 1))

#ifdef __cplusplus
}
#endif

#endif /* BIT_OPERATION_H_ */

