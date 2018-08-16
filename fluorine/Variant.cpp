/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <fluorine/Variant.hpp>
#include <fluorine/debug.hpp>
#include <etk/Allocator.hpp>

fluorine::Variant fluorine::empty() {
	return fluorine::Variant();
}



etk::Stream& fluorine::operator <<(etk::Stream& _os, const fluorine::Variant& _obj) {
	switch (_obj.getType()) {
		case fluorine::variantType::Undefined:
			_os << "undefined";
			break;
		case fluorine::variantType::Integer:
			_os << _obj.getInt();
			break;
		case fluorine::variantType::UnsignedInteger:
			_os << _obj.getUInt();
			break;
		case fluorine::variantType::Float:
			_os << _obj.getFloat();
			break;
		case fluorine::variantType::Null:
			_os << "null";
			break;
		case fluorine::variantType::Boolean:
			_os << _obj.getBoolean();
			break;
		case fluorine::variantType::RawPointer:
			_os << _obj.getRawPointer();
			break;
		case fluorine::variantType::String:
			_os << _obj.getString();
			break;
		case fluorine::variantType::ColorFloat:
			_os << _obj.getColorFloat();
			break;
		case fluorine::variantType::ColorInt:
			_os << _obj.getColorInt();
			break;
		case fluorine::variantType::Vec2:
			_os << _obj.getVec2();
			break;
		case fluorine::variantType::IVec2:
			_os << _obj.getIVec2();
			break;
		case fluorine::variantType::Vec3:
			_os << _obj.getVec3();
			break;
		case fluorine::variantType::IVec3:
			_os << _obj.getIVec3();
			break;
		default:
			_os << "<<ERROR VARIANT>>";
			break;
	}
	return _os;
}

void fluorine::Variant::swap(Variant& _obj) {
	etk::swap(m_dataUnion, _obj.m_dataUnion);
	etk::swap(m_dataType, _obj.m_dataType);
}

enum fluorine::variantType fluorine::Variant::getType() const {
	return m_dataType;
}

fluorine::Variant::Variant(Variant&& _obj) {
	m_dataUnion.m_rawPointer = null;
	etk::swap(*this, _obj);
}
/**
* @brief Copy contructor
* @param[in] _obj Object to copy.
*/
fluorine::Variant::Variant(const Variant& _obj) {
	fluorine::Variant tmp = _obj.clone();
	etk::swap(*this, tmp);
}


fluorine::Variant& fluorine::Variant::operator= (Variant&& _obj) {
	etk::swap(*this, _obj);
	return *this;
}

fluorine::Variant& fluorine::Variant::operator= (const Variant& _obj) {
	fluorine::Variant tmp = _obj.clone();
	etk::swap(*this, tmp);
	return *this;
}

fluorine::Variant fluorine::Variant::clone() const {
	switch (getType()) {
		case fluorine::variantType::Undefined:
			return fluorine::Variant{};
		case fluorine::variantType::Integer:
			return fluorine::Variant{getInt()};
		case fluorine::variantType::UnsignedInteger:
			return fluorine::Variant{getUInt()};
		case fluorine::variantType::Float:
			return fluorine::Variant{getFloat()};
		case fluorine::variantType::Null:
			return fluorine::Variant{null};
		case fluorine::variantType::Boolean:
			return fluorine::Variant{getBoolean()};
		case fluorine::variantType::RawPointer:
			return fluorine::Variant{getRawPointer()};
		case fluorine::variantType::String:
			return fluorine::Variant{getString()};
		case fluorine::variantType::ColorFloat:
			return fluorine::Variant{getColorFloat()};
		case fluorine::variantType::ColorInt:
			return fluorine::Variant{getColorInt()};
		case fluorine::variantType::Vec2:
			return fluorine::Variant{getVec2()};
		case fluorine::variantType::IVec2:
			return fluorine::Variant{getIVec2()};
		case fluorine::variantType::Vec3:
			return fluorine::Variant{getVec3()};
		case fluorine::variantType::IVec3:
			return fluorine::Variant{getIVec3()};
	}
	return fluorine::Variant();
}

void fluorine::Variant::clear() {
	switch (getType()) {
		case fluorine::variantType::Undefined:
		case fluorine::variantType::Integer:
		case fluorine::variantType::UnsignedInteger:
		case fluorine::variantType::Float:
		case fluorine::variantType::Null:
		case fluorine::variantType::Boolean:
		case fluorine::variantType::RawPointer:
			break;
		case fluorine::variantType::String:
			ETK_DELETE(etk::String, m_dataUnion.m_string);
			break;
		case fluorine::variantType::ColorFloat:
			ETK_DELETE(etk::Color<float>, m_dataUnion.m_colorFloat);
			break;
		case fluorine::variantType::ColorInt:
			ETK_DELETE(etk::Color<>, m_dataUnion.m_colorInt);
			break;
		case fluorine::variantType::Vec2:
			ETK_DELETE(vec2, m_dataUnion.m_vec2);
			break;
		case fluorine::variantType::IVec2:
			ETK_DELETE(ivec2, m_dataUnion.m_ivec2);
			break;
		case fluorine::variantType::Vec3:
			ETK_DELETE(vec3, m_dataUnion.m_vec3);
			break;
		case fluorine::variantType::IVec3:
			ETK_DELETE(ivec3, m_dataUnion.m_ivec3);
			break;
	}
	m_dataUnion.m_rawPointer = null;
}


fluorine::Variant::Variant():
  m_dataType(fluorine::variantType::Undefined) {
	m_dataUnion.m_rawPointer = null;
}

fluorine::Variant::Variant(const etk::NullPtr&):
  m_dataType(fluorine::variantType::Null) {
	m_dataUnion.m_rawPointer = null;
}

fluorine::Variant::Variant(const int8_t& _value):
  m_dataType(fluorine::variantType::Integer) {
	m_dataUnion.m_int = _value;
}
fluorine::Variant::Variant(const int16_t& _value):
  m_dataType(fluorine::variantType::Integer) {
	m_dataUnion.m_int = _value;
}
fluorine::Variant::Variant(const int32_t& _value):
  m_dataType(fluorine::variantType::Integer) {
	m_dataUnion.m_int = _value;
}
fluorine::Variant::Variant(const int64_t& _value):
  m_dataType(fluorine::variantType::Integer) {
	m_dataUnion.m_int = _value;
}

fluorine::Variant::Variant(const uint8_t& _value):
  m_dataType(fluorine::variantType::UnsignedInteger) {
	m_dataUnion.m_uint = _value;
}
fluorine::Variant::Variant(const uint16_t& _value):
  m_dataType(fluorine::variantType::UnsignedInteger) {
	m_dataUnion.m_uint = _value;
}
fluorine::Variant::Variant(const uint32_t& _value):
  m_dataType(fluorine::variantType::UnsignedInteger) {
	m_dataUnion.m_uint = _value;
}
fluorine::Variant::Variant(const uint64_t& _value):
  m_dataType(fluorine::variantType::UnsignedInteger) {
	m_dataUnion.m_uint = _value;
}

fluorine::Variant::Variant(const float_t& _value):
  m_dataType(fluorine::variantType::Float) {
	m_dataUnion.m_float = _value;
}

fluorine::Variant::Variant(const bool& _value):
  m_dataType(fluorine::variantType::Boolean) {
	m_dataUnion.m_boolean = _value;
}

fluorine::Variant::Variant(const etk::String& _value):
  m_dataType(fluorine::variantType::String) {
	m_dataUnion.m_string = ETK_NEW(etk::String, _value);
}

fluorine::Variant::Variant(const char* _value):
  m_dataType(fluorine::variantType::String) {
	m_dataUnion.m_string = ETK_NEW(etk::String, _value);
}

fluorine::Variant::Variant(const void* _value):
  m_dataType(fluorine::variantType::RawPointer) {
	m_dataUnion.m_rawPointer = (void*)_value;
}

fluorine::Variant::Variant(const vec2& _value):
  m_dataType(fluorine::variantType::Vec2) {
	m_dataUnion.m_vec2 = ETK_NEW(vec2, _value);
}

fluorine::Variant::Variant(const ivec2& _value):
  m_dataType(fluorine::variantType::IVec2) {
	m_dataUnion.m_ivec2 = ETK_NEW(ivec2, _value);
}

fluorine::Variant::Variant(const vec3& _value):
  m_dataType(fluorine::variantType::Vec3) {
	m_dataUnion.m_vec3 = ETK_NEW(vec3, _value);
}

fluorine::Variant::Variant(const ivec3& _value):
  m_dataType(fluorine::variantType::IVec3) {
	m_dataUnion.m_ivec3 = ETK_NEW(ivec3, _value);
}

fluorine::Variant::Variant(const etk::Color<float>& _value):
  m_dataType(fluorine::variantType::ColorFloat) {
	m_dataUnion.m_colorFloat = ETK_NEW(etk::Color<float>, _value);
}
fluorine::Variant::Variant(const etk::Color<>& _value):
  m_dataType(fluorine::variantType::ColorInt) {
	m_dataUnion.m_colorInt = ETK_NEW(etk::Color<>, _value);
}

fluorine::Variant::~Variant() {
	clear();
}

bool fluorine::Variant::getBoolean() const {
	return m_dataUnion.m_boolean;
}

bool fluorine::Variant::isBoolean() const {
	return m_dataType == fluorine::variantType::Boolean;
}

int_t fluorine::Variant::getInt() const {
	return m_dataUnion.m_int;
}

bool fluorine::Variant::isInt() const {
	return m_dataType == fluorine::variantType::Integer;
}

uint_t fluorine::Variant::getUInt() const {
	return m_dataUnion.m_uint;
}

bool fluorine::Variant::isUInt() const {
	return m_dataType == fluorine::variantType::UnsignedInteger;
}

float_t fluorine::Variant::getFloat() const {
	return m_dataUnion.m_float;
}

bool fluorine::Variant::isFloat() const {
	return m_dataType == fluorine::variantType::Float;
}

void* fluorine::Variant::getRawPointer() const {
	return m_dataUnion.m_rawPointer;
}

bool fluorine::Variant::isRawPointer() const {
	return m_dataType == fluorine::variantType::RawPointer;
}

etk::String fluorine::Variant::getString() const {
	return *(m_dataUnion.m_string);
}

bool fluorine::Variant::isString() const {
	return m_dataType == fluorine::variantType::String;
}

etk::Color<float> fluorine::Variant::getColorFloat() const {
	if (m_dataType == fluorine::variantType::ColorFloat) {
		return *(m_dataUnion.m_colorFloat);
	}
	return *(m_dataUnion.m_colorInt);
}
etk::Color<> fluorine::Variant::getColorInt() const {
	if (m_dataType == fluorine::variantType::ColorFloat) {
		return *(m_dataUnion.m_colorFloat);
	}
	return *(m_dataUnion.m_colorInt);
}

bool fluorine::Variant::isColor() const {
	return    m_dataType == fluorine::variantType::ColorFloat
	       || m_dataType == fluorine::variantType::ColorInt;
}
bool fluorine::Variant::isColorFloat() const {
	return m_dataType == fluorine::variantType::ColorFloat;
}
bool fluorine::Variant::isColorInt() const {
	return m_dataType == fluorine::variantType::ColorInt;
}

vec2 fluorine::Variant::getVec2() const {
	return *(m_dataUnion.m_vec2);
}

bool fluorine::Variant::isVec2() const {
	return m_dataType == fluorine::variantType::Vec2;
}

ivec2 fluorine::Variant::getIVec2() const {
	return *(m_dataUnion.m_ivec2);
}

bool fluorine::Variant::isIVec2() const {
	return m_dataType == fluorine::variantType::IVec2;
}

vec3 fluorine::Variant::getVec3() const {
	return *(m_dataUnion.m_vec3);
}

bool fluorine::Variant::isVec3() const {
	return m_dataType == fluorine::variantType::Vec3;
}

ivec3 fluorine::Variant::getIVec3() const {
	return *(m_dataUnion.m_ivec3);
}

bool fluorine::Variant::isIVec3() const {
	return m_dataType == fluorine::variantType::IVec3;
}

bool fluorine::Variant::isNull() const {
	return m_dataType == fluorine::variantType::Null;
}

bool fluorine::Variant::isUndefined() const {
	return m_dataType == fluorine::variantType::Undefined;
}

