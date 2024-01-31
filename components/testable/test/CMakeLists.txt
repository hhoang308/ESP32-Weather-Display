# set(COMPONENT_REQUIRES cmock testable)
# set(COMPONENT_PRIV_REQUIRES)

# set(COMPONENT_SRCS "test_mean.c" ".")
# set(COMPONENT_ADD_INCLUDEDIRS ".")

# register_component()
idf_component_register(SRC_DIRS "."
                    INCLUDE_DIRS "."
                    REQUIRES cmock testable)