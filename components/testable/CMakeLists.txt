# set(COMPONENT_REQUIRES)
# set(COMPONENT_PRIV_REQUIRES)

# set(COMPONENT_SRCS "mean.c")
# set(COMPONENT_ADD_INCLUDEDIRS ".")

# register_component()
idf_component_register(SRCS "mean.c"
                    INCLUDE_DIRS "include")