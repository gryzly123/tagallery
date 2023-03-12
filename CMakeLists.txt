cmake_minimum_required( VERSION 3.21 )
project( tagallery LANGUAGES CXX )
set_property( GLOBAL PROPERTY USE_FOLDERS ON )

set( wxUSE_STL ON )
#set( wxUSE_GUI ON )
set( wxBUILD_SHARED OFF )
set( wxBUILD_DEMOS OFF )
set( wxBUILD_PRECOMP OFF )
set( wxBUILD_TESTS "OFF" )
set( wxBUILD_SAMPLES "OFF" )
add_subdirectory( contrib/wx )

set( SQLITECPP_BUILD_EXAMPLES OFF )
set( SQLITECPP_BUILD_TESTS OFF )
add_subdirectory( contrib/SQLiteCpp )

add_subdirectory( src )
