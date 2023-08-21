add_executable(self_balancing_robot)

pico_generate_pio_header(self_balancing_robot ${CMAKE_CURRENT_LIST_DIR}/quadrature_encoder.pio)

target_sources(self_balancing_robot PRIVATE main.cpp)

target_link_libraries(self_balancing_robot PRIVATE
        pico_stdlib
        pico_multicore
        hardware_pio
        )

# create map/bin/hex file etc.
pico_add_extra_outputs(self_balancing_robot)
