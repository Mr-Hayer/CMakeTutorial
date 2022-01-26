add_library(services ${SUBMODULESDIR}/services/services_interfaces.cpp)

target_compile_definitions(
    services
    PRIVATE
    RAW_INTERFACE_SERVICES
)