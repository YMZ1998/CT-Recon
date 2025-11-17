include(${PROJECT_SOURCE_DIR}/BackprojectionFDK/src.cmake)

project(FDK LANGUAGES CXX CUDA)

# 启用 CUDA 支持
enable_language(CUDA)

# 头文件目录
include_directories("${PROJECT_SOURCE_DIR}/BackprojectionFDK")
include_directories("${PROJECT_BINARY_DIR}")

# 宏定义
add_definitions(-DCT_RECON_CORE_SHARED_LIBS_EXPORT)
add_definitions(-D_BIND_TO_CURRENT_VCLIBS_VERSION=1)
add_definitions(-D_UNICODE -DUNICODE)

add_library(FDK SHARED ${core_src})

# 设置 CUDA 编译选项
set_target_properties(FDK PROPERTIES
  CUDA_SEPARABLE_COMPILATION ON
  CUDA_ARCHITECTURES "native"
)

find_package(Boost REQUIRED COMPONENTS filesystem system)

target_link_libraries(FDK PRIVATE 
	Boost::filesystem 
	Boost::system
	Qt5::Core
	Qt5::Gui
	Version.lib
)

install(FILES ${core_header} DESTINATION include)
install(TARGETS FDK
  RUNTIME DESTINATION bin/$<CONFIG>
  LIBRARY DESTINATION lib/$<CONFIG>
  ARCHIVE DESTINATION lib/$<CONFIG>
)
