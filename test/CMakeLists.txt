file(GLOB TEST_SRCS "*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/BackprojectionFDK")
foreach(src_file IN LISTS TEST_SRCS)
    get_filename_component(name ${src_file} NAME_WE)
    add_executable(${name} ${src_file})
    target_link_libraries(${name} PRIVATE 
    FDK 	
    Qt5::Core
    Qt5::Gui)
    set_target_properties(${name} PROPERTIES FOLDER "test")
    message(STATUS "Added test target: ${name}")
endforeach()

source_group("Source Files" FILES ${TEST_SRCS})
