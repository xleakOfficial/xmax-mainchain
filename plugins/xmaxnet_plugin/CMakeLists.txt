set(current_lib_name ${xmax_net_lib_name})


file(GLOB HEADERS "include/*.hpp")
file (GLOB SOURCE_FILES "*.cpp")


source_group( 
	include
	FILES 
	${HEADERS}
)

source_group( 
	src
	FILES 
	${SOURCE_FILES}
	"CMakeLists.txt"
)

add_library( ${current_lib_name} ${SOURCE_FILES} ${HEADERS} )

add_definitions(-DMINIUPNP_STATICLIB)

target_link_libraries( ${current_lib_name}
    ${Boost_LIBRARIES}
	${xmax_app_lib_name}
	proto_base
)

target_include_directories( ${current_lib_name} 
	PUBLIC  "include"  "${Boost_INCLUDE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" 
		)
target_include_directories( ${current_lib_name}  
	PUBLIC "include" ${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/miniupnp/include )		
		

set_target_properties( ${current_lib_name} PROPERTIES PUBLIC_HEADER "${HEADERS}" FOLDER "5.Plugins")