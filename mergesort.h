#include <iostream>
#include <vector>

void merge(std::vector<std::iostream*> &input, std::iostream &output, int chunkSize);
void splitData(std::iostream &input, std::vector<std::iostream*> &outputs, int chunkSize);
void mergeSort(std::iostream &input, std::iostream &output, int tmpStreamCount = 2);