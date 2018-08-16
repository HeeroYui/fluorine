/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <elog/log.hpp>

namespace fluorine {
	int32_t getLogId();
};
#define FLUORINE_BASE(info,data)  ELOG_BASE(fluorine::getLogId(),info,data)

#define FLUORINE_CRITICAL(data)      FLUORINE_BASE(1, data)
#define FLUORINE_ERROR(data)         FLUORINE_BASE(2, data)
#define FLUORINE_WARNING(data)       FLUORINE_BASE(3, data)
#ifdef DEBUG
	#define FLUORINE_INFO(data)          FLUORINE_BASE(4, data)
	#define FLUORINE_DEBUG(data)         FLUORINE_BASE(5, data)
	#define FLUORINE_VERBOSE(data)       FLUORINE_BASE(6, data)
	#define FLUORINE_TODO(data)          FLUORINE_BASE(4, "TODO : " << data)
#else
	#define FLUORINE_INFO(data)          do { } while(false)
	#define FLUORINE_DEBUG(data)         do { } while(false)
	#define FLUORINE_VERBOSE(data)       do { } while(false)
	#define FLUORINE_TODO(data)          do { } while(false)
#endif

#define FLUORINE_ASSERT(cond,data) \
	do { \
		if (!(cond)) { \
			JSON_CRITICAL(data); \
			assert(!#cond); \
		} \
	} while (0)

