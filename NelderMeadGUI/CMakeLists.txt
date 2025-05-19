cmake_minimum_required(VERSION 3.5)
project(NelderMeadGUI)

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

# Линковка с DLL (Windows)
if(WIN32)
    # Путь к .lib файлу
    link_directories(${CMAKE_SOURCE_DIR}/lib)

    # Имя библиотеки без расширения
    target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/lib/NelderMeadOptimizer.lib")

    # Копирование DLL в папку сборки
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_SOURCE_DIR}/lib/NelderMeadOptimizer.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()
