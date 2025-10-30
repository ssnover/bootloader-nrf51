export ARM_TOOLS_PREFIX := "/usr/bin"

cmake:
    cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=cmake/arm-cortex-m.toolchain.cmake -DCMAKE_BUILD_TYPE=Release

build: cmake
    cd build && make -j
    arm-none-eabi-objcopy -O binary build/minimal.elf build/minimal.bin

run: build
    qemu-system-arm -M microbit -device loader,file=build/minimal.bin

clean:
    rm -rf build