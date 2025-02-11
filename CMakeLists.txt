# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)  # Importa o SDK do Pico

project(Embarca_ServoMotor C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Inicializa o SDK do Pico
pico_sdk_init()

# Adiciona o executável com os arquivos do projeto
add_executable(Embarca_ServoMotor
    Embarca_ServoMotor.c
)

# Vincula as bibliotecas necessárias
target_link_libraries(Embarca_ServoMotor
pico_stdlib
pico_time
hardware_irq
hardware_pwm)


# Garante que os binários e UF2 sejam gerados corretamente
pico_add_extra_outputs(Embarca_ServoMotor)


