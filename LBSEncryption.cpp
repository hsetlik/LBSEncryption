#include "LBSEncryption.h"

LBSEncryptBase::LBSEncryptBase()
{

}

LBSEncryptBase::~LBSEncryptBase()
{

}

void LBSEncryptBase::encryptBlock (char* data, size_t totalDataSize, size_t startByte, size_t numBytesToSwap)
{
    firstIdx = startByte;
    secondIdx = startByte + (255 - numBytesToSwap);
    firstIdxEnd = firstIdx + numBytesToSwap;
    while (firstIdx < firstIdxEnd) {
        firstChar = data[firstIdx];
        secondChar = data[secondIdx];

        data[secondIdx] = firstChar;
        data[firstIdx] = secondChar;
        firstIdx++;
        secondIdx++;
    }
}
//==========================================================================================================
LBSSingleKey::LBSSingleKey(std::string k) : key(k)
{

}

void LBSSingleKey::encryptFile(std::string source, std::string dest)
{
    std::ifstream file(source, std::ios::binary | std::ios::ate);
    const size_t size = (size_t)file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);
    int bytesToSwap = 0;
    if (file.read(buffer.data(), size))
    {
        std::cout << "Successfully read " << size << " bytes from file: " << source << "\n";
        int numBlocks = floor (size / 256);
        for (size_t block = 0; block < numBlocks; block++)
        {
            bytesToSwap = (int)key[block % key.length()] % 128;
            encryptBlock(buffer.data(), size, 256 * block, bytesToSwap);
        }
    }
}
//==========================================================================================================
LBSDoubleKey::LBSDoubleKey(std::string key1, std::string key2) : keyA(key1), keyB(key2)
{

}


void LBSDoubleKey::encryptFile(std::string source, std::string dest)
{
    
}