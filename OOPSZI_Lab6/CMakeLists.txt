# CMakeList.txt: проект CMake для OOPSZI_Lab6_orig; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (main "headers/AbstractQueue.hpp" "headers/Node.hpp" "headers/Queue.hpp" "src/main.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
