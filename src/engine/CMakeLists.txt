add_library( tagallery_engine STATIC
    Engine.cpp
    Engine.hpp
    Gallery.cpp
    Gallery.hpp
)

target_compile_features( tagallery_engine PUBLIC cxx_std_17 )
target_link_libraries( tagallery_engine PRIVATE SQLiteCpp sqlite3 )
