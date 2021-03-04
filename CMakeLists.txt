cmake_minimum_required( VERSION 3.9 )
set(PROJECT_NAME mouse_toucher )
project( ${PROJECT_NAME} )

set( CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -rdynamic" )
set( CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3 -rdynamic -s" )
set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -rdynamic")
set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -rdynamic" )

if( UNIX )
	if( CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.9 )
		set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color")
		set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++11")
		set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11" )
	else( CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.9 )
		set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++0x")
		set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++0x" )
	endif( CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.9 )
	set( CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined" )
else( UNIX )
	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_IE=0x0600" )
endif( UNIX )

# sources to include in project
set( SOURCE
app.cpp
mtaskbaricon.cpp
)

# reduce warnings while linking
if( UNIX )
	set( CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined" )
endif( UNIX )

set(LINK_FLAGS ${LINK_FLAGS} "-Wl,-whole-archive")

include_directories(
${PROJECT_SOURCE_DIR}
${CMAKE_BINARY_DIR}/generated
${CMAKE_SOURCE_DIR}/include
)

find_package(wxWidgets)
include(${wxWidgets_USE_FILE})

#turn on ccach if installed
find_program( CCACHE_FOUND ccache )
if( CCACHE_FOUND )
    set_property( GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache )
    set_property( GLOBAL PROPERTY RULE_LAUNCH_LINK ccache )
endif( CCACHE_FOUND )

##########################################################
add_executable( ${PROJECT_NAME} ${SOURCE} )

target_link_libraries( 	${PROJECT_NAME}
						${Boost_LIBRARIES}
						${CURL_LIBRARIES}
						${LIBXML2_LIBRARIES}
						${wxWidgets_LIBRARIES}
)
