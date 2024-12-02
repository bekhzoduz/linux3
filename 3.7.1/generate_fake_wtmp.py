import struct
import time

# Define fake login entries
fake_logins = [
    ("haady", "tty1", "192.168.0.1", int(time.time()) - 300),
    ("John", "tty2", "1.1.1.1", int(time.time()) - 600),
    ("Kaf", "tty3", "2.0.0.5", int(time.time()) - 900),
    ("Nzrv", "tty4", "192.168.17.07", int(time.time()) - 1200),
    ("chuck", "tty5", "10.0.0.1", int(time.time()) - 1500),
]

# Create the fake wtmp file
output_file = "/var/log/wtmp"
with open(output_file, "wb") as f:
    for user, tty, host, timestamp in fake_logins:
        entry = struct.pack(
            "hi32s4s32s256s2i36x",  # Binary format for utmp structure
            7,  # Type of entry (USER_PROCESS)
            0,  # PID (not used)
            tty.encode("utf-8"),
            b"",  # ID (empty)
            user.encode("utf-8"),
            host.encode("utf-8"),
            timestamp,  # Login time
            timestamp,  # Logout time
        )
        f.write(entry)

print(f"Fake wtmp file created at {output_file}")
