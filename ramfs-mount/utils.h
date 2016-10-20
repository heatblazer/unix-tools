#ifndef UTILS_H
#define UTILS_H


/// strchr2 returns match after
/// a given count not like
/// K&R`s first occurance
/// \brief strchr2
/// \param str
/// \param c
/// \param count
/// \return positions after N count - null if no match
/// no const to make it reusable
const char *strchr2(const char* str, char c, int count);

/// my split function
/// \brief split
/// \param str - haystack
/// \param delimiter - delimter to split
/// \param ret_size - counter to iterrate the 2d arr
/// \return array of char arrays
char** split(const char* str, char delimiter, int* ret_size);

#endif
