import struct
import time

# Define fake login entries
fake_logins = [
    ("haady", "tty1", "192.168.0.1", int(time.mktime(time.strptime("2005-07-08", "%Y-%m-%d")))),
    ("John", "tty2", "1.1.1.1", int(time.mktime(time.strptime("2005-08-27", "%Y-%m-%d")))),
    ("Kaf", "tty3", "2.0.0.5", int(time.mktime(time.strptime("2005-08-21", "%Y-%m-%d")))),
    ("Nzrv", "tty4", "192.168.17.7", int(time.mktime(time.strptime("2005-07-17", "%Y-%m-%d")))),
    ("chuck", "tty1", "10.0.0.2", int(time.time() - 3600)),
    ("root", "pts/0", "10.0.0.1", int(time.time())),
]

# Path for the fake wtmp file
output_file = "/var/log/wtmp"

# Define struct format for wtmp entries
# Reference: Linux man page for utmp structure
entry_format = "hi32s4s32s256shhiii36x"
entry_size = struct.calcsize(entry_format)

# Create the fake wtmp file
with open(output_file, "wb") as f:
    for user, tty, host, timestamp in fake_logins:
        # Pack the data into the expected format
        packed_entry = struct.pack(
            entry_format,
            7,  # Type of entry (USER_PROCESS)
            0,  # PID (not used, set to 0)
            tty.encode("utf-8").ljust(32, b"\x00"),  # TTY name
            b"1",  # ID (default to "1", 4 bytes)
            user.encode("utf-8").ljust(32, b"\x00"),  # Username
            host.encode("utf-8").ljust(256, b"\x00"),  # Hostname
            0,  # Exit status
            0,  # Reserved
            timestamp,  # Login time (seconds since epoch)
            timestamp,  # Use same timestamp for logout time
            0,  # Session ID (set to 0)
        )
        f.write(packed_entry)
        print(f"Written record: {user}, {tty}, {host}, {time.ctime(timestamp)}")

print(f"\nFake wtmp file created at {output_file}")
print(f"Entry size: {entry_size} bytes, Total entries: {len(fake_logins)}")
