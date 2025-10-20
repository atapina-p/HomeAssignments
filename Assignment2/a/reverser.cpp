/*
* Polina Atapina
* st139859@student.spbu.ru
* My project number two(a)
*/


#include "reverser.h"
#include <fstream>
#include <filesystem>
#include <algorithm>


void TextReverse(){
    std::ifstream infile; // declare input file

    infile.open("source.pdf", std::ios::binary|std::ios::in); // determine input file
    int fileSize = std::filesystem::file_size("source.pdf");

    char* fileArray = new char[fileSize]; // select an array with a length of the file size
    infile.read(fileArray, fileSize); // reading the file into an array
    
    std::reverse(fileArray, fileArray + fileSize);

    std::ofstream outfile; // declare output file
    outfile.open("temp.pdf", std::ios::binary|std::ios::out); // determine output file
    infile.read(fileArray, fileSize);
    outfile.write(fileArray, fileSize);

    // free up memory
    delete[] fileArray;

    // close used files
    infile.close();
    outfile.close();
}
