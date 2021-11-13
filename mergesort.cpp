#include "mergesort.h"

#include <cstring>
#include <cstdint>
#include <algorithm>
#include <list>
#include <cmath>
#include <fstream>

using namespace std;

unsigned fileSize(iostream &file)
{
    file.seekg(0, ios_base::end);
    unsigned size = file.tellg();
    file.seekg(0, ios_base::beg);
    return size;
}

vector<iostream*> getTmpReadonly(unsigned count)
{
    vector<iostream*> tmpFiles;
    for (int i = 0; i < count; ++i)
    {
        const string filename = std::to_string(i) + "tmp.txt";
        tmpFiles.push_back(new fstream(filename, ios_base::in));
    }
    return tmpFiles;
}

vector<iostream*> getTmpWriteonly(unsigned count)
{
    vector<iostream*> tmpFiles;
    for (int i = 0; i < count; ++i)
    {
        const string filename = std::to_string(i) + "tmp.txt";
        tmpFiles.push_back(new fstream(filename, ios_base::out));
    }
    return tmpFiles;
}

void deleteTmp(vector<iostream*> &array)
{
    for (int i = 0; i < array.size(); ++i)
        delete array[i];
}

void mergeSort(iostream &input, iostream &output, int tmpStreamCount)
{
    size_t size = fileSize(input);

    if(size < 2)
        return;

    vector<iostream*> tmpFiles = getTmpWriteonly(tmpStreamCount);
    fstream tmpOutput("tmp_out.txt", ios_base::out);
    splitData(input, tmpFiles, 1);

    deleteTmp(tmpFiles);
    tmpFiles = getTmpReadonly(tmpStreamCount);
    merge(tmpFiles, tmpOutput, 1);

    for (size_t i = 1; std::pow(2, i - 1) < size / 2; ++i)
    {
        const int chunkSize = std::pow(2, i);

        tmpOutput.close();
        tmpOutput.open("tmp_out.txt", ios_base::in);

        deleteTmp(tmpFiles);
        tmpFiles = getTmpWriteonly(tmpStreamCount);
        splitData(tmpOutput, tmpFiles, chunkSize);

        tmpOutput.close();
        tmpOutput.open("tmp_out.txt", ios_base::out);

        deleteTmp(tmpFiles);
        tmpFiles = getTmpReadonly(tmpStreamCount);
        merge(tmpFiles, tmpOutput, chunkSize);
    }

    tmpOutput.close();
    tmpOutput.open("tmp_out.txt", ios_base::in);

    char chr;
    while(tmpOutput.get(chr))
        output.put(chr);
}

void merge(vector<iostream *> &input, iostream &output, int chunkSize)
{
    while (!std::all_of(input.begin(), input.end(), [](iostream *stream)
                        { return stream->eof(); }))
    {
        list<iostream *> streams;
        std::copy_if(input.begin(), input.end(), std::back_inserter(streams),
                     [](iostream *stream)
                     { return !stream->eof(); });

        int i = 0;
        vector<char> buffer(streams.size() * chunkSize, 0);
        for (auto &stream : streams)
        {
            stream->read(buffer.data() + i * chunkSize, chunkSize);
            i += 1;

            if (stream->get() && !stream->fail())
                stream->seekg(-1, ios_base::cur);
        }

        for (auto iter = buffer.begin(); iter != buffer.end();)
        {
            if (*iter == 0)
                iter = buffer.erase(iter);
            else
                ++iter;
        }

        std::sort(buffer.begin(), buffer.end());
        output.write(buffer.data(), buffer.size());
    }
}

void splitData(iostream &input, vector<iostream *> &outputs, int chunkSize)
{
    char *buffer = new char[chunkSize + 1];
    int i = 0;

    while (!input.eof())
    {
        input.get(buffer, chunkSize + 1, '\0');
        int readLength = strlen(buffer);

        outputs[i]->write(buffer, readLength);
        i = (i + 1) % outputs.size();
    }

    delete[] buffer;
}