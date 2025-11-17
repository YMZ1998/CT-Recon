file(GLOB TEST_SRCS "*.cpp")

find_package(Eigen3 CONFIG REQUIRED)
find_package(ArrayFire CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

include_directories("${PROJECT_SOURCE_DIR}/BackprojectionFDK")
foreach(src_file IN LISTS TEST_SRCS)
    get_filename_component(name ${src_file} NAME_WE)
    add_executable(${name} ${src_file})
    target_link_libraries(${name} PRIVATE 
    FDK 	
    Qt5::Core
    Qt5::Gui
    ArrayFire::af
    Eigen3::Eigen
    Boost::filesystem 
    Boost::system
    )
    set_target_properties(${name} PROPERTIES FOLDER "test")
    message(STATUS "Added test target: ${name}")
endforeach()

source_group("Source Files" FILES ${TEST_SRCS})
