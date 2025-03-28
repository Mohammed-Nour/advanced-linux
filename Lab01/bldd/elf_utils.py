import lief


def get_architecture(path):
    try:
        elf = lief.parse(path)
        return str(elf.header.machine_type)
    except Exception:
        return None


def get_needed_libraries(path):
    try:
        elf = lief.parse(path)
        return list(elf.libraries)
    except Exception:
        return []
