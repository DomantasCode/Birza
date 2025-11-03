cmake_minimum_required(VERSION 3.30)
project(StockMarketSimulator)

set(CMAKE_CXX_STANDARD 11)

add_executable(StockMarketSimulator
    main.cpp
    Stock.cpp
    Player.cpp
    Game.cpp
)
