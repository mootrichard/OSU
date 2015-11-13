#ifndef FILETEST_HPP
#define FILETEST_HPP
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class FileTest {
  public:
    FileTest();
    void openFile();
    void createFile();
    int searchValue();
    void sortValue();

  private:
    std::string fileInName;
    std::string fileOutName;
    std::ifstream fileIn;
    std::ofstream fileOut;
};

#endif // FILETEST_HPP
