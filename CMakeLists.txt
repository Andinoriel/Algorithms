cmake_minimum_required(VERSION 3.8)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(DEBUG_OPTIONS -m64 -Wall -Wextra -pedantic -Werror)
set(RELEASE_OPTIONS -m64 -O2)

project(algorithms)
add_subdirectory(3rd_party/sfml)
add_subdirectory(3rd_party/Box2D-cmake)

add_definitions(-DDISABLE_OLD_EP)

# ======================================== EXECUTABLES ======================================== 			

add_executable(patterns-t)
add_executable(garbage-t-wht-sfml)
add_executable(garbage-t-w-sfml)
add_executable(templates-t)
add_executable(box2d-sfml-t)

# =============================================================================================


# ======================================== TARGETS=======================================

# excluded from any target:
#   - Algorithms/garbage/__oth/Feature20.cpp
#   - Algorithms/garbage/__oth/boost-serialization.cpp
#   - Algorithms/garbage/re-asm/taicall/...
#	...

target_sources(patterns-t PRIVATE	
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/creational/AbstractFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/creational/Builder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/creational/FactoryMethod.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/creational/Prototype.cpp
	
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/structural/Adapter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/structural/Bridge.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/structural/Composite.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/structural/Decorator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/structural/Facade.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/structural/Flyweight.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/structural/Proxy.cpp
	
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/behavioral/Command.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/behavioral/CoR.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/behavioral/Mediator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/behavioral/Memento.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/behavioral/Observer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/behavioral/State.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/behavioral/Strategy.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/behavioral/TemplateMethod.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/patterns/behavioral/Visitor.cpp	

	
	${CMAKE_CURRENT_SOURCE_DIR}/src/main-patterns.cpp
)
target_sources(garbage-t-wht-sfml PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/__oth/numeral-system-converter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/sorting/Bubble-Coctail-EvenOddSort-Combo.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/sorting/Insert-Selection-Merge.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/sorting/Shell-Quick.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/graph-theory/DFS-BFS.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/graph-theory/Dijkstra-FloydWarshall.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/graph-theory/Kraskal-Prim.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/main-garbage.cpp
)
target_sources(garbage-t-w-sfml PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/sfml/shape-fun/RandomF.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/sfml/shape-fun/Circle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/sfml/shape-fun/Square.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/sfml/shape-fun/demo1.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/sfml/shape-fun/demo2.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/main-sfml.cpp
)
target_sources(templates-t PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main-templates.cpp
)
target_sources(box2d-sfml-t PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/box2d-sfml-tests/main.cpp
)

# =======================================================================================


# ======================================== LINKING LIB ========================================			

target_link_libraries(garbage-t-w-sfml sfml-graphics)
# target_link_libraries(garbage-t-w-sfml sfml-audio)

target_link_libraries(box2d-sfml-t sfml-graphics)
# target_link_libraries(box2d-sfml-t sfml-audio)
target_link_libraries(box2d-sfml-t tobanteGaming::Box2D)

# =============================================================================================

add_compile_options("$<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}>")
add_compile_options("$<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>")