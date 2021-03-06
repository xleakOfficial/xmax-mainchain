set(current_lib_name proto_base)

file (GLOB SOURCE_FILES "*.cpp")
file (GLOB HEADERS "include/*.hpp")
file (GLOB PROTO_SOURCE_FILES "${PROTO_BUILD_DIR}/*.cc")
file (GLOB PROTO_HEADERS_FILES "${PROTO_BUILD_DIR}/*.h")

source_group( 
	src
	FILES 
	${SOURCE_FILES}
	"CMakeLists.txt"
)

source_group(
    include
    FILES
    ${HEADERS}
)

source_group(
    protos
    FILES
    ${PROTO_SOURCE_FILES}
    ${PROTO_HEADERS_FILES}
)

add_library( ${current_lib_name} 
    ${SOURCE_FILES} 
    ${HEADERS} 
    ${PROTO_SOURCE_FILES} 
    ${PROTO_HEADERS_FILES}
    )


target_include_directories(${current_lib_name} 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROTO_BUILD_DIR}
        )

target_link_libraries( ${current_lib_name}
        ${xmax_core_lib_name} 
        ${Boost_LIBRARIES}
        libprotobuf
	    libprotoc
 )

set_target_properties( ${current_lib_name} PROPERTIES PUBLIC_HEADER "${HEADERS}" FOLDER "1.Foundation")


install( TARGETS 
${current_lib_name}

RUNTIME DESTINATION bin 
LIBRARY DESTINATION lib 
ARCHIVE DESTINATION lib 
)