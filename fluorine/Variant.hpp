/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <etk/types.hpp>
#include <etk/Color.hpp>
#include <etk/math/Vector2D.hpp>
#include <etk/math/Vector3D.hpp>
#include <fluorine/variantType.hpp>

/**
 * @brief fluorine namespace containing all function for JSON interpretor
 */
namespace fluorine {
	union DataType {
		int_t m_int;
		uint_t m_uint;
		float_t m_float;
		bool m_boolean;
		void * m_rawPointer;
		etk::String* m_string;
		ivec2* m_ivec2;
		vec2* m_vec2;
		ivec3* m_ivec3;
		vec3* m_vec3;
		etk::Color<float>* m_colorFloat;
		etk::Color<>* m_colorInt;
	};
	/**
	 * @brief Basic main object of all json elements.
	 */
	class Variant {
		protected:
			union fluorine::DataType m_dataUnion; //!< Variant Data...
			fluorine::variantType m_dataType = fluorine::variantType::Undefined; //!< Type of the Data...
		public:
			/**
			 * @brief Get Variant type
			 * @return Type of the object
			 */
			enum fluorine::variantType getType() const;
		public:
			/**
			 * @brief Move contructor
			 * @param[in] _obj Object to move.
			 */
			Variant(Variant&& _obj);
			/**
			 * @brief Copy contructor
			 * @param[in] _obj Object to copy.
			 */
			Variant(const Variant& _obj);
			/**
			 * @brief Move operator
			 * @param[in] _obj Object to move.
			 */
			Variant& operator= (Variant&& _obj);
			/**
			 * @brief Copy operator
			 * @param[in] _obj Object to copy.
			 */
			Variant& operator= (const Variant& _obj);
			/**
			 * @brief Constuctor that generate an undefined element
			 */
			Variant();
			/**
			 * @brief Constuctor that generate a null element
			 */
			Variant(const etk::NullPtr& _value);
			/**
			 * @brief Constuctor that generate a int_t value
			 */
			Variant(const int8_t& _value);
			Variant(const int16_t& _value);
			Variant(const int32_t& _value);
			Variant(const int64_t& _value);
			/**
			 * @brief Constuctor that generate a uint_t value
			 */
			Variant(const uint8_t& _value);
			Variant(const uint16_t& _value);
			Variant(const uint32_t& _value);
			Variant(const uint64_t& _value);
			/**
			 * @brief Constuctor that generate a float_t value
			 */
			Variant(const float_t& _value);
			/**
			 * @brief Constuctor that generate a boolean value
			 */
			Variant(const bool& _value);
			/**
			 * @brief Constuctor that generate a string value
			 */
			Variant(const etk::String& _value);
			/**
			 * @brief Constuctor that generate a string value
			 */
			Variant(const char* _value);
			/**
			 * @brief Constuctor that generate a RAW pointer value
			 */
			Variant(const void* _value);
			/**
			 * @brief Constuctor that generate a vec2 value
			 */
			Variant(const vec2& _value);
			/**
			 * @brief Constuctor that generate a ivec2 value
			 */
			Variant(const ivec2& _value);
			/**
			 * @brief Constuctor that generate a vec3 value
			 */
			Variant(const vec3& _value);
			/**
			 * @brief Constuctor that generate a ivec3 value
			 */
			Variant(const ivec3& _value);
			/**
			 * @brief Constuctor that generate a etk::Color<float> value
			 */
			Variant(const etk::Color<float>& _value);
			/**
			 * @brief Constuctor that generate a etk::Color<> value
			 */
			Variant(const etk::Color<>& _value);
		public:
			/**
			 * @brief Virtualize destructor
			 */
			~Variant();
		public:
			/**
			 * @brief Get the Boolean Value.
			 * @return requested value if compatible.
			 */
			bool getBoolean() const;
			/**
			 * @brief check if the node is a fluorine::Boolean
			 * @return true if the node is a fluorine::Boolean
			 */
			bool isBoolean() const;
		public:
			/**
			 * @brief Get the int_t Value.
			 * @return requested value if compatible.
			 */
			int_t getInt() const;
			/**
			 * @brief check if the node is a fluorine::Integer
			 * @return true if the node is a fluorine::Integer
			 */
			bool isInt() const;
		public:
			/**
			 * @brief Get the uint_t Value.
			 * @return requested value if compatible.
			 */
			uint_t getUInt() const;
			/**
			 * @brief check if the node is a fluorine::UnsignedInteger
			 * @return true if the node is a fluorine::UnsignedInteger
			 */
			bool isUInt() const;
		public:
			/**
			 * @brief Get the uint_t Value.
			 * @return requested value if compatible.
			 */
			float_t getFloat() const;
			/**
			 * @brief check if the node is a fluorine::Float
			 * @return true if the node is a fluorine::Float
			 */
			bool isFloat() const;
		public:
			/**
			 * @brief Get the void* Value.
			 * @return requested value if compatible.
			 */
			void* getRawPointer() const;
			/**
			 * @brief check if the node is a fluorine::RawPointer
			 * @return true if the node is a fluorine::RawPointer
			 */
			bool isRawPointer() const;
		public:
			/**
			 * @brief Get the etk::String Value.
			 * @return requested value if compatible.
			 */
			etk::String getString() const;
			/**
			 * @brief check if the node is a fluorine::String
			 * @return true if the node is a fluorine::String
			 */
			bool isString() const;
		public:
			/**
			 * @brief Get the etk::Color Value.
			 * @return requested value if compatible.
			 */
			etk::Color<float> getColorFloat() const;
			/**
			 * @brief Get the etk::Color Value.
			 * @return requested value if compatible.
			 */
			etk::Color<> getColorInt() const;
			/**
			 * @brief Get the etk::Color Value (generic etk type).
			 * @return requested value if compatible.
			 */
			etk::Color<> getColor() const {
				return getColorInt();
			}
			/**
			 * @brief check if the node is a fluorine::ColorFloat or fluorine::ColorInt
			 * @return true if the node is a fluorine::ColorFloat or fluorine::ColorInt
			 */
			bool isColor() const;
			/**
			 * @brief check if the node is a fluorine::ColorFloat
			 * @return true if the node is a fluorine::ColorFloat
			 */
			bool isColorFloat() const;
			/**
			 * @brief check if the node is a fluorine::ColorInt
			 * @return true if the node is a fluorine::ColorInt
			 */
			bool isColorInt() const;
		public:
			/**
			 * @brief Get the vec2 Value.
			 * @return requested value if compatible.
			 */
			vec2 getVec2() const;
			/**
			 * @brief check if the node is a fluorine::Vec2
			 * @return true if the node is a fluorine::Vec2
			 */
			bool isVec2() const;
		public:
			/**
			 * @brief Get the ivec2 Value.
			 * @return requested value if compatible.
			 */
			ivec2 getIVec2() const;
			/**
			 * @brief check if the node is a fluorine::IVec2
			 * @return true if the node is a fluorine::IVec2
			 */
			bool isIVec2() const;
		public:
			/**
			 * @brief Get the vec3 Value.
			 * @return requested value if compatible.
			 */
			vec3 getVec3() const;
			/**
			 * @brief check if the node is a fluorine::Vec3
			 * @return true if the node is a fluorine::Vec3
			 */
			bool isVec3() const;
		public:
			/**
			 * @brief Get the ivec3 Value.
			 * @return requested value if compatible.
			 */
			ivec3 getIVec3() const;
			/**
			 * @brief check if the node is a fluorine::IVec3
			 * @return true if the node is a fluorine::IVec3
			 */
			bool isIVec3() const;
		public:
			/**
			 * @brief check if the node is a fluorine::Null
			 * @return true if the node is a fluorine::Null
			 */
			bool isNull() const;
		public:
			/**
			 * @brief check if the node is a fluorine::Undefined
			 * @return true if the node is a fluorine::Undefined
			 */
			bool isUndefined() const;
			/**
			 * @brief clear the Variant ==> set undefined
			 */
			Variant clone() const;
			/**
			 * @brief clear the Variant ==> set undefined
			 */
			void clear();
			/**
			 * @brief Swap 2 object Variant
			 * @param[in] second object to swap.
			 */
			void swap(Variant& _obj);
	};
	//! @not_in_doc
	etk::Stream& operator <<(etk::Stream& _os, const fluorine::Variant& _obj);
	/**
	 * @brief create an empty Variant (that does not exist:unknow ...)
	 * @return empty value (not usable)
	 */
	fluorine::Variant empty();
}
