cmake_minimum_required(VERSION 3.16)

project(ertp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Qt6Network Qt6Concurrent)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network Concurrent)

find_package(OpenSSL REQUIRED)


set(PROJECT_SOURCES
       pingdialog.h
       pingdialog.cpp
       main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt6 REQUIRED COMPONENTS Core)

    qt_add_executable(ertp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        passphrasedialog.h passphrasedialog.cpp
        stegengine.h stegengine.cpp
        constants.h constants.cpp
        resources.qrc
        icmpstegengine.cpp icmpstegengine.h
        pingdialog.cpp pingdialog.h
        ipfilter.cpp ipfilter.h
        udpstegengine.cpp udpstegengine.h
        ertp_structs.h
        dnsstegengine.cpp dnsstegengine.h
        httpstegengine.cpp httpstegengine.h
    )

else()
    if(ANDROID)
        add_library(ertp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ertp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ertp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets OpenSSL::SSL OpenSSL::Crypto Qt6::Network Qt6::Concurrent)
target_link_libraries(ertp PRIVATE Qt6::Core)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ertp)
endif()
set_target_properties(ertp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ertp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ertp)
endif()
