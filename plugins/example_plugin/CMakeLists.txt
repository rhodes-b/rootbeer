cmake_minimum_required(VERSION 3.20)
set(PROJECT example_plugin)
project(${PROJECT})

add_library(example_plugin example.c)
link_plugin(example_plugin include)
register_function(bar foo example.h)
register_function(baz baz example.h)
