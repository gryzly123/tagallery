set( sources
        ${CMAKE_CURRENT_LIST_DIR}/Application.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Application.hpp
        ${CMAKE_CURRENT_LIST_DIR}/GalleryWindow.cpp
        ${CMAKE_CURRENT_LIST_DIR}/GalleryWindow.hpp
        ${CMAKE_CURRENT_LIST_DIR}/MainFrame.cpp
        ${CMAKE_CURRENT_LIST_DIR}/MainFrame.hpp
        ${CMAKE_CURRENT_LIST_DIR}/TagListView.cpp
        ${CMAKE_CURRENT_LIST_DIR}/TagListView.hpp
)

#source_group( ui ${sources} )
target_sources( tagallery PRIVATE ${sources} )
