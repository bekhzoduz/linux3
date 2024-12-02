import struct
import time

# Define fake login entries
fake_logins = [
    ("haady", "tty1", "192.168.0.1", int(time.mktime(time.strptime("2005-07-25", "%Y-%m-%d")))),
    ("John", "tty2", "1.1.1.1", int(time.mktime(time.strptime("2005-08-27", "%Y-%m-%d")))),
    ("Kaf", "tty3", "2.0.0.5", int(time.mktime(time.strptime("2005-08-21", "%Y-%m-%d")))),
    ("Nzrv", "tty4", "192.168.17.7", int(time.mktime(time.strptime("2005-09-01", "%Y-%m-%d")))),
    ("chuck", "tty5", "10.0.0.1", int(time.time() - 3600)),
]

# Filepath for the fake wtmp file
output_file = "/var/log/wtmp"

# Define struct format
entry_format = "hi32s4s32s256shhii36x"
entry_size = struct.calcsize(entry_format)

# Create the fake wtmp file
with open(output_file, "wb") as f:
    for user, tty, host, timestamp in fake_logins:
        # Ensure all strings are properly encoded and padded
        packed_entry = struct.pack(
            entry_format,
            7,  # Type of entry (USER_PROCESS)
            0,  # PID (not used)
            tty.encode("utf-8").ljust(32, b"\x00"),  # TTY name, padded to 32 bytes
            b"",  # ID (empty, 4 bytes)
            user.encode("utf-8").ljust(32, b"\x00"),  # Username, padded to 32 bytes
            host.encode("utf-8").ljust(256, b"\x00"),  # Hostname, padded to 256 bytes
            0,  # Exit status
            0,  # Reserved
            timestamp,  # Login time
            timestamp,  # Logout time
        )
        f.write(packed_entry)
        print(f"Written record: {user}, {tty}, {host}, {time.ctime(timestamp)}")

# Confirm file creation
print(f"\nFake wtmp file created at {output_file}")

# Verify file contents
print(f"\nSize of each entry: {entry_size} bytes")
print(f"Expected file size: {len(fake_logins) * entry_size} bytes")
