set(dir "${PROJECT_SOURCE_DIR}/BackprojectionFDK")
message("core dir: ${dir}")

file(GLOB core_header
    "${dir}/*.h"
    "${dir}/*.hpp"
	"${dir}/*.cuh"
)
file(GLOB core_src
    "${dir}/*.cpp"
    "${dir}/*.cu"
)

set(core_src ${core_header} ${core_src})
source_group(core FILES ${core_src})
