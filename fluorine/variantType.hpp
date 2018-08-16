/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <etk/Stream.hpp>

namespace fluorine {
	/**
	 * @brief Type of the JSON elements.
	 */
	enum class variantType {
		Undefined, //!< Undefined Value ...
		Integer, //!< int_t value
		UnsignedInteger, //!< uint_t value
		Float, //!< Float value (double)
		Null, //!< Null value
		RawPointer, //!< Void * pointer
		String,  //!< String element
		Boolean, //!< Boolean element
		Color, //!< Color RGBA float element
		Vec2, //!< 2D vector Position (float)
		IVec2, //!< 2D vector Position (integer)
		Vec3, //!< 3D vector Position (float)
		IVec3, //!< 3D vector Position (integer)
	};
	//! @not_in_doc
	etk::Stream& operator <<(etk::Stream& _os, enum variantType _obj);
}

