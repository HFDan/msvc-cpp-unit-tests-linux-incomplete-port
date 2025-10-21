target_sources(
        "${${PROJECT_NAME}_INTERNAL_LIB_NAME}"
        PRIVATE
        "${PROJECT_SOURCE_DIR}/src/MainImpl.cpp"
        "${PROJECT_SOURCE_DIR}/src/TestRegistry.cpp"
)