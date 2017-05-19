#pragma once

#include <string>
#include "AFGUID.h"
namespace ArkFrame
{

enum AF_DATA_TYPE
{
    DT_UNKNOWN, //unknown type
    DT_BOOLEAN, //bool
    DT_INT, //int32_t
    DT_INT64, //int64_t
    DT_FLOAT, //float
    DT_DOUBLE, //double
    DT_STRING, //string(char*)
    DT_OBJECT, //object(ident + serial)
    DT_POINTER, //pointer(void*)
    DT_USERDATA, //user data(char*)
    DT_TABLE, //table
    DT_MAX, //max
};

const static bool NULL_BOOLEAN = false;
const static int NULL_INT = 0;
const static int64_t NULL_INT64 = 0;
const static float NULL_FLOAT = 0.0f;
const static double NULL_DOUBLE = 0.0;
const static std::string NULL_STR = "";
const static AFGUID NULL_GUID = AFGUID();

class AFIData
{
public:

public:
    AFIData& operator=(const AFIData& rhs) = delete; //��ֹ�ȺŸ�ֵ

public:
    inline static const void* GetUserData(void* value)
    {
        return (char*)value + sizeof(size_t);
    }

    inline static const size_t GetUserDataSize(void* value)
    {
        return *((size_t*)value);
    }

    inline static size_t GetRawUserDataSize(size_t size)
    {
        return sizeof(size_t) + size;
    }

    inline static void InitRawUserData(void* p, const void* pData, size_t size)
    {
        *((size_t*)p) = size;
        memcpy((char*)p + sizeof(size_t), pData, size);
    }

public:
    virtual ~AFIData() = 0;

    virtual int GetType() const = 0;

    //Get data
    virtual bool GetBool() const = 0;
    virtual int GetInt() const = 0;
    virtual int64_t GetInt64() const = 0;
    virtual float GetFloat() const = 0;
    virtual double GetDouble() const = 0;
    virtual const char* GetString() const = 0;
    virtual AFGUID GetObject() const = 0;
    virtual void* GetPointer() const = 0;
    virtual const void* GetUserData(size_t& size) const = 0;
    virtual void GetRawUserData() const = 0;

    //Set data
    virtual void SetUnknown() = 0;
    virtual void SetBool(bool value) = 0;
    virtual void SetInt(int value) = 0;
    virtual void SetInt64(int64_t value) = 0;
    virtual void SetFloat(float value) = 0;
    virtual void SetDouble(double value) = 0;
    virtual void SetString(const char* value) = 0;
    virtual void SetObject(const AFGUID& value) = 0;
    virtual void SetPointer(void* value) = 0;
    virtual void SetUserData(const void* value, size_t size) = 0;
    virtual void SetRawUserData(void* value) = 0;

    virtual void Assign(const AFIData& src) = 0;
    virtual size_t GetMemUsage() const = 0;
};

}