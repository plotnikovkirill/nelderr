cmake_minimum_required(VERSION 3.5)
project(NelderMeadGUI)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections")


add_compile_definitions(QT_NO_DEBUG_OUTPUT)
add_compile_options(-Os)  # Оптимизация по размеру




# Настройка Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Добавляем исходники
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
)

# Подключаем Qt
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)

# Путь к заголовкам DLL
target_include_directories(${PROJECT_NAME} PRIVATE include)
if(MINGW)
    add_compile_options(-Wa,-mbig-obj)
endif()
# Линковка с DLL (Windows)
if(WIN32)
    # Путь к .lib файлу
    link_directories(${CMAKE_SOURCE_DIR}/lib)

    # Имя библиотеки
    target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/lib/NelderMeadOptimizer.lib")

    # Копирование DLL в папку сборки
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_SOURCE_DIR}/lib/NelderMeadOptimizer.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()
