/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <fluorine/variantType.hpp>
#include <fluorine/debug.hpp>



etk::Stream& fluorine::operator <<(etk::Stream& _os, enum fluorine::variantType _obj) {
	switch (_obj) {
		case fluorine::variantType::Undefined:
			_os << "fluorine::variantType::Undefined";
			break;
		case fluorine::variantType::Integer:
			_os << "fluorine::variantType::Integer";
			break;
		case fluorine::variantType::UnsignedInteger:
			_os << "fluorine::variantType::UnsignedInteger";
			break;
		case fluorine::variantType::Float:
			_os << "fluorine::variantType::Float";
			break;
		case fluorine::variantType::Null:
			_os << "fluorine::variantType::Null";
			break;
		case fluorine::variantType::RawPointer:
			_os << "fluorine::variantType::RawPointer";
			break;
		case fluorine::variantType::String:
			_os << "fluorine::variantType::String";
			break;
		case fluorine::variantType::Boolean:
			_os << "fluorine::variantType::Boolean";
			break;
		case fluorine::variantType::Color:
			_os << "fluorine::variantType::Color";
			break;
		case fluorine::variantType::Vec2:
			_os << "fluorine::variantType::Vec2";
			break;
		case fluorine::variantType::IVec2:
			_os << "fluorine::variantType::IVec2";
			break;
		case fluorine::variantType::Vec3:
			_os << "fluorine::variantType::Vec3";
			break;
		case fluorine::variantType::IVec3:
			_os << "fluorine::variantType::IVec3";
			break;
	}
	return _os;
}


