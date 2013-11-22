include_directories(Common)
add_subdirectory(Common)
add_subdirectory(Game)
if(BUILD_EDITOR)
	add_subdirectory(Editor)
endif()

