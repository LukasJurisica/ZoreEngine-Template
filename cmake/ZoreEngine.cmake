if (TARGET ZoreEngine)
	return()
endif()

message(STATUS "First-party (external): creating target 'ZoreEngine'")

include(CPM)
CPMAddPackage(
    NAME ZoreEngine
    GITHUB_REPOSITORY LukasJurisica/ZoreEngine
    GIT_TAG 8543720
)