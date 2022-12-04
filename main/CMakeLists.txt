## >>>>>>>>>>>>>>>
## >>>>>>>>>>>>>>>
add_library(libreria dummy.cpp "funciones.cpp")
## <<<<<<<<<<<<<<<
## <<<<<<<<<<<<<<<

target_include_directories(libreria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
## >>>>>>>>>>>>>>>
## >>>>>>>>>>>>>>>
add_executable(main main.cpp)
## <<<<<<<<<<<<<<<
## <<<<<<<<<<<<<<<

target_link_libraries(main iri libreria)