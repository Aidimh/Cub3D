# Cub3D
A Ray-Casting 3D game engine from the 42 Network (1337). Engineered the data parsing and validation engine, managing file ingestion (.cub), configuration extraction (textures, RGB color mapping), mathematical map validation via Flood-Fill, and memory safety to guarantee leak-free asset loading.

# cub3D — Ray-Casting 3D Engine Fundamentals

An advanced graphics and systems programming project from the **1337 / 42 Network** curriculum. This project implements a first-person 3D game environment using the concept of **Ray-Casting**—inspired by the world-famous 90s classic *Wolfenstein 3D*.

While collaborating in a team structure, **my primary responsibility was architecting and implementing the Configuration Parser, Map Validation Engine, and Asset Memory Subsystems.** This engine guarantees that the game only launches if given an structurally secure and properly formatted world file.

---

## ⚙️ My Engineering Focus: Parsing & Map Validation

As the lead developer for the parsing pipeline, I built a bulletproof validation system designed to handle malformed input files and illegal map configurations defensively. Key technical hurdles I solved include:

* **File Ingestion & Tokenization:** Processed `.cub` configuration files line-by-line, utilizing dynamic string analysis to isolate and load environmental parameters while stripping garbage data.
* **Texture & Color Configuration:** Parsed directional wall texture paths (North `NO`, South `SO`, West `WE`, East `EA`) and mapped RGB color spectrum strings for the Floor (`F`) and Ceiling (`C`) into clean, usable hexadecimal values.
* **Map Integrity & Validation:** Built structural tracking loops to verify that the map layout is composed strictly of authorized characters (`0`, `1`, `N`, `S`, `E`, `W`) and contains exactly **one** player starting orientation.
* **Flood-Fill Enclosure Checks:** Developed a specialized **Flood-Fill algorithm** to ensure the map layout is completely closed and surrounded by walls (`1`), catching any boundary holes, missing walls, or out-of-bounds player positions before passing data to the graphics pipeline.
* **Clean Crash Error Handling:** Implemented a unified exit matrix. If the parser detects an anomaly, it immediately triggers a custom error message prefixed with `Error\n`, prevents segmentation faults, and releases all previously allocated memory vectors safely.

---

## 📋 The Parsing & Ingestion Pipeline

The parsing module tokenizes, transforms, and validates the configuration layout using the following sequential architectural flow:

```text
 ┌──────────────┐      ┌─────────────────────────┐      ┌─────────────────────────┐
 │  Input File  │─────►│ Texture & Color Parsing │─────►│ Characters Verification │
 │   (.cub)     │      │ (NO, SO, WE, EA, F, C)  │      │  (Forbidden Elements)   │
 └──────────────┘      └─────────────────────────┘      └────────────┬────────────┘
                                                                     │
                                                                     ▼
 ┌──────────────┐      ┌─────────────────────────┐      ┌─────────────────────────┐
 │ Ready for    │◄─────│   Flood-Fill Test       │◄─────│ Player Validation       │
 │ Ray-Casting  │      │  (Boundary Enclosure)   │      │ (1 Starting Position)   │
 └──────────────┘      └─────────────────────────┘      └─────────────────────────┘
```

---

## 📁 Sample Valid Configuration Schema

The data structures I engineered are capable of perfectly routing clean, well-formed configuration maps such as this:

```text
NO ./path_to_textures/north_wall.xpm
SO ./path_to_textures/south_wall.xpm
WE ./path_to_textures/west_wall.xpm
EA ./path_to_textures/east_wall.xpm

F 220,100,0
C 225,30,0

        1111111111111111
        1000000000110001
        1011000000110001
        1001000000000001
        10010000N0000001
        1111111111111111
```

---

## 🚀 Compilation & Integration

The repository contains an optimized `Makefile` configured to compile all engine files under strict POSIX compliance flags.

### Build Commands:
```bash
# Compile and output the cub3D executable
make

# Clean binary object directories (.o)
make clean

# Full system reset: Clear object files and the final game binary
make fclean

# Perform a fresh, clean rebuild from scratch
make re
```

### Launching a Level:
To load a world file into the engine, feed the parsed file directly into the executable:
```bash
./cub3D maps/valid_fortress.cub
```

---

## 🧹 Memory Sanitization & Leak Safeguards
Because texture files and text maps consume major segments of heap memory, dynamic sanitization is crucial. My parsing algorithm ensures that if any part of the configuration fails (e.g., a missing texture file or an unclosed wall), **every single allocated block of memory is immediately freed** up before the program exits, maintaining a perfect record of **0 memory leaks**.
