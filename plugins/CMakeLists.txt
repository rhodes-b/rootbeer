set(PROJECT rootbeer-plugins)
project(${PROJECT})

add_library(${PROJECT} STATIC plugins.c)
target_include_directories(${PROJECT} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    "${LUAJIT_INCLUDE_DIR}"
)

target_link_libraries(${PROJECT} PRIVATE ${LUAJIT_LIBRARIES})

macro(link_rootbeer_plugin target)
    target_link_libraries(rootbeer-plugins PUBLIC ${target})
    # add_dependencies(${PROJECT} ${target})
endmacro()

add_subdirectory(example_plugin)


