add_executable (
    ${PROJECT_ID}
   
    game.h
    game.cpp
    apples.h
    apples.cpp 
    snake.cpp
    main.cpp
   
 "snake.h")

set_property (TARGET ${PROJECT_ID} PROPERTY CXX_STANDARD 20)
set_property (TARGET ${PROJECT_ID} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property (TARGET ${PROJECT_ID} PROPERTY CXX_EXTENSIONS OFF)

target_sources(
    ${PROJECT_ID}
    PRIVATE
)

target_link_libraries (
    ${PROJECT_ID}
    PRIVATE
        fmt::fmt
        SDL::SDL2
        SDL::SDL_mixer
        stb::stb
)

target_compile_definitions (
    ${PROJECT_ID}
    PRIVATE
        -DPROJECT_NAME="${PROJECT_NAME}"
)
