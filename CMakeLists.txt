cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

set(DEBUG_OPTIONS -Wall)
set(RELEASE_OPTIONS -m64 -O2)

project(tester)

# --------------------------------------------------------------------------------------------------------------------------

add_executable(main)
target_sources(main PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/numeral_system_converter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/sorting/Bubble_Coctail_EvenOddSort_Combo.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/sorting/Insert_Selection_Merge.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/sorting/Shell_Quick.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/graph_theory/DFS_BFS.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/graph_theory/Dijkstra_FloydWarshall.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/garbage/graph_theory/Kraskal_Prim.cpp
	
	
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
	
	
	${CMAKE_CURRENT_SOURCE_DIR}/entry/main.cpp
)
target_compile_definitions(main PUBLIC -D__RTTR_TEST_OFF__)

target_compile_options(main PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}>")
target_compile_options(main PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>")

# --------------------------------------------------------------------------------------------------------------------------