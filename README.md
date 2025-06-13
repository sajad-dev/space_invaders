# Space Invaders

A classic Space Invaders game written in C using X11 for Linux.

## Features

- Classic gameplay with ship movement and shooting
- 3 invader types (L1: 100pts, M1: 200pts, S1: 400pts)
- Progressive difficulty and health system
- Score tracking and explosion effects

## Installation

### Prerequisites
```bash
# Ubuntu/Debian
sudo apt-get install libx11-dev libxft-dev libfreetype6-dev cmake build-essential

# Fedora/RHEL
sudo yum install libX11-devel libXft-devel freetype-devel cmake gcc make
```

### Build & Run
```bash
chmod +x run.sh
./run.sh
```

## Controls

- **Arrow Keys**: Move ship left/right
- **Spacebar**: Shoot
- **R**: Restart (game over screen)
- **Q**: Quit (game over screen)

## Configuration

Update asset paths in `src/media.c` to match your installation directory:
```c
// Change hardcoded paths like:
"/home/sajad/Documents/Programming/space_invaders/Assets/..."
// To your actual path
```

## Project Structure

```
├── src/          # Source code
├── Assets/       # Game sprites
├── run.sh        # Build script
└── CMakeLists.txt
```

## License

MIT License