if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Quake/quakedef.h")
	file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/Quake/quakedef.h" IRONWAIL_VERSION_MAJOR_LINE REGEX "^#define[ \t]+IRONWAIL_VER_MAJOR[ \t]+[0-9]+$")
	file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/Quake/quakedef.h" IRONWAIL_VERSION_MINOR_LINE REGEX "^#define[ \t]+IRONWAIL_VER_MINOR[ \t]+[0-9]+$")
	file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/Quake/quakedef.h" IRONWAIL_VERSION_PATCH_LINE REGEX "^#define[ \t]+IRONWAIL_VER_PATCH[ \t]+[0-9]+$")
	string(REGEX REPLACE "^#define[ \t]+IRONWAIL_VER_MAJOR[ \t]+([0-9]+)$" "\\1" IRONWAIL_VERSION_MAJOR "${IRONWAIL_VERSION_MAJOR_LINE}")
	string(REGEX REPLACE "^#define[ \t]+IRONWAIL_VER_MINOR[ \t]+([0-9]+)$" "\\1" IRONWAIL_VERSION_MINOR "${IRONWAIL_VERSION_MINOR_LINE}")
	string(REGEX REPLACE "^#define[ \t]+IRONWAIL_VER_PATCH[ \t]+([0-9]+)$" "\\1" IRONWAIL_VERSION_PATCH "${IRONWAIL_VERSION_PATCH_LINE}")
	set(IRONWAIL_VERSION ${IRONWAIL_VERSION_MAJOR}.${IRONWAIL_VERSION_MINOR}.${IRONWAIL_VERSION_PATCH})
	unset(IRONWAIL_VERSION_MAJOR_LINE)
	unset(IRONWAIL_VERSION_MINOR_LINE)
	unset(IRONWAIL_VERSION_PATCH_LINE)
	unset(IRONWAIL_VERSION_MAJOR)
	unset(IRONWAIL_VERSION_MINOR)
	unset(IRONWAIL_VERSION_PATCH)
endif() 
