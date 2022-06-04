#pragma once

// Get the least significant bit that is on
template <typename T> T IsPowerOfTwo(T &t) { return t & (t - 1); }

// Get the least significant bit that is on
template <typename T> T LowestBitSet(T &t) { return t & (-t); }

// Get the least significant bit that is off
template <typename T> T LowestBitNotSet(T &t) { return ~t & (t + 1); }

// Clear the least significant bit that is on
template <typename T> T ClearLowestBitSet(T &t) { return t & (t - 1); }

// Set the least significant bit that is off
template <typename T> T SetLowestBitNotSet(T &t) { return t | (t + 1); }

// Clear the last consecutive bits that are on
template <typename T> T ClearLowestBitsSet(T &t) { return t & (t + 1); }

// Set the last consecutive bits that are off
template <typename T> T SetLowestBitsNotSet(T &t) { return t | (t - 1); }
