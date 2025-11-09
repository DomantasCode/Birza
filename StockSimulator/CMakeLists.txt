cmake_minimum_required(VERSION 3.30)
project(StockSimulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(StockSimulator main.cpp
        Player.cpp
        Player.h
        Stock.cpp
        Stock.h
        Game.cpp
        Game.h)
