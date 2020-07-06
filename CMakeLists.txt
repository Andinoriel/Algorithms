cmake_minimum_required(VERSION 3.8)

project(algorithms)

add_subdirectory(3rd_party/sfml)
add_subdirectory(3rd_party/Box2D-cmake)

option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." FALSE)
if(${FORCE_COLORED_OUTPUT})
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
       add_compile_options(-fdiagnostics-color=always)
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       add_compile_options(-fcolor-diagnostics)
    endif()
endif()

# ======================================== TARGETS ======================================== 			

add_executable(patterns-t)
add_executable(garbage-t-wht-sfml)
add_executable(garbage-t-w-sfml)
add_executable(templates-t)
add_executable(box2d-sfml-t)
add_executable(crypto-t)

target_compile_features(patterns-t 			PUBLIC cxx_std_17)
target_compile_features(garbage-t-wht-sfml 	PUBLIC cxx_std_17)
target_compile_features(garbage-t-w-sfml 	PUBLIC cxx_std_17)
target_compile_features(templates-t 		PUBLIC cxx_std_17)
target_compile_features(box2d-sfml-t 		PUBLIC cxx_std_17)
target_compile_features(crypto-t 			PUBLIC cxx_std_17)

# =========================================================================================


# ======================================== SOURCES =======================================

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
target_sources(crypto-t PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/crypto/md5.c

	${CMAKE_CURRENT_SOURCE_DIR}/src/main-crypto.c
)

# =======================================================================================


# ======================================== LINKING LIB ========================================			

target_link_libraries(garbage-t-w-sfml sfml-graphics)
# target_link_libraries(garbage-t-w-sfml sfml-audio)

target_link_libraries(box2d-sfml-t sfml-graphics)
# target_link_libraries(box2d-sfml-t sfml-audio)
target_link_libraries(box2d-sfml-t tobanteGaming::Box2D)

# =============================================================================================
