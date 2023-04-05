add_library( tagallery_engine STATIC
    Access.cpp
    Access.hpp
    Engine.cpp
    Engine.hpp
    Gallery.cpp
    Gallery.hpp
    Internals.cpp
    Internals.hpp
    Item.cpp
    Item.hpp
    Platform.hpp
    platform/PlatformWindows.cpp
    Statements.hpp
    Tag.cpp
    Tag.hpp
    TagType.cpp
    TagType.hpp
)

target_compile_features( tagallery_engine PUBLIC cxx_std_17 )
target_link_libraries( tagallery_engine PRIVATE SQLiteCpp sqlite3 )
