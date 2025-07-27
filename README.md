# Advanced Linux Course - Lab Solutions

**Author**: Mohamad Nour Shahin  
**Course**: Advanced Linux Programming  
**Academic Year**: Third Year, Second Semester  

## 📋 Overview

This repository contains comprehensive solutions for 5 advanced Linux programming assignments, covering essential topics in system programming, kernel development, embedded systems, and reverse engineering.

## 🗂️ Repository Structure

```log
advanced-linux/
├── Lab01/          # ELF Dependency Analyzer (bldd)
├── Lab02/          # Reverse Engineering with GDB
├── Lab03/          # Kernel Booting & Embedded Systems
├── Lab04/          # Kernel Module Development
├── Lab05/          # Advanced Kernel Modules
└── README.md
```

## 🚀 Lab Descriptions

### Lab 01: ELF Dependency Analyzer (`bldd`)

**Topic**: Binary Analysis & Dependency Tracking

- **Description**: Implementation of a "backward ldd" tool that scans directories for ELF binaries and identifies shared library dependencies
- **Technologies**: Python, LIEF library, ELF format analysis
- **Features**:
  - Multi-architecture support (x86, x86_64, ARMv7, AArch64)
  - Text and PDF report generation
  - Comprehensive dependency mapping
- **Key Files**: [`bldd_tool.py`](Lab01/bldd_tool.py), [`Lab_solution.md`](Lab01/Lab_solution.md)

### Lab 02: Reverse Engineering with GDB

**Topic**: Binary Reverse Engineering & Security Analysis

- **Description**: Comprehensive reverse engineering exercise using GDB and GHIDRA
- **Technologies**: GDB, GHIDRA, Python binary patching
- **Features**:
  - Dynamic analysis and debugging
  - Keygen development
  - Binary patching techniques
  - Security vulnerability analysis
- **Key Files**: [`Lab_Solution.md`](Lab02/Lab_Solution.md)

### Lab 03: Kernel Booting & Embedded Systems

**Topic**: Embedded Linux Boot Process

- **Description**: Complete embedded Linux boot chain implementation
- **Technologies**: U-Boot, Linux Kernel, BusyBox, QEMU
- **Features**:
  - U-Boot bootloader compilation
  - Linux kernel 6.15 cross-compilation for ARM
  - Custom initramfs creation
  - Multi-partition SD card image generation
  - QEMU-based system emulation
- **Key Files**: [`Lab_solution.md`](Lab03/Lab_solution.md)

### Lab 04: Kernel Module Development

**Topic**: Character Device Drivers & Kernel Programming

- **Description**: Integer stack implementation as a kernel module with IOCTL interface
- **Technologies**: Linux Kernel Module API, Character Devices, IOCTL
- **Features**:
  - Kernel-space integer stack data structure
  - Character device driver implementation
  - Custom IOCTL command interface
  - Userspace CLI application
- **Key Files**: [`int_stack.c`](Lab04/int_stack.c), [`kernel_stack.c`](Lab04/kernel_stack.c), [`Lab_solution.md`](Lab04/Lab_solution.md)

### Lab 05: Advanced Kernel Modules

**Topic**: Multi-Module Kernel Development

- **Description**: Extended kernel module development with multiple components
- **Technologies**: Advanced Kernel APIs, USB subsystem integration
- **Features**:
  - Enhanced integer stack module
  - USB gate module implementation
  - Inter-module communication
  - Advanced kernel debugging
- **Key Files**: [`int_stack.c`](Lab05/int_stack.c), [`usb_gate.c`](Lab05/usb_gate.c)

## 🛠️ Technical Skills Demonstrated

### Programming Languages & Technologies

- **C Programming**: Kernel-level and system programming
- **Python**: Automation, binary analysis, and tooling
- **Shell Scripting**: Build automation and system configuration
- **Assembly**: Low-level debugging and reverse engineering

### System Programming Concepts

- **Kernel Module Development**: Character devices, IOCTL interfaces
- **Binary Analysis**: ELF format, dependency resolution
- **Embedded Systems**: Cross-compilation, bootloaders, initramfs
- **Reverse Engineering**: Static and dynamic analysis techniques
- **Device Drivers**: Character device implementation and management

### Tools & Frameworks

- **Development**: GCC cross-compilers, Make build system
- **Debugging**: GDB, GHIDRA, kernel debugging techniques
- **Emulation**: QEMU system emulation
- **Binary Analysis**: LIEF library, objdump, readelf
- **Version Control**: Git repository management

## 📚 Learning Outcomes

Through these labs, the following advanced concepts were mastered:

1. **Low-Level System Programming**: Direct interaction with kernel APIs and hardware abstraction layers
2. **Cross-Platform Development**: Multi-architecture binary analysis and embedded system development
3. **Security Analysis**: Reverse engineering techniques and vulnerability assessment
4. **Embedded Linux**: Complete understanding of Linux boot process and system initialization
5. **Kernel Development**: Module development, device driver implementation, and kernel debugging

## 📖 Documentation

Each lab includes comprehensive documentation:

- **Solution Methodology**: Step-by-step implementation approach
- **Technical Analysis**: In-depth explanation of concepts and challenges
- **Screenshots**: Visual demonstration of working solutions
- **Code Comments**: Detailed inline documentation

## 🎯 Academic Achievement

This repository demonstrates mastery of advanced Linux programming concepts and represents significant practical experience in:

- System-level programming and kernel development
- Embedded systems and cross-platform development
- Security analysis and reverse engineering
- Binary analysis and dependency management
- Professional software development practices

---
