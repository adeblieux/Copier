# File Copier

File Copier is a simple command-line tool written in C that copies the contents of one file to another. It provides a basic file copying functionality with a progress bar to indicate the copying progress.

## Usage

To use the File Copier, follow these steps:

1. Compile the source code:
   ```bash
   $ gcc -o copier copier.c
   
### Usage Format:
Run the executable with the source file and destination file as arguments:
```
> $ Copier <SourceFile> <DestinationFile>
```
## Features
- Copies the contents of a source file to a destination file.
- Displays a progress bar indicating the copying progress.
- Gracefully handles errors such as incorrect usage, inability to read the source file, and inability to write to the destination file.

## Requirements
- C compiler (e.g., GCC)
- Standard C libraries: stdio.h, stdlib.h, unistd.h

## Limitations
- Only supports copying files up to the buffer size defined (BUFFER_SIZE = 4096).
- Progress bar may not be displayed accurately for very large files due to limitations in file size calculations.

## License
This project is licensed under the Apache License. See the LICENSE file for details.

## Acknowledgements
The progress bar implementation in this code is inspired by examples found online, but modified for the specific use case of this project.

## Author
[@adeblieux](https://github.com/adeblieux)
