import sys

# Define original and replacement byte sequences
old_bytes = b'\xBA\x21\x00'
new_bytes = b'\xBA\x00\x00'


def patch_binary(filename):
    with open(filename, "rb") as f:
        data = f.read()

    # Find first occurrence
    index = data.find(old_bytes)
    if index == -1:
        print("Pattern BA 21 00 not found!")
        return

    # Replace only the first occurrence
    patched_data = data[:index] + new_bytes + data[index + len(old_bytes):]

    # Save the modified file
    patched_filename = "patched_" + filename
    with open(patched_filename, "wb") as f:
        f.write(patched_data)

    print(f"Patching complete: {patched_filename}")


# Usage: python script.py hack_app
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python patch.py <filename>")
        sys.exit(1)

    patch_binary(sys.argv[1])
