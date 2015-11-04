#include "FileFilter.hpp"

int main () {
    std::ifstream inFile;

    Copy justCopy;
    std::ofstream copyFile;
    copyFile.open("outCopy.txt");
    inFile.open("sample.txt");
    justCopy.doFilter(inFile, copyFile);
    inFile.close();
    copyFile.close();

    UpperCase justUpper;
    std::ofstream upperFile;
    upperFile.open("upperCopy.txt");
    inFile.open("sample.txt");
    justUpper.doFilter(inFile, upperFile);
    inFile.close();
    upperFile.close();

    Encrypt justEncrypt;
    std::ofstream encryptFile;
    encryptFile.open("encryptCopy.txt");
    inFile.open("sample.txt");
    justEncrypt.doFilter(inFile, encryptFile);
    inFile.close();
    encryptFile.close();

}