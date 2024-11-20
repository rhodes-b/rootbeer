set(PROJECT example-plugin)
project(${PROJECT})

add_library(${PROJECT} STATIC example_plugin.c)
target_include_directories(${PROJECT} PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/"
)

target_compile_definitions(${PROJECT} PUBLIC EXAMPLE_PLUGIN_ENABLE=1)

link_rootbeer_plugin(${PROJECT})

