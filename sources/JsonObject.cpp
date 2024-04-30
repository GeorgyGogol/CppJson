#include "JsonObject.h"

json::JsonObject::JsonObject(const JsonObject& src) noexcept
{
    JsonProperties = src.JsonProperties;
}

json::JsonObject& json::JsonObject::operator=(const JsonObject& src) noexcept
{
    if (this != &src) {
        JsonProperties = src.JsonProperties;
    }
    return *this;
}

json::JsonObject& json::JsonObject::operator=(JsonObject&& from) noexcept
{
    //if (this != &from) {
    JsonProperties = from.JsonProperties;
    //}
    return *this;
}

void json::JsonObject::add(const std::string& propertyName, ObjectValueType value) noexcept
{
    JsonProperties[propertyName] = value;
}

void json::JsonObject::add(const std::string& propertyName) noexcept
{
    ObjectValueType nullValue;
    nullValue.setNull();
    JsonProperties[propertyName] = nullValue;
}

void json::JsonObject::set(const std::string& propertyName, ObjectValueType value) noexcept
{
    JsonProperties[propertyName] = value;
}

json::ObjectValueType json::JsonObject::get(const std::string& propertyName) const noexcept
{
    ObjectValueType out = JsonProperties.at(propertyName);
    return out;
}

json::ObjectValueType& json::JsonObject::getRef(const std::string& propertyName)
{
    return JsonProperties[propertyName];
}

bool json::JsonObject::isExists(const std::string& propertyName) const noexcept
{
    return JsonProperties.find(propertyName) != JsonProperties.end();
}

json::JsonType json::JsonObject::Type() const noexcept
{
    return json::JsonType::Object;
}

std::string json::JsonObject::toString() const noexcept
{
    std::string out;

    out += "{";

    auto last = JsonProperties.end();
    last--;
    for (auto it = JsonProperties.begin(); it != JsonProperties.end(); ++it)
    {
        out += "\"" + it->first + "\":";

        ObjectValueType value = it->second;
        if (value.isNull()) {
            out += "null";
        }
        else if (value.isString()) {
            out += "\"" + value.getStr() + "\"";
        }
        else {
            out += value.getStr();
        }

        if (it != last) {
            out += ",";
        }
    }

    out += "}";

    return out;
}

int json::JsonObject::count() const noexcept
{
    return int(JsonProperties.size());
}

