#include "ObjectValueType.h"
#include "JsonObject.h"
#include "JsonArray.h"
#include <exception>
#include <future>
#include <cmath>

json::ObjectValueType::ObjectValueType()
    : CurrentType(ValueTypes::None)
{
    StrData.clear();
}

json::ObjectValueType::~ObjectValueType()
{
    if (pJson) delete pJson;
}

json::ObjectValueType::ObjectValueType(const ObjectValueType& src) noexcept
{
    CurrentType = src.CurrentType;
    NumberData = src.NumberData;
    StrData = src.StrData;
    CopyJsonBase(src.pJson);
}

json::ObjectValueType::ObjectValueType(ObjectValueType&& src) noexcept
{
    CurrentType = src.CurrentType;
    NumberData = src.NumberData;
    StrData = src.StrData;

    if (pJson) delete pJson;
    pJson = src.pJson;
    src.pJson = nullptr;
}

json::ObjectValueType& json::ObjectValueType::operator=(const ObjectValueType& src) noexcept
{
    if (this != &src) {
        CurrentType = src.CurrentType;
        NumberData = src.NumberData;
        StrData = src.StrData;
        CopyJsonBase(src.pJson);
    }
    return *this;
}

bool json::ObjectValueType::operator==(const ObjectValueType& aim) const noexcept
{
    if (CurrentType != aim.CurrentType) return false;

    switch (CurrentType)
    {
    case ValueTypes::None:
        return true;

    case ValueTypes::Int:
    case ValueTypes::Double:
        return NumberData == aim.NumberData;

    case ValueTypes::String:
        return StrData == aim.StrData;

    case ValueTypes::Boolean:
        return getBool() == aim.getBool();

    case ValueTypes::JsonObject:
    case ValueTypes::JsonArray:
        return pJson == aim.pJson;

    default:
        return false;
    }
}

bool json::ObjectValueType::operator!=(const ObjectValueType& aim) const noexcept
{
    return !(*this == aim);
}

json::ObjectValueType::ObjectValueType(int data) noexcept
    : CurrentType(ValueTypes::Int)
    , NumberData(data)
{
    StrData.clear();
}

json::ObjectValueType& json::ObjectValueType::operator=(int data) noexcept
{
    CurrentType = ValueTypes::Int;
    NumberData = data;
    StrData.clear();
    if (pJson) {
        delete pJson;
        pJson = nullptr;
    }
    return *this;
}

bool json::ObjectValueType::operator==(int data) const noexcept
{
    return CurrentType == ValueTypes::Int ? int(NumberData) == data : false;
}

bool json::ObjectValueType::operator!=(int data) const noexcept
{
    return !(*this == data);
}

json::ObjectValueType::ObjectValueType(double data) noexcept
    : CurrentType(ValueTypes::Double)
    , NumberData(data)
{
    StrData.clear();
}

json::ObjectValueType& json::ObjectValueType::operator=(double data) noexcept
{
    CurrentType = ValueTypes::Double;
    NumberData = data;
    StrData.clear();
    if (pJson) {
        delete pJson;
        pJson = nullptr;
    }
    return *this;
}

bool json::ObjectValueType::operator==(double data) const noexcept
{
    return CurrentType == ValueTypes::Double ? NumberData == data : false;
}

bool json::ObjectValueType::operator!=(double data) const noexcept
{
    return !(*this == data);
}

json::ObjectValueType::ObjectValueType(const char data[]) noexcept
    : CurrentType(ValueTypes::String)
{
    NumberData = 0;
    StrData = std::string(data);
    if (pJson) {
        delete pJson;
        pJson = nullptr;
    }
}

bool json::ObjectValueType::operator==(const char data[]) const noexcept
{
    if (CurrentType != ValueTypes::String) return false;
    int dataSize = std::find(data, data + int(std::pow(2, sizeof(std::size_t) * 8)), 0) - data;

    if (StrData.size() != dataSize) return false;

    bool isEqual = true;
    const char* original = StrData.c_str();
    while (isEqual && *original != 0)
    {
        isEqual = *original == *data;
        data++;
        original++;
    }

    return isEqual;
}

bool json::ObjectValueType::operator!=(const char data[]) const noexcept
{
    return !(*this == data);
}

json::ObjectValueType::ObjectValueType(const std::string &data) noexcept
    : CurrentType(ValueTypes::String)
{
    NumberData = 0;
    StrData = data;
    if (pJson) {
        delete pJson;
        pJson = nullptr;
    }
}

bool json::ObjectValueType::operator==(const std::string &data) const noexcept
{
    if (CurrentType != ValueTypes::String) return false;
    if (StrData.size() != data.size()) return false;

    return StrData == data;
}

bool json::ObjectValueType::operator!=(const std::string &data) const noexcept
{
    return !(*this == data);
}

json::ObjectValueType::ObjectValueType(bool data) noexcept
    : CurrentType(ValueTypes::Boolean)
{
    NumberData = data ? 1.0 : 0.0;
    StrData.clear();
}

json::ObjectValueType &json::ObjectValueType::operator=(bool data) noexcept
{
    CurrentType = ValueTypes::Boolean;
    NumberData = data ? 1.0 : 0.0;
    StrData.clear();
    if (pJson) {
        delete pJson;
        pJson = nullptr;
    }
    return *this;
}

bool json::ObjectValueType::operator==(bool data) const noexcept
{
    if (CurrentType != ValueTypes::Boolean) return false;
    return getBool() == data;
}

bool json::ObjectValueType::operator!=(bool data) const noexcept
{
    return !(*this == data);
}

json::ObjectValueType::ObjectValueType(JsonBase* pData) noexcept
{
    NumberData = 0;
    StrData.clear();

    if (pJson) {
        delete pJson;
        pJson = nullptr;
    }

    if (pData->Type() == json::JsonType::Object) CurrentType = ValueTypes::JsonObject;
    else CurrentType = ValueTypes::JsonArray;
    
    CopyJsonBase(pData);
    //pJson = pData;
    //pData = nullptr;
}

json::ObjectValueType::ObjectValueType(const JsonObject& data) noexcept
    : CurrentType(ValueTypes::JsonObject)
{
    NumberData = 0;
    StrData.clear();

    if (pJson) {
        delete pJson;
        pJson = nullptr;
    }
    pJson = new JsonObject(data);
}

json::ObjectValueType::ObjectValueType(const JsonArray& data) noexcept
    : CurrentType(ValueTypes::JsonArray)
{
    NumberData = 0;
    StrData.clear();

    if (pJson) {
        delete pJson;
        pJson = nullptr;
    }
    pJson = new JsonArray(data);
}

void json::ObjectValueType::CopyJsonBase(JsonBase* aim) noexcept
{
    if (pJson) {
        delete pJson;
        pJson = nullptr;
    }

    if (!aim) return;

    switch (aim->Type())
    {
    case JsonType::Array:
        pJson = new JsonArray(*(static_cast<JsonArray*>(aim)));
        break;

    case JsonType::Object:
        pJson = new JsonObject(*(static_cast<JsonObject*>(aim)));
        break;
    }
}

bool json::ObjectValueType::isValide() const noexcept
{
    return CurrentType != ValueTypes::None;
}

json::ValueTypes json::ObjectValueType::getType() const noexcept
{
    return CurrentType;
}

bool json::ObjectValueType::isNull() const noexcept
{
    return CurrentType == ValueTypes::Null;
}

bool json::ObjectValueType::isNumber() const noexcept
{
    return 
        CurrentType == ValueTypes::Int || 
        CurrentType == ValueTypes::Double
        ;
}

bool json::ObjectValueType::isString() const noexcept
{
    return CurrentType == ValueTypes::String;
}

bool json::ObjectValueType::isBool() const noexcept
{
    return CurrentType == ValueTypes::Boolean;
}

bool json::ObjectValueType::isJsonObject() const noexcept
{
    return CurrentType == ValueTypes::JsonObject;
}

bool json::ObjectValueType::isJsonArray() const noexcept
{
    return CurrentType == ValueTypes::JsonArray;
}

bool json::ObjectValueType::isJson() const noexcept
{
    return CurrentType == ValueTypes::JsonObject || CurrentType == ValueTypes::JsonArray;
}

int json::ObjectValueType::getInt() const
{
    switch (CurrentType)
    {
    case ValueTypes::Int:
    case ValueTypes::Double:
        return int(NumberData);

    case ValueTypes::String:
        return std::stoi(StrData);

    case ValueTypes::Null:
    case ValueTypes::None:
    default:
        throw std::future_error(std::error_code());
    }
}

double json::ObjectValueType::getDouble() const
{
    switch (CurrentType)
    {
    case ValueTypes::Int:
        return double(NumberData);

    case ValueTypes::Double:
        return NumberData;

    case ValueTypes::String:
        return std::stod(StrData);

    case ValueTypes::Null:
    case ValueTypes::None:
    default:
        throw std::future_error(std::error_code());
    }
}

std::string json::ObjectValueType::getStr() const
{
    switch (CurrentType)
    {
    case ValueTypes::Null:
        return std::string("null");

    case ValueTypes::Int:
        return std::to_string(int(NumberData));

    case ValueTypes::Double:
        return std::to_string(NumberData);

    case ValueTypes::String:
        return StrData;

    case ValueTypes::JsonObject:
    case ValueTypes::JsonArray:
        return pJson->toString();

    case ValueTypes::None:
    default:
        throw std::future_error(std::error_code());
    }
}

bool json::ObjectValueType::getBool() const
{
    return NumberData != 0.0;
}

json::JsonObject& json::ObjectValueType::getJsonObject() const
{
    if (CurrentType != ValueTypes::JsonObject)
        throw std::future_error(std::error_code());

    return *(static_cast<JsonObject*>(pJson));
}

json::JsonArray& json::ObjectValueType::getJsonArray() const
{
    if (CurrentType != ValueTypes::JsonArray)
        throw std::future_error(std::error_code());

    return *(static_cast<JsonArray*>(pJson));
}

void json::ObjectValueType::setNull() noexcept
{
    CurrentType = ValueTypes::Null;
    NumberData = 0;
    StrData.clear();
    if (pJson) {
        delete pJson;
        pJson = nullptr;
    }
}

