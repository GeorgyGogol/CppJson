#include "JsonArray.h"

json::JsonArray::JsonArray(const JsonArray &src) noexcept
{
    Storage = src.Storage;
}

json::JsonArray& json::JsonArray::operator=(const JsonArray& src) noexcept
{
    if (this != &src) {
        Storage = src.Storage;
    }
    return *this;
}

json::JsonArray& json::JsonArray::operator=(JsonArray&& from) noexcept
{
    Storage = from.Storage;
    return *this;
}

void json::JsonArray::add(ObjectValueType value) noexcept
{
    Storage.push_back(value);
}

void json::JsonArray::set(int pos, ObjectValueType value)
{
    Storage[pos] = value;
}

json::ObjectValueType json::JsonArray::get(int pos) const
{
    ObjectValueType out = Storage.at(pos);
    return out;
}

json::ObjectValueType& json::JsonArray::getRef(int pos)
{
    return Storage[pos];
}

#pragma region JsonBase
json::JsonType json::JsonArray::Type() const noexcept
{
    return json::JsonType::Array;
}

std::string json::JsonArray::toString() const noexcept
{
    std::string out;

    out += "[";

    auto last = Storage.end();
    --last;
    for (auto it = Storage.begin(); it != Storage.end(); ++it)
    {
        if (it->isString()) {
            out += "\"" + it->getStr() + "\"";
        }
        else {
            out += it->getStr();
        }

        if (it != last) {
            out += ",";
        }
    }

    out += "]";

    return out;
}

int json::JsonArray::count() const noexcept
{
    return int(Storage.size());
}
#pragma endregion

