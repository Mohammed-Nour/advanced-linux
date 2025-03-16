import hashlib


def hash_hardware_id(hardware_id):
    hashed_id = hashlib.md5(hardware_id.encode()).digest()[::-1].hex()
    print("Your hashed id is: ", hashed_id)
    return hashed_id


if __name__ == "__main__":
    hardware_id = input("Enter your HWID: ")
    if len(hardware_id) < 16:
        print("Invalid HWID. Please enter a valid HWID.")
    else:
        print("Your HWID is valid.")
        hash_hardware_id(hardware_id)
