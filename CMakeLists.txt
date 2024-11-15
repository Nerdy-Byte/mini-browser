cmake_minimum_required(VERSION 3.16)

project(untitled VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DYYDEBUG=1")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




# Add Network along with Widgets
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

# Find the libcurl package
find_package(CURL REQUIRED)

# Find Flex and Bison packages
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

include_directories("/opt/homebrew/opt/libomp/include")
link_directories("/opt/homebrew/opt/libomp/lib")
find_package(OpenMP REQUIRED)



# Generate parser and lexer from Bison and Flex files
BISON_TARGET(Parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(Lexer lex.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

include_directories(${CMAKE_SOURCE_DIR} ${CURL_INCLUDE_DIRS})

set(PROJECT_SOURCES
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    dom_creater.h
    dom_creater.cpp
    dom_tree.h
    renderer.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp   # Generated Bison parser
    ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp    # Generated Flex lexer
)


set_property(SOURCE main.cpp PROPERTY SKIP_AUTOMOC ON)
set_property(SOURCE renderer.cpp PROPERTY SKIP_AUTOMOC ON)

string(REPLACE "-fcolor-diagnostics" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
string(REPLACE "-fno-color-diagnostics" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DYYDEBUG=1")


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(untitled
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        input.html
        renderer.cpp
        pages.h
        lex.l parser.y

    )
else()
    if(ANDROID)
        add_library(untitled SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(untitled
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link the Qt Widgets, Network, and Curl libraries
target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network CURL::libcurl)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.untitled)
endif()

set_target_properties(untitled PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS untitled
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(untitled)
endif()
