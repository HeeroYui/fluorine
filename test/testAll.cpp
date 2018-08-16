/**
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include "fluorine/Variant.hpp"
#include <etest/etest.hpp>

TEST(constructor, testUndefined) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}

TEST(constructor, testBoolean) {
	fluorine::Variant element(false);
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), true);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}

TEST(constructor, testInt) {
	fluorine::Variant element(int_t(-9123456789LL));
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), true);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}


TEST(constructor, testUnsignedInt) {
	fluorine::Variant element(uint_t(9123456789UL));
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), true);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}

TEST(constructor, testFloat) {
	fluorine::Variant element(float_t(76543.7654));
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), true);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}


TEST(constructor, testRawPointer) {
	fluorine::Variant element((void*)654321);
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), true);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}


TEST(constructor, testString_1) {
	fluorine::Variant element("HGFDSQ");
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), true);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}

TEST(constructor, testString_2) {
	fluorine::Variant element(etk::String("HGFDSQ"));
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), true);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}

TEST(constructor, testColor) {
	fluorine::Variant element(etk::Color<>(55,55,55,65));
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), true);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}

TEST(constructor, testVec2) {
	fluorine::Variant element(vec2(43.6f,65.0f));
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), true);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}

TEST(constructor, testIVec2) {
	fluorine::Variant element(ivec2(43,65));
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), true);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}

TEST(constructor, testVec3) {
	fluorine::Variant element(vec3(43.6f, 65.0f, 333.6f));
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), true);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), false);
}

TEST(constructor, testIVec3) {
	fluorine::Variant element(ivec3(43, 65, 333));
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), true);
	EXPECT_EQ(element.isNull(), false);
}

TEST(constructor, testNull) {
	fluorine::Variant element(null);
	EXPECT_EQ(element.isUndefined(), false);
	EXPECT_EQ(element.isBoolean(), false);
	EXPECT_EQ(element.isInt(), false);
	EXPECT_EQ(element.isUInt(), false);
	EXPECT_EQ(element.isFloat(), false);
	EXPECT_EQ(element.isRawPointer(), false);
	EXPECT_EQ(element.isString(), false);
	EXPECT_EQ(element.isColor(), false);
	EXPECT_EQ(element.isVec2(), false);
	EXPECT_EQ(element.isIVec2(), false);
	EXPECT_EQ(element.isVec3(), false);
	EXPECT_EQ(element.isIVec3(), false);
	EXPECT_EQ(element.isNull(), true);
}







TEST(constructor, testBooleanValue) {
	fluorine::Variant element(false);
	EXPECT_EQ(element.getBoolean(), false);
	element = true;
	EXPECT_EQ(element.getBoolean(), true);
}

TEST(constructor, testIntValue) {
	fluorine::Variant element(int_t(-9123456789LL));
	EXPECT_EQ(element.getInt(), int_t(-9123456789LL));
}


TEST(constructor, testUnsignedIntValue) {
	fluorine::Variant element(uint_t(9123456789UL));
	EXPECT_EQ(element.getUInt(), uint_t(9123456789UL));
}

TEST(constructor, testFloatValue) {
	fluorine::Variant element(float_t(76543.7654));
	EXPECT_EQ(element.getFloat(), float_t(76543.7654));
}


TEST(constructor, testRawPointerValue) {
	fluorine::Variant element((void*)654321);
	EXPECT_EQ(element.getRawPointer(), (void*)654321);
}


TEST(constructor, testString_1Value) {
	fluorine::Variant element("HGFDSQ");
	EXPECT_EQ(element.getString(), "HGFDSQ");
}

TEST(constructor, testString_2Value) {
	fluorine::Variant element(etk::String("HGFDSQ"));
	EXPECT_EQ(element.getString(), "HGFDSQ");
}

TEST(constructor, testColorValue) {
	fluorine::Variant element(etk::Color<>(55,55,55,65));
	EXPECT_EQ(element.getColor(), etk::Color<>(55,55,55,65));
}

TEST(constructor, testVec2Value) {
	fluorine::Variant element(vec2(43.6f,65.0f));
	EXPECT_EQ(element.getVec2(), vec2(43.6f,65.0f));
}

TEST(constructor, testIVec2Value) {
	fluorine::Variant element(ivec2(43,65));
	EXPECT_EQ(element.getIVec2(), ivec2(43,65));
}

TEST(constructor, testVec3Value) {
	fluorine::Variant element(vec3(43.6f, 65.0f, 333.6f));
	EXPECT_EQ(element.getVec3(), vec3(43.6f, 65.0f, 333.6f));
}

TEST(constructor, testIVec3Value) {
	fluorine::Variant element(ivec3(43, 65, 333));
	EXPECT_EQ(element.getIVec3(), ivec3(43, 65, 333));
}







TEST(constructor, testBooleanValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = false;
	EXPECT_EQ(element.getBoolean(), false);
	element = true;
	EXPECT_EQ(element.getBoolean(), true);
}

TEST(constructor, testIntValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = int_t(-9123456789LL);
	EXPECT_EQ(element.getInt(), int_t(-9123456789LL));
}


TEST(constructor, testUnsignedIntValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = uint_t(9123456789UL);
	EXPECT_EQ(element.getUInt(), uint_t(9123456789UL));
}

TEST(constructor, testFloatValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = float_t(76543.7654);
	EXPECT_EQ(element.getFloat(), float_t(76543.7654));
}


TEST(constructor, testRawPointerValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = (void*)654321;
	EXPECT_EQ(element.getRawPointer(), (void*)654321);
}


TEST(constructor, testString_1ValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = "HGFDSQ";
	EXPECT_EQ(element.getString(), "HGFDSQ");
}

TEST(constructor, testString_2ValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = etk::String("HGFDSQ");
	EXPECT_EQ(element.getString(), "HGFDSQ");
}

TEST(constructor, testColorValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = etk::Color<>(55,55,55,65);
	EXPECT_EQ(element.getColor(), etk::Color<>(55,55,55,65));
}

TEST(constructor, testVec2ValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = vec2(43.6f,65.0f);
	EXPECT_EQ(element.getVec2(), vec2(43.6f,65.0f));
}

TEST(constructor, testIVec2ValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = ivec2(43,65);
	EXPECT_EQ(element.getIVec2(), ivec2(43,65));
}

TEST(constructor, testVec3ValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = vec3(43.6f, 65.0f, 333.6f);
	EXPECT_EQ(element.getVec3(), vec3(43.6f, 65.0f, 333.6f));
}

TEST(constructor, testIVec3ValueOperator) {
	fluorine::Variant element;
	EXPECT_EQ(element.isUndefined(), true);
	element = ivec3(43, 65, 333);
	EXPECT_EQ(element.getIVec3(), ivec3(43, 65, 333));
}





