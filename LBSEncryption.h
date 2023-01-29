#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
class LBSEncryptBase
{
public:
    LBSEncryptBase();
    virtual ~LBSEncryptBase();
    virtual void encryptFile(std::string source, std::string dest)=0;
protected:
    void encryptBlock (char* data, size_t totalDataSize, size_t startByte, size_t numBytesToSwap);
private:
    char firstChar, secondChar;
    size_t firstIdx, secondIdx, firstIdxEnd;
};

class LBSSingleKey : public LBSEncryptBase
{
public:
    LBSSingleKey(std::string key);
    void encryptFile(std::string source, std::string dest) override; 
private:
    std::string key;

};

class LBSDoubleKey : public LBSEncryptBase
{
public:
    LBSDoubleKey(std::string key1, std::string key2);
    void encryptFile(std::string source, std::string dest) override;
private:
    std::string keyA, keyB;
    int keyIdx;

};