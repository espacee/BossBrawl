include_directories(Common)
add_subdirectory(Common)

if(${BUILD_GAME})
    add_subdirectory(Game)
endif()

if(${BUILD_EDITOR})
    add_subdirectory(Editor)
endif()
