# Create tagallery project
add_executable( tagallery WIN32 main.cpp )
add_subdirectory( ui )

# Create tagellery_engine project
add_subdirectory( engine )

# Link
target_link_libraries( tagallery PRIVATE tagallery_engine wx::core wx::base wx::aui )
